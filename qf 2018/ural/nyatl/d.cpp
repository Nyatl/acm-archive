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
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(auto i=a; i<=b; i++)
#define fj(a, b) for(auto j=a; j<=b; j++)
#define fo(a, b) for(auto o=a; o<=b; o++)
#define fy(a) for(auto &y : a)
#define fz(a) for(auto &z : a)
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
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
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

#define ID "d"

#define MAX 3010
#define base 37

#ifdef LOCAL
#define MOD 1000000009
ll mult(ll a, ll b) {
	return (a * b) % MOD;
}
#else
#define MOD (1000000007 * 1000000009LL)
ll mult(ll a, ll b) {
	return (ll)(((__int128)a * b) % MOD);
}
#endif

ll add(ll a, ll b) {
	return (a + b) % MOD;
}

ll sub(ll a, ll b) {
	return ((a - b) % MOD + MOD) % MOD;
}

int n, k;
ll pw[MAX];
ll hsh[MAX];

ll get_hash(int l, int r) {
	return sub(hsh[r], mult(hsh[l - 1], pw[r - l + 1]));
}

map<pii, set<ll>> t;

void solve() {
	fi(1, n) {
		fj(i, min(k, 2 * n - 1)) {
			if (i == 1 && j >= n) continue;
			t[mp(0, 0)].insert(get_hash(i, j));
		}
	}
	fi(2, n + 1) {
		fj(2 * n, 3 * n - 1) {
			int pref = (i == n + 1 ? 0 : n);
			int suff = (j - 2 * n);
			int q = (k - pref - suff) / n;
			if (q <= 0) continue;
			t[mp(1, q)].insert(get_hash(i, j));
		}
	}
	ll ans = 0;
	fz(t) {
		ans += (z.first.second - z.first.first + 1) * (ll)sz(z.second);
	}
	printf("%lld\n", ans);
}

char s[MAX];

void init() {
	pw[0] = 1;
	fi(1, 3 * n) {
		pw[i] = mult(pw[i - 1], base);
	}
	fi(1, 3 * n) {
		hsh[i] = add(mult(hsh[i - 1], base), s[i] - 'a' + 1);
	}
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%s", s + 1);
	scanf("%d", &k);
	n = (int)strlen(s + 1);

	fi(1, n - 1) {
		if (n % i != 0) continue;
		int f = 1;
		fj(i + 1, n) {
			if (s[j] != s[(j - 1) % i + 1]) {
				f = 0;
				break;
			}
		}
		if (f) {
			n = i;
			break;
		}
	}

	fi(n + 1, 3 * n) {
		s[i] = s[(i - 1) % n + 1];
	}

	init();

	solve();

	exit();
	return 0;
}