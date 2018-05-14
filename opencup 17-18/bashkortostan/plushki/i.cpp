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

const int MAX = 100 + 5;

int sq(int x) {
	return x * x;
}

double sq(double x) {
	return x * x;
}

int zn(int x) {
	if (x > 0) {
		return 1;
	} else if (x < 0) {
		return -1;
	}
	return 0;
}

struct point {
	int x, y, z;
	point() {}
	point(int x, int y, int z) : x(x), y(y), z(z) {}
	point operator-(const point & p) const {
		return point(x - p.x, y - p.y, z - p.z);
	}
};

struct plane {
	int A, B, C;
	plane() {}
	plane(int A, int B, int C) : A(A), B(B), C(C) {}
	bool check(int x) {
		if (x == A) {
			return false;
		}
		if (x == B) {
			return false;
		}
		if (x == C) {
			return false;
		}
		return true;
	}
};

struct Point {
	double x, y, z;
	Point() {}
	Point(point p) {
		x = p.x;
		y = p.y;
		z = p.z;
	}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point operator-(const Point & p) const {
		return Point(x - p.x, y - p.y, z - p.z);
	}
};

struct Tetr {
	Point p1, p2, p3, p4;
	Tetr() {}
	Tetr(Point p1, Point p2, Point p3, Point p4) : p1(p1), p2(p2), p3(p3), p4(p4) {}
};

int det(const point & p1, const point & p2, const point & p3) {
	return (p1.x * p2.y * p3.z + p1.y * p2.z * p3.x + p1.z * p2.x * p3.y) - (p1.z * p2.y * p3.x + p1.x * p2.z * p3.y + p1.y * p2.x * p3.z);
}

int vol(const point & p1, const point & p2, const point & p3, const point & p4) {
	return det(p2 - p1, p3 - p1, p4 - p1);
}



double det(const Point & p1, const Point & p2, const Point & p3) {
	return (p1.x * p2.y * p3.z + p1.y * p2.z * p3.x + p1.z * p2.x * p3.y) - (p1.z * p2.y * p3.x + p1.x * p2.z * p3.y + p1.y * p2.x * p3.z);
}

double vol(const Point & p1, const Point & p2, const Point & p3, const Point & p4) {
	return abs(det(p2 - p1, p3 - p1, p4 - p1));
}

double vol(const Tetr & t) {
	return vol(t.p1, t.p2, t.p3, t.p4);
}


int n;

point p[MAX];
vector<plane> planes;

vector<Tetr> tetrs;

Point perz(Point p1, Point p2, double z) {
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
	vector<Point> under;
	vector<Point> upside;
	if (t.p1.z < z) {
		under.pb(t.p1);
	} else {
		upside.pb(t.p1);
	}
	if (t.p2.z < z) {
		under.pb(t.p2);
	} else {
		upside.pb(t.p2);
	}
	if (t.p3.z < z) {
		under.pb(t.p3);
	} else {
		upside.pb(t.p3);
	}
	if (t.p4.z < z) {
		under.pb(t.p4);
	} else {
		upside.pb(t.p4);
	}
	if (sz(under) == 4) {
		return res;
	}
	if (sz(upside) == 4) {
		return 0;
	}
	if (sz(upside) == 3) {
		Point p1 = perz(under[0], upside[0], z);
		Point p2 = perz(under[0], upside[1], z);
		Point p3 = perz(under[0], upside[2], z);
		double vol1 = vol(under[0], p1, p2, p3);
		return vol1;
	}
	if (sz(under) == 3) {
		Point p1 = perz(under[0], upside[0], z);
		Point p2 = perz(under[1], upside[0], z);
		Point p3 = perz(under[2], upside[0], z);
		double vol1 = vol(upside[0], p1, p2, p3);
		return res - vol1;
	}
	Point p1 = perz(under[0], upside[0], z);
	Point p2 = perz(under[0], upside[1], z);
	Point p3 = perz(under[1], upside[0], z);
	Point p4 = perz(under[1], upside[1], z);
	double vol1 = vol(upside[0], upside[1], p2, p4);
	double vol2 = vol(upside[0], p2, p3, p4);
	double vol3 = vol(upside[0], p2, p3, p1);
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
	double vol0 = 0;
	double z1 = 10000;
	double z2 = -10000;
	fi(1, n) {
		z1 = min(z1, (double)p[i].z);
		z2 = max(z2, (double)p[i].z);
	}
	fi (1, n) {
		fj(i + 1, n) {
			fo(j + 1, n) {
				int f = 0;
				for (int iter = 1; iter <= n; iter++) {
					int t = zn(vol(p[i], p[j], p[o], p[iter])); 
					if (t < 0) f |= 1;
					if (t > 0) f |= 2;
				}
				if (f != 3) {
					planes.pb(plane(i, j, o));
				}
			}
		}
	}
	
	bool b = 1;
	fi (2, n) {
		if (p[i].z < p[b].z) {
			b = i;
		}
	}
	fi(0, sz(planes) - 1) {
		if (planes[i].check(b)) {
			tetrs.pb(Tetr(p[b], p[planes[i].A], p[planes[i].B], p[planes[i].C]));
		}
	}
	fi(0, sz(tetrs) - 1) {
		vol0 += vol(tetrs[i]);
	}
	double l = z1;
	double r = z2;
	fi(0, 100) {
		double h = (l + r) / 2;
		double vol = calcVol(h);
		if (vol < 0.9 * vol0) {
			l = h;
		} else {
			r = h;
		}
	}
	
	double ans = l - z1;
	
	printf("%.15lf\n", ans);
}

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
	}
	solve();
	exit();
	return 0;
}
