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

#define ID "f"

#define MAX 500100

int n;
int a[MAX];
int b[MAX];
int c[MAX];

int order(int x, int y, int a[MAX]) {
	int p1, p2;
	fi(1, n) {
		if (a[i] == x) p1 = i;
		if (a[i] == y) p2 = i;
	}
	return p1 < p2;
}

int num[MAX];

int f[MAX];

void upd(int p) {
	int l = 1;
	int r = n;
	while (l <= r) {
		int h = (l + r) / 2;
		if (p <= h) {
			f[h]++;
			r = h - 1;
		} else {
			l = h + 1;
		}		
	}
}

int sum(int p) {
	int res = 0;
	int l = 1;
	int r = n;
	while (l <= r) {
		int h = (l + r) / 2;
		if (p < h) {
			r = h - 1;
		} else {
			res += f[h];
			l = h + 1;
		}		
	}
	return res;
}

int sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int pos[MAX];

ll solve(int a[MAX], int b[MAX]) {	
	ll res = 0;
	errln();
	clr(f);
	clr(pos);
	fi(1, n) {
		pos[b[i]] = i;
	}	
	fi(1, n) {
		res += sum(1, pos[a[i]]);
		upd(pos[a[i]]);
	}
	res = ((ll)n * (n - 1) / 2) - res;
	dbg1(a, n);
	dbg1(b, n);
	dbg(res);
	return res;
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
	fi(1, n) {
		scanf("%d", &b[i]);
	}
	fi(1, n) {
		scanf("%d", &c[i]);
	}

	fi(1, n) {
		num[a[i]] = i;
	}

	fi(1, n) {
		a[i] = num[a[i]];
		b[i] = num[b[i]];
		c[i] = num[c[i]];
	}

	dbg1(a, n);
	dbg1(b, n);
	dbg1(c, n);

	ll ans = (solve(a, b) + solve(b, c) + solve(a, c));
	dbg(ans);

	ans = ((ll)n * (n - 1)) / 2 - ans / 2;

	printf("%lld\n", ans);

	exit();
	return 0;
}