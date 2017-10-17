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

void solve(){
	
}

#define FILENAME "xorsep"

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);
#endif

	//solve();
	ll n, answer = 1;
	scanf("%lld", &n);
	vector<ll> a(n);
	ll t = 0;
	fi(0, n){
		scanf("%lld", &a[i]);
		t ^= a[i];
		answer *= 2;
	}
	if(t || n == 1){
		printf("0");
		return 0;
	}
	printf("%lld", answer - 2);
	return 0;
}