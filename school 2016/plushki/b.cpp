#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cassert>
#include<map>
#include<set>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define fdj(a,b) for(int j=a-1;j>=b;--j)
#define fdo(a,b) for(int o=a-1;o>=b;--o)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
//////////////////////

int const N = 4e5 + 41;
pii const EMP = mp(-1, -1);

int n, m, k;
int a[N], b[N];

map<int, int> hv;
vector<int> rv;

ll ans;
int ansp;
vector<int> c;

set<int> t[2];

vector<int> go[N], ogo[N];
pii pl[N];

void hashall(){
	c.pb(1);
	c.pb(n);
	fi(0, k) c.pb(a[i]), c.pb(b[i] );
	sort(c.begin(), c.end());
	fi(0, sz(c)){
		if(!i || c[i] != c[i-1]){
			int v = sz(hv);
			hv[c[i]] = v;
			rv.pb(c[i]);
		}
	}

	fi(0, k) a[i] = hv[a[i]], b[i] = hv[b[i]];
}

void pushevents(){
	fi(0, k){
		go[a[i]].pb(i);
		ogo[b[i]].pb(i);
	}
}

int tin[N], tout[N];
int g[N];

void calc(){
	fi(0, 2) t[i].clear();
	fi(0, 2){
		fj(0, m){
			t[i].insert(j);
		}
	}

	t[0].erase(0);

	fi(0, sz(rv)){
		fj(0, sz(ogo[i])){
			int cid = ogo[i][j];
			pii curp = pl[cid];
			if(curp == EMP) continue;
			int ty = curp.first;
			int pos = curp.second;
			t[ty].insert(pos);
			if(ty == 1) g[pos] += (rv[i] - tin[cid]);
		}
		fj(0, sz(go[i])){
			int cid = go[i][j];
			if(sz(t[0]) > 0){
				int ty = 0;
				set<int> :: iterator it = t[0].begin();
				int pos = (*it);
				t[0].erase(pos);
				pl[cid] = mp(ty, pos);
				tin[cid] = rv[i];
			}else{
				if(sz(t[1]) > 0){
					int ty = 1;
					set<int> :: iterator it = t[1].begin();
					int pos = (*it);
					t[1].erase(pos);
					pl[cid] = mp(ty, pos);	
					tin[cid] = rv[i];
				}else{
					pl[cid] = EMP;
				}
			}
		}
	}
}

int const INF = 1e9 + 41;

void solve(){
	hashall();
	pushevents();
	calc();
	ans = INF;
	fi(0, m){
		if(ans > g[i]){
			ans = g[i];
			ansp = i;
		}
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d %d %d",&n,&m,&k);
	fi(0, k) scanf("%d %d",&a[i],&b[i]);

	solve();

	printf("%lld %d\n",ans,ansp + 1);

	return 0;
}