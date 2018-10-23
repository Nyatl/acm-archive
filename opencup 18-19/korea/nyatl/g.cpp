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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(auto i=a; i<=b; i++)
#define fj(a, b) for(auto j=a; j<=b; j++)
#define fo(a, b) for(auto o=a; o<=b; o++)
#define fdi(a, b) for(auto i=a; i>=b; i--)
#define fdj(a, b) for(auto j=a; j>=b; j--)
#define fdo(a, b) for(auto o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

void err(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s\n", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln() {
#ifdef LOCAL	
	fprintf(stderr, "\n");
#endif	
}

double START_TIME;

void exit() {
#ifdef LOCAL	
	cerr << "TIME: " << setprecision(5) << fixed << (clock() - START_TIME) / CLOCKS_PER_SEC << endl;
#endif	
	exit(0);
}

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

#define ID "g"

#define MAX 250100
#define INF 1000000000000000000LL

int n, k;
ll a[MAX];

ll d[MAX][3][10][10];

ll fun(int x, int last, int put, int taken) {
	if (x > n) {		
		if (put != taken) return INF;
		if (last == 2) return INF;
		return 0;
	}
	if (d[x][last][put][taken] != -1) return d[x][last][put][taken];
	ll res = INF;

	res = min(res, fun(x + 1, 0, put, taken) + a[x]);
	if (put < k) res = min(res, fun(x + 1, 0, put + 1, taken));

	if (last != 2) {
		res = min(res, fun(x + 1, last + 1, put, taken));
		if (taken < k) res = min(res, fun(x + 1, last + 1, put, taken + 1) + a[x]);
	}

	return d[x][last][put][taken] = res;
}

ll solve() {
	for (int last = 0; last <= 2; last++) {
		for (int put = 0; put <= k; put++) {
			for (int taken = 0; taken <= k; taken++) {
				if (last == 2) d[n + 1][last][put][taken] = INF;
				else if (put != taken) d[n + 1][last][put][taken] = INF;
				else d[n + 1][last][put][taken] = 0;
			}
		}
	}
	for (int x = n; x >= 1; x--) {
		for (int last = 0; last <= 2; last++) {
			for (int put = 0; put <= k; put++) {
				for (int taken = 0; taken <= k; taken++) {
					ll &res = d[x][last][put][taken];
					res = INF;
					res = min(res, d[x + 1][0][put][taken] + a[x]);
					if (put < k) res = min(res, d[x + 1][0][put + 1][taken]);
					if (last != 2) {
						res = min(res, d[x + 1][last + 1][put][taken]);
						if (taken < k) res = min(res, d[x + 1][last + 1][put][taken + 1] + a[x]);
					}
				}
			}
		}
	}
	return d[1][1][0][0];
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d", &n, &k);
	fi(1, n) {
		scanf("%lld", &a[i]);
	}

	// memset(d, -1, sizeof(d));

	ll ans = solve();

	printf("%lld\n", ans);

	exit();
	return 0;
}