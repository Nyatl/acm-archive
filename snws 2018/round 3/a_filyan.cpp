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

int const M = 4e6 + 41;

int n, a[N];
int l[N], r[N];
ll k[N];
int m;
ll ans[N];

vector<int> e[M];

namespace F{
	ll f[N];

	void add(int x, int v){
		while(x < n){
			f[x] += v;
			x |= (x + 1);
		}
	}

	ll get(int x){
		ll res = 0;
		while(x >= 0){
			res += f[x];
			x = (x&(x+1))-1;
		}
		return res;
	}

	ll get(int l, int r){
		ll res = get(r);
		if(l) res -= get(l-1);
		return res;
	}

	void build(){
		memset(f, 0, sizeof(f));
		fi(0, n) add(i, a[i]);
	}
};

priority_queue<pii> t;

void solve(){
	F::build();
	fi(0, n) t.push(mp(a[i], -i));
	fi(0, m){
		k[i] = min(k[i], (ll) (M-1));
	}
	fi(0, m) e[k[i]].pb(i);
	fi(0, M){
		//cerr << i << endl;
		for(int q : e[i]){
			ans[q] = F::get(l[q], r[q]);
		}
		if(sz(t)){
			pii p = t.top();
			t.pop();
			F::add(-p.second, -p.first);
			p.first /= 2;
			if(p.first > 0){
				F::add(-p.second, p.first);
				t.push(p);
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	scanf("%d",&n);
	fi(0, n) scanf("%d",&a[i]);
	scanf("%d",&m);
	fi(0, m){
		scanf("%d %d %lld",&l[i],&r[i],&k[i]);
		--l[i];--r[i];
	}

	solve();	

	fi(0, m) printf("%lld\n",ans[i]);

	return 0;
}