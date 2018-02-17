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

int const N = 63;

ll n;
int k;
ll ans, x;

bool bit(ll m, int i){
	return (m & (1LL << i));
}

int bitq(ll m){
	int res = 0;
	while(m){
		res += (m & 1);
		m >>= 1;
	}
	return res;
}

void solve(){
	if(k == 1){
		fi(0, N){
			if( (1LL << i) > n){
				ans = (1LL << i);
				return;
			}
		}
	}
	fi(0, k) x += (1LL << i);
	if(x > n){
		ans = x;
		return;
	}
	if(x == n){
		ans = ((x + 1) | (x >> 1));
		return;
	}
	vector<int> a;
	fi(0, N){
		if(bit(n, i)) a.pb(1);
		else a.pb(0);
	}
	while(a.back() == 0) a.pop_back();
	fi(0, sz(a)){
		if(a[i] == 1) continue;
		int s = 0;
		fj(i+1, sz(a)) s += a[j];
		if(s + 1 > k) continue;
		if(s + i + 1 < k) continue;
		int r = k - s - 1;
		a[i] = 1;
		fj(0, i){
			a[j] = 0;
			if(r){
				--r;
				a[j] = 1;
			}
		}
		break;
	}
	fi(0, sz(a)){
		if(a[i]) ans += (1LL << i);
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> n >> k;

	solve();

	cout << ans << endl;

	return 0;
}