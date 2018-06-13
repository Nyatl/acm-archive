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

const double INF = 1e18;
const double EPS = 1e-9;
const int MAX = 100 + 5;

auto sqr(auto x) {
	return x * x;
}

struct Point {
	double x, y, z;
	Point() {}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point operator-(const Point & p) const {
		return Point(x - p.x, y - p.y, z - p.z);
	}
	Point operator+(const Point & p) const {
		return Point(x + p.x, y + p.y, z + p.z);
	}
};

struct Tetr {
	Point p1, p2, p3, p4;
	Tetr() {}
	Tetr(Point p1, Point p2, Point p3, Point p4) : p1(p1), p2(p2), p3(p3), p4(p4) {}
};

double det(const Point & p1, const Point & p2, const Point & p3) {
	return (p1.x * p2.y * p3.z + p1.y * p2.z * p3.x + p1.z * p2.x * p3.y) - (p3.x * p2.y * p1.z + p3.y * p2.z * p1.x + p3.z * p2.x * p1.y);
}

double vol(const Point & p1, const Point & p2, const Point & p3, const Point & p4) {
	return abs(det(p2 - p1, p3 - p1, p4 - p1));
}

double vol(const Tetr & t) {
	return vol(t.p1, t.p2, t.p3, t.p4);
}

int n;

Point p[MAX];

vector<Tetr> tetrs;

Point cut_z(Point p1, Point p2, double z) {
	if (p1.z > p2.z) {
		swap(p1, p2);
	}
	double c = (z - p1.z) / (p2.z - p1.z);
	double x = (p2.x - p1.x) * c + p1.x;
	double y = (p2.y - p1.y) * c + p1.y;
	return Point(x, y, z);
}

double calcVol(const Tetr & t, double z) {
	double res = vol(t);
	vector<Point> v1;
	vector<Point> v2;
	if (t.p1.z < z) {
		v1.pb(t.p1);
	} else {
		v2.pb(t.p1);
	}
	if (t.p2.z < z) {
		v1.pb(t.p2);
	} else {
		v2.pb(t.p2);
	}
	if (t.p3.z < z) {
		v1.pb(t.p3);
	} else {
		v2.pb(t.p3);
	}
	if (t.p4.z < z) {
		v1.pb(t.p4);
	} else {
		v2.pb(t.p4);
	}
	if (sz(v1) == 4) {
		return res;
	}
	if (sz(v2) == 4) {
		return 0.;
	}
	if (sz(v1) == 3) {
		Point p1 = cut_z(v1[0], v2[0], z);
		Point p2 = cut_z(v1[1], v2[0], z);
		Point p3 = cut_z(v1[2], v2[0], z);
		double vol1 = vol(v2[0], p1, p2, p3);
		return res - vol1;
	}
	if (sz(v2) == 3) {
		Point p1 = cut_z(v1[0], v2[0], z);
		Point p2 = cut_z(v1[0], v2[1], z);
		Point p3 = cut_z(v1[0], v2[2], z);
		double vol1 = vol(v1[0], p1, p2, p3);
		return vol1;
	}
	Point p1 = cut_z(v1[0], v2[0], z);
	Point p2 = cut_z(v1[0], v2[1], z);
	Point p3 = cut_z(v1[1], v2[0], z);
	Point p4 = cut_z(v1[1], v2[1], z);
	double vol1 = vol(v2[0], v2[1], p2, p4);
	double vol2 = vol(v2[0], p2, p3, p4);
	double vol3 = vol(v2[0], p2, p3, p1);
	return res - vol1 - vol2 - vol3;
}

double calcVol(double z) {
	double res = 0.;
	fi (0, sz(tetrs) - 1) {
		res += calcVol(tetrs[i], z);
	}
	return res;
}


void solve() {
	Point p0(0, 0, 0);
	fi(1, n) {
		p0 = p0 + p[i];
	}
	p0.x /= n;
	p0.y /= n;
	p0.z /= n;
	fi(1, n) {
		fj(i + 1, n) {
			fo(j + 1, n) {
				int f = 0;
				for (int w = 1; w <= n; ++w) {
					auto t = det(p[j] - p[i], p[o] - p[i], p[w] - p[i]);
					if (t < -EPS) {
						f |= 1;
					}
					if (t > EPS) {
						f |= 2;
					}
				}
				if (f == 3) continue;
				tetrs.pb(Tetr(p0, p[i], p[j], p[o]));
			}
		}
	}	
	double z1 = INF;
	double z2 = -INF;
	fi(1, n) {
		z1 = min(z1, p[i].z);
		z2 = max(z2, p[i].z);
	}
	double vol0 = calcVol(z2);
	dbg(vol0);
	double l = z1;
	double r = z2;
	fi(1, 100) {
		double h = (l + r) / 2;
		double vol = calcVol(h);
		if (vol > vol0 * 0.9) {
			r = h;
		} else {
			l = h;
		}
	}
	double ans = l - z1;
	printf("%.15lf\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	scanf("%d", &n);
	fi(1, n) {
		scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
	}
	solve();
	exit();
	return 0;
}
