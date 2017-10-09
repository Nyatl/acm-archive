#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cassert>

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

ll getC(ll a, ll n) {
	return ((a + n - 1) / n) * n;
}

void solve(){
	ll a, n;
	scanf("%lld%lld", &a, &n);
	ll b, c;
	ll d = 1;
	ll a1 = a;
	c = getC(a, n);
	b = (a^c);
	fi(0, 62) {
		if (a1&d) {
			a1 ^= d;
			c = getC(a1, n);
			b = min(b, (a^c));
		}
		d *= 2;
	}
	printf("%lld\n", b);
}


int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int nT;
	scanf("%d", &nT);
	while(nT--) {
		solve();
	}
	return 0;
}