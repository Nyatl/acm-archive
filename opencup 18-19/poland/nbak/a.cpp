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

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	Point operator-(const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator+(const Point &p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator*(double t) const {
		return Point(x * t, y * t);
	}
};

struct Line {
	Point p1, p2;
	Line() {}
	Line(int A, int B, int C) {
		if (B) {
			p1 = Point(0., -C * 1. / B);
			p2 = Point(1., (-C - A) * 1. / B);
		} else {
			p1 = Point(-C * 1. / A, 0.);
			p2 = Point((-C - B) * 1. / A, 1.);
		}
	}
	Line(Point p1, Point p2) : p1(p1), p2(p2) {}
	Point getP(double x) const {
		return p1 + ((p2 - p1) * x);
	}
};

Line l1, l2;

Point p0(0, 0);

double ro(const Point &p1, const Point &p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

Point get(const Point & p) {
	double l = 1e18;
	double r = -1e18;
	fi(1, 200) {
		double h1 = l + (r - l) / 3;
		double h2 = r - (r - l) / 3;
		Point p1 = l2.getP(h1);
		Point p2 = l2.getP(h2);
		if (ro(p0, p1) + ro(p, p1) < ro(p0, p2) + ro(p, p2)) {
			r = h2;
		} else {
			l = h1;
		}
	}
	
	return l2.getP((l + r) / 2);
}

void solve() {
	double l = -1e18;
	double r = 1e18;
	fi(1, 200) {
		double h1 = l + (r - l) / 3;
		double h2 = r - (r - l) / 3;
		Point p1 = l1.getP(h1);
		Point p2 = l1.getP(h2);
		Point p3 = get(p1);
		Point p4 = get(p2);
		if (ro(p0, p1) + ro(p1, p3) + ro(p3, p0) < ro(p0, p2) + ro(p2, p4) + ro(p4, p0)) {
			r = h2;
		} else {
			l = h1;
		}
	}
	Point p1 = l1.getP((l + r) / 2);
	Point p2 = get(p1);
	double ans = ro(p0, p1) + ro(p1, p2) + ro(p2, p0);
	printf("%.15lf", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	l1 = Line(a, b, -c);
	scanf("%d %d %d", &a, &b, &c);
	l2 = Line(a, b, -c);
	solve();
	exit();
	return 0;
}
