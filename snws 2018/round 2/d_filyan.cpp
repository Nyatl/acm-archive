#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<cassert>
#include<deque>
#include<numeric>
#include<functional>
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
///////////////////////

int const N = 1e5 + 41;

int n;
vector<int> e[N];
int w[N];
int ans;
int a[N];
int p[N];

void bad(){
	printf("-1\n");
	exit(0);
}

void dfs(int x){
	w[x] = 1;
	for(int y : e[x]){
		if(w[y] == 1) bad();
		if(w[y] == 2) continue;
		dfs(y);
	}
	w[x] = 2;
}

pii d[N];

void dfs1(int x){
	w[x] = 1;
	if(sz(e[x]) == 0){
		d[x] = mp(1, p[x]);
		return;
	}
	for(int y : e[x]){
		if(!w[y]) dfs1(y);
		pii c = d[y];
		if(p[y] > p[x]){
			c.first += 1;
		}
		c.second = p[x];
		d[x] = max(d[x], c);
	}
}

void solve(){
	fi(0, n) p[a[i]] = i;
	fi(0, n){
		if(w[i]) continue;
		dfs(i);
	}
	memset(w, 0, sizeof(w));
	fi(0, n){
		if(!w[i]) dfs1(i);
	}
	fi(0, n) ans = max(ans, d[i].first);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&n);
	fi(0, n){
		scanf("%d",&a[i]);
		--a[i];
	}
	fi(0, n){
		int k;
		scanf("%d",&k);
		fj(0, k){
			int x;
			scanf("%d",&x);
			--x;
			e[i].pb(x);
		}
	}

	solve();

	printf("%d\n",ans);

	return 0;
}