#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
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
ostream& operator<<(ostream& s, pair<A, B> p) {
	s << "(" << p.first << ", " << p.second << ")";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	fi(0, sz(v) - 1) {
		s << v[i] << " ";
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, set<T> t) {
	for (auto z : t) {
		s << z << " ";
	}
	return s;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& s, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		s << "\t" << z.first << " -> " << z.second << endl;
	}
	return s;
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

const int MAX = 100000 + 5;

ll sqr(ll x) {
	return x * x;
}

ll X;

struct Point {
	ll x, y;
	ll d;
	double a;
	Point() {}
	Point(ll x, ll y) : x(x), y(y) {}
	bool operator<(const Point & p) const {
		if (a != p.a) {
			return a < p.a;
		}
		if (x == X && p.x == X) {
			return d > p.d;
		}
		return d < p.d;
	}
	Point operator-(const Point & p) const {
		return Point(x - p.x, y - p.y);
	}
};

ll r(const Point & p1, const Point & p2) {
	return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}

ll cross(const Point p1, const Point p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

ll cross(const Point & p1, const Point & p2, const Point & p3) {
	return cross(p2 - p1, p3 - p1);
}

ll dot(const Point p1, const Point p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

int n;

Point p[MAX];

vector<Point> ch;

void calcCH() {
	vi chl;
	fi(1, n) {
		while(sz(chl) > 2 && cross(p[chl[sz(chl) - 2]], p[chl[sz(chl) - 1]], p[i]) < 0) {
			chl.pop_back();
		}
		chl.pb(i);
	}
	fi(0, sz(chl) - 1) {
		ch.pb(p[chl[i]]);
	}
}

ll area(const vector<Point> & v) {
	ll res = 0;
	fi(1, sz(v) - 2) {
		res += cross(v[0], v[i], v[i + 1]);
	}
	return res;
}

int ans;

void solve() {
	int b = 1;
	fi(2, n) {
		if (p[i].x < p[b].x || (p[i].x == p[b].x && p[i].y < p[b].y)) {
			b = i;
		}
	}
	X = p[b].x;
	ans = n;
	fi(1, n) {
		p[i].d = r(p[b], p[i]);
		if (p[i].d == 0) {
			p[i].a = -10.;
		} else {
			p[i].a = atan2(p[i].y - p[b].y, p[i].x - p[b].x);
		}
	}
	sort(p + 1, p + n + 1);
	calcCH();
	if(area(ch) == 0) {
		printf("%d\n", n);
		return;
	}
	int curchsz = sz(ch);
	fi(0, curchsz - 1) {
		ch.pb(ch[i]);
	}
	fi(0, curchsz - 1) {
		ch.pb(ch[i]);
	}
	int pr = 1;
	dbg(curchsz);
	fi(1, curchsz) {
		dbg(i);
		if (cross(ch[i - 1] - ch[i], ch[i + 1] - ch[i]) == 0) continue;
		pr = max(pr, i + 1);
		while (pr < i + curchsz && (cross(ch[i - 1] - ch[i], ch[pr + 1] - ch[pr]) <= 0)) {
			pr++;
		}
		dbg(pr);
		ans = min(ans, pr - i + 1);
	}
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	scanf("%d", &n);
	fi(1, n) {
		scanf("%lld %lld", &p[i].x, &p[i].y);
	}
	solve();
	exit();
	return 0;
}
