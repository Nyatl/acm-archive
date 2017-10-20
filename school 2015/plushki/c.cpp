#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define fj(a,b) for(int j=a;j<b;++j)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
////////////////////

#define filename "demo"

#ifdef _DEBUG
int const N = 41;
#else
int const N = 1e5 + 41;
#endif
int const INF = 1e9 + 41;
pii const EMP = mp(-INF, -INF);

int n, L, R;
vector<pii> answer;
int a[N], suf[N];
int b[N], g[N];

vpi F[N * 4];
vi t[N * 4];
vector<pii> pt[N];

pii ans[N];

void merge(vi &v, vi &l, vi &r){
	int lp = 0, rp = 0, ln = sz(l), rn = sz(r);
	while(lp < ln || rp < rn){
		if(rp == rn || (lp < ln && suf[l[lp]] > suf[r[rp]])){
			v.pb(l[lp]);
			++lp;
		}else{
			v.pb(r[rp]);
			++rp;
		}
	}
}

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v].pb(tl);
	}else{
		int tm = (tl+tr)/2;
		build(v*2+1, tl, tm);
		build(v*2+2, tm+1, tr);
		merge(t[v], t[v*2+1], t[v*2+2]);
	}
	fi(0, sz(t[v])){
		pt[t[v][i]].pb(mp(v, i));
	}
	F[v].assign(sz(t[v]), EMP);
}

pii getmax(vpi &F, int x){
	pii ret = EMP;
	while(x >= 0){
		ret = max(ret, F[x]);
		x = (x&(x+1)) - 1;
	}
	return ret;
}

void upd(vpi &F, pii v, int x){
	while(x < sz(F)){
		F[x] = max(F[x], v);
		x |= (x + 1);
	}
}

void push(int id){
	fi(0, sz(pt[id])){
		int node = pt[id][i].first;
		int pos = pt[id][i].second;
		pii val = mp(ans[id].first, id);
		upd(F[node], val, pos);
	}
}

int getpos(vi &v, int s){
	int l = -1;
	int r = sz(v);
	while(r-l>1){
		int m = (l+r)/2;
		if(suf[v[m]] >= s) l = m;
		else r = m;
	}
	return l;
}

pii query(int v, int tl, int tr, int l, int r, int s){
	if(l > tr || tl > r) return EMP;
	if(l <= tl && tr <= r){
		pii ret = EMP;
		int pos = getpos(t[v], s);
		ret = getmax(F[v], pos);
		return ret;
	}
	int tm = (tl+tr)/2;
	pii rr = query(v*2+1, tl, tm, l, r, s);
	pii rl = query(v*2+2, tm+1, tr, l, r, s);
	return max(rr, rl);
}

pii query(int l, int r, int s){
	return query(0, 0, n, l, r, s);
}

void solve(){
	fi(1, n+1) a[i] = b[i] - g[i];
	fdi(n+1, 0){
		suf[i] = a[i+1] + suf[i+1];
	}
	build(0, 0, n);

	fi(1, n+1) ans[i] = EMP;
	push(0);

	fi(1, n+1){
		int rp = i - L;
		int lp = max(0, i - R);
		int sum = suf[i];
		if(lp >= 0){
			pii vless = query(lp, rp, -INF);
			--vless.first;
			pii veq = query(lp, rp, sum);
			pii vgr = query(lp, rp, sum + 1);
			++vgr.first;
			ans[i] = max(ans[i], vless);
			ans[i] = max(ans[i], veq);
			ans[i] = max(ans[i], vgr);
		}
		push(i);
	}

	int x = n;
	while(x > 0){
		int nxt = ans[x].second;
		answer.pb(mp(nxt+1, x));
		x = nxt;
	}
	reverse(answer.begin(), answer.end());
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(filename ".in", "r", stdin);
	freopen(filename ".out", "w", stdout);
#endif
	scanf("%d %d %d",&n,&L,&R);
	fi(1, n+1) scanf("%d %d",&b[i],&g[i]);

	solve();

	printf("%d\n",sz(answer));
	fi(0, sz(answer)){
		printf("%d %d\n",answer[i].first,answer[i].second);
	}

	return 0;
}