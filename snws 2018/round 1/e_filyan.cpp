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

int const MOD = 1e9 + 7;
int const N = 1e5 + 41;

int n;
ll a[N];
int ans;

int mul(int a, int b){
	return (ll) a * b % MOD;
}

void add(int &a, ll b){
	b %= MOD;
	if(b < 0) b += MOD;
	a += b;
	if(a >= MOD) a -= MOD;
}

void bad(){
	printf("-1\n");
	exit(0);
}

void solve(){
	ll s = 1;
	fi(0, n){
		s *= 2;
		s -= a[i];
		if(s >= (1LL << 61)){
			break;
		}
		if(s < 0) bad();
	}
	
	ans = 1;
	fi(0, n){
		ans = mul(ans, 2);
		add(ans, -a[i]);
	}
}

int main(){
//#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
//#endif

	scanf("%d",&n);
	fi(0, n) scanf("%lld",&a[i]);

	solve();

	printf("%d\n",ans);

	return 0;
}