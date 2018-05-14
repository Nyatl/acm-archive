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
#include <cstdarg>
#include <memory.h>
#include <assert.h>
#include <cmath>

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
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<int> si;
typedef set<pii> spii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef set<ll> sl;
typedef set<pll> spll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

#ifdef LOCAL
#define PRINT
#endif

// #undef PRINT

void err(const char *format, ... ) {
#ifdef PRINT
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
#ifdef PRINT
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
#ifdef PRINT	
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

#ifdef PRINT
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

const int MAX = 1000 * 1000 + 41;

ll vol[MAX];

ll sqr(ll x) {
	return x * x;
}

ll brutecalc(int x) {
	if (vol[x] != -1) return vol[x];
	
	ll res = 0;
	int b = -1;
	fi(1, (x - 1) / 2) {
		ll tmp = sqr(x - 2 * i) * i;
		tmp += 4 * brutecalc(i);
		if (tmp > res) {
			b = i;
			res = tmp;
		}
	}
	err("%d %d\n", x, b);
	
	return vol[x] = res;
}

void bruteprep() {
	fi(0, MAX - 1) vol[i] = -1;
	//fi(0, MAX - 1) dfs0(i);
	fi(0, 1000) brutecalc(i);
	dbg0(vol, 1000);
	
	
}

ll sq[MAX];

ll getV(ll a, ll x) {
	ll res = 0;
	if (a - 2 * x <= 0) {
		return 0;
	}
	res += 4 * sq[x];
	res += x * sqr(a - 2 * x);
	return res;
}

ll getV(ll a, ll b, ll x) {
	if (a - 2 * x <= 0) return 0;
	if (b - 2 * x <= 0) return 0;
	ll res = 0;
	res += 4 * sq[x];
	res += x * (a - 2 * x) * (b - 2 * x);
	return res;
}

void solve() {
	int a, b;
	scanf("%d %d", &a, &b);
	ll ans = 0;
	ll r = (min(a, b) - 1) / 2 + 1;
	ll l = 0;
	while (r - l > 4) {
		ll h1 = l + (r - l) / 3;
		ll h2 = r - (r - l) / 3;
		if (getV(a, b, h1) > getV(a, b, h2)) {
			r = h2;
		} else {
			l = h1;
		}
	}
	fj(l, r) {
		ans = max(ans, getV(a, b, j));
	}
	printf("%lld\n", ans);
}

void prepare() {
	sq[0] = sq[1] = sq[2] = 0;
	fi(3, MAX - 1) {
		ll l = 0;
		ll r = (i - 1) / 2 + 1;
		while (r - l > 4) {
			ll h1 = l + (r - l) / 3;
			ll h2 = r - (r - l) / 3;
			if (getV(i, h1) > getV(i, h2)) {
				r = h2;
			} else {
				l = h1;
			}
		}
		ll b = 0;
		fj(l, r) {
			b = max(b, getV(i, j));
		}
		sq[i] = b;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	prepare();
	int nT;
	scanf("%d", &nT);
	fi(1, nT) {
		solve();
	}
	//prep();
	exit();
	return 0;
}
