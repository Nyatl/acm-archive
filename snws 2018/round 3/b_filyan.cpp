#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<cassert>

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
int const N = 1e6 + 41;
#endif

int n, a[N], m, b[N];
int ans;
int d[N][4];
int f[N], s[N];

void remax(int &a, int b){
	a = max(a, b);
}

void solve(){
	fi(0, n) f[a[i]] = 1;
	fj(0, m) s[b[j]] = 1;
	fi(0, N-2) fj(0, 4){
		remax(d[i+1][j], d[i][j]);
		if(f[i] && s[i]){
			remax(d[i+1][3], d[i][j] + 1);
		}else{
			if(f[i]){
				if(!(j & 2)) continue;
				remax(d[i+1][1], d[i][j]+1);
			}else if(s[i]){
				if(!(j & 1)) continue;
				remax(d[i+1][2], d[i][j]+1);
			}
		}
	}
	fi(0, N) fj(0, 4) remax(ans, d[i][j]);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	scanf("%d",&n);
	fi(0, n) scanf("%d",&a[i]);
	scanf("%d",&m);
	fi(0, m) scanf("%d",&b[i]);

	solve();	

	printf("%d\n",ans);

	return 0;
}