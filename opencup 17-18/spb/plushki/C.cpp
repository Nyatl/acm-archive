#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

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
///////////////////

int const N = 14;

int n;
int a[N], b[N];
int d[N][(1<<N)];

bool bit(int mask, int id){
	return ( (1 << n) & mask);
}

void solve(){
	d[0][0] = 1;
	fi(0, n){
		for(int mask=0;mask<(1<<n);++mask){
			fj(0, n){
				if(!bit(mask, j) && a[i] <= b[j]){
					int nmask = (mask ^ (1 << j));
					d[i+1][nmask] += d[i][mask];
				}
			}
		}
	}
	printf("%d\n",d[n][(1<<n)-1]);
}

#define FILENAME "chickens"

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);
#endif
	scanf("%d",&n);
	fi(0, n) scanf("%d",&a[i]);
	fi(0, n) scanf("%d",&b[i]);
	solve();


	return 0;
}