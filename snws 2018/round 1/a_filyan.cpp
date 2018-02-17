#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cstring>
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
typedef vector<int> vi;
typedef long double ld;
///////////////////////////

int const N = 22;
int const INF = 1e9 + 41;

vi a[N][N];
int l[N][N];
int q[N][N];
int p[N];
int d[(1 << N)];
int ans, n;

void remin(int &a, int b){
	a = min(a, b);
}

bool bit(int m, int i){
	return (m & (1 << i));
}

vector<int> v0[N], v1[N], v2[N];

void solve(){
	fi(0, n){
		fj(0, p[i]){
			int co = l[i][j];
			int m = 0;
			fo(0, q[i][j]){
				m |= (1 << a[i][j][o]);
			}
			int nm = (m | (1 << i));
			v0[i].pb(m);
			v1[i].pb(nm);
			v2[i].pb(co);
		}
	}
	fi(0, (1<<n)) d[i] = INF;
	d[0] = 0;
	fi(0, (1<<n)){
		if(d[i] == INF) continue;
		fj(0, n){
			fo(0, sz(v0[j])){
				int m = v0[j][o];
				if((m & i) != m) continue;
				int nm = (v1[j][o] | i);
				int nc = d[i] + v2[j][o];
				remin(d[nm], nc);
			}
		}
	}
	ans = INF;
	fi(0, (1<<n)){
		if(bit(i, 0)) remin(ans, d[i]);
	}
	if(ans == INF) ans = -1;
}

int main(){
//#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
//#endif

	scanf("%d",&n);
	fi(0, n){
		scanf("%d",&p[i]);
		fj(0, p[i]){
			scanf("%d",&l[i][j]);
			scanf("%d",&q[i][j]);
			fo(0, q[i][j]){
				int x;
				scanf("%d",&x);
				a[i][j].pb(x);
			}
		}
	}

	solve();

	printf("%d\n",ans);

	return 0;
}