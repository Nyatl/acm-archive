#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<cassert>
#include<queue>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define fdj(a,b) for(int j=a-1;j>=b;--j)
#define fdo(a,b) for(int o=a-1;o>=b;--o)
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef vector<int> vi;

////////////////////////

#ifdef _DEBUG
int const N = 141;
#else
int const N = 1e5 + 41;
#endif

int n, k, m;
int b[N], cb[N];
int ans;

vector<int> e[N], et[N];

int q;
int order[N];
int w[N];
int col[N];
int color;

int qb[N], qg[N];
vector<int> ec[N];
int dg[N], db[N];

void dfs0(int x){
	w[x] = 1;
	for(int y : e[x]){
		if(!w[y]) dfs0(y);
	}
	order[q++] = x;
}

void dfs1(int x){
	w[x] = 1;
	for(int y : et[x]){
		if(!w[y]) dfs1(y);
	}
	col[x] = color;
}

void findcomps(){
	memset(w, 0, sizeof(w));
	fi(0, n){
		if(!w[i]) dfs0(i);
	}
	memset(w, 0, sizeof(w));
	fdi(n, 0){
		int x = order[i];
		if(!w[x]){
			dfs1(x);
			++color;
		}
	}
#ifdef _DEBUG
	//fi(0, n) printf("ver = %d col = %d\n",i,col[i]);
#endif
}

void buildg(){
	set<pii> t;
	fi(0, n){
		for(int y : e[i]){
			int x0 = col[i];
			int y0 = col[y];
			if(x0 == y0) continue;
			if(t.find(mp(x0, y0)) != t.end()) continue;
			ec[x0].pb(y0);
			t.insert(mp(x0, y0));
			t.insert(mp(y0, x0));
		}
	}
}

void dfs2(int x){
	db[x] = qb[x];
	dg[x] = qg[x];
	w[x] = 1;
	for(int y : ec[x]){
		if(!w[y]) dfs2(y);
		db[x] += db[y];
		dg[x] += dg[y];
	}
}

void dfs3(int x){
	w[x] = 1;
	for(int y : ec[x]){
		if(!w[y]) dfs3(y);
	}
}


void calcdp(){
	fi(0, n){
		int x = col[i];
		qb[x] += b[i];
		qg[x] += (1 - b[i]);
	}
	memset(w, 0, sizeof(w));
	fi(0, color){
		if(!w[i]) dfs2(i);
	}
	memset(w, 0, sizeof(w));
	fi(0, color){
		if(w[i]) continue;
		if(db[i] > 0){
			ans += qg[i];
			w[i] = 1;
		}else{
			if(dg[i] > 0){
				++ans;
			}
			dfs3(i);
		}
	}
}

void solve(){
	findcomps();
	buildg();
	calcdp();
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d %d %d",&n,&k,&m);
	fi(0, m){
		int x, y;
		scanf("%d %d",&x,&y);
		e[x].pb(y);
		et[y].pb(x);
	}
	fi(0, k){
		int x;
		scanf("%d",&x);
		b[x] = 1;
	}
	
	solve();	

	printf("%d\n",ans);

	return 0;
}