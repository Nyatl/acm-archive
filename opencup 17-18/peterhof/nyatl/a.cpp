#define _CRT_SECURE_NO_DEPRECATE
 
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <assert.h>
 
using namespace std;
 
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define all(x) (x).being(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
 
template<typename A, typename B>
ostream& operator<<(ostream& s, pair<A, B> p) {
    cerr << "(" << p.first << ", " << p.second << ")";
    return s;
}
 
template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
    fi(0, sz(v) - 1) {
        cerr << v[i] << " ";
    }
    return s;
}

#ifdef _DEBUG
#define LOCAL
#endif
 
#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl;
#define dbg0(x,n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x,n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define ass(x) cerr << __LINE__ << " assertion failed: " << #x << endl, assert(0);
#else
#define dbg(x) while(0){}
#define dbg0(x,n) while(0){}
#define dbg1(x,n) while(0){}
#define ass(x) assert(x)
#endif

ll n;

ll ans = 100000000000LL;

ll per(ll x) {
	return 6 * x - 6;
}

ll area(ll x) {
	return 1 + 3 * x * (x - 1) - per(x);
}

void relax(ll p, ll s) {
	if (s >= n) {
		ans = min(ans, p);
	}
}

void solve() {
	ll l = 2;
	ll r = 1000000000;
	while (l < r) {
		ll h = (l + r) / 2;
		if (area(h) < n) {
			l = h + 1;
		} else {
			r = h;
		}
	}
	ll x = l;
	ll p = per(x);
	ll s = area(x);
	relax(p, s);
	relax(p - 1, s - (x - 1));
	relax(p - 2, s - (x - 1) - (x - 2));
	relax(p - 3, s - (x - 1) - 2 * (x - 2));
	relax(p - 4, s - (x - 1) - 3 * (x - 2));
	relax(p - 5, s - (x - 1) - 4 * (x - 2));
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	scanf("%lld", &n);
	solve();
    return 0;
}