#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <cmath>
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

typedef long long ll;

#define MAX 100100

int n, h, w;

double eps = 1e-9;

struct Point {
	double x, y;
	Point () {
		x = 0;
		y = 0;
	}
	Point (double x, double y) : x(x), y(y) {}
	Point operator-(const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	bool operator<(const Point &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

struct Line {
	double a, b, c;
 
	Line() {}
	Line (Point p, Point q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		norm();
	}
 
	void norm() {
		double z = sqrt(a*a + b*b);
		if (abs(z) > eps) {
			a /= z;
			b /= z;
			c /= z;
		}
	}
 
	double dist(Point p) const {
		return a * p.x + b * p.y + c;
	}
};
 
inline bool between(double l, double r, double x) {
	return min(l, r) <= x + eps && x <= max(l,r) + eps;
}
 
inline bool intersect (double a, double b, double c, double d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a, c) <= min(b, d) + eps;
}

#define det(a,b,c,d)  (a*d-b*c)
 
bool intersect(Point a, Point b, Point c, Point d, Point &res) {
	if (!intersect(a.x, b.x, c.x, d.x) || !intersect(a.y, b.y, c.y, d.y)) return false;
	Line m(a, b);
	Line n(c, d);
	double zn = det(m.a, m.b, n.a, n.b);
	if (fabs(zn) < eps) {
		return false;
	}
	else {
		res.x = -det(m.c, m.b, n.c, n.b) / zn;
		res.y = -det(m.a, m.c, n.a, n.c) / zn;
		return between (a.x, b.x, res.x)
			&& between (a.y, b.y, res.y)
			&& between (c.x, d.x, res.x)
			&& between (c.y, d.y, res.y);
	}
}

Point p1[MAX], p2[MAX], p3[MAX];

double vect(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

double vect(Point a, Point b, Point c) {
	return vect(b - a, c - a);
}

void add(Point &a, Point &b, Point &c, Point &d, vector<Point> &v) {
	Point p;
	if (intersect(a, b, c, d, p)) {
		v.pb(p);
	}
}

bool inside(Point &p, vector<Point> &v) {
	int f1, f2;
	f1 = 0;
	f2 = 0;
	fi(0, sz(v) - 1) {
		double t = vect(v[i], v[(i + 1) % sz(v)], p);
		if (t < -eps) f1 = 1;
		if (t > eps) f2 = 1;
	}
	return !f1 || !f2;
}

double get_area(Point a, Point b, Point c, Point r1, Point r2) {
	vector<Point> t, r, v;
	t.pb(a);
	t.pb(b);
	t.pb(c);
	r.pb(Point(r1.x, r1.y));
	r.pb(Point(r2.x, r1.y));
	r.pb(Point(r2.x, r2.y));
	r.pb(Point(r1.x, r2.y));	

	fi(0, sz(t) - 1) {
		if (inside(t[i], r)) v.pb(t[i]);
	}

	fi(0, sz(r) - 1) {
		if (inside(r[i], t)) v.pb(r[i]);
	}

	fi(0, sz(t) - 1) {
		fj(0, sz(r) - 1) {
			add(t[i], t[(i + 1) % sz(t)], r[j], r[(j + 1) % sz(r)], v);
		}
	}

	if (!sz(v)) return 0;

	vector<pair<double, Point> > p;
	Point C;

	fi(0, sz(v) - 1) {
		C.x += v[i].x;
		C.y += v[i].y;
	}

	C.x /= sz(v);
	C.y /= sz(v);

	fi(0, sz(v) - 1) {
		p.pb(mp(atan2(v[i].y - C.y, v[i].x - C.x), v[i]));
	}
	sort(p.begin(), p.end());

	double res = 0;
	fi(0, sz(p) - 1) {
		res += vect(C, p[i].second, p[(i + 1) % sz(v)].second);
	}
	return fabs(res) / 2.;
}

int q[MAX];

double get_sum(double x1, double x2, double y1, double y2) {
	double res = 0;
	double s = 0;
	fi(1, n) {
		s = get_area(p1[i], p2[i], p3[i], Point(x1, y1), Point(x2, y2));
		if (s < eps) {
			q[i]++;
			if (q[i] == 4) {
				p1[i] = p1[n];
				p2[i] = p2[n];
				p3[i] = p3[n];
				i--;
				n--;
				continue;
			}
		}
		res += s;
	}
	return res;
}

int ansf;

void fun(double x1, double x2, double y1, double y2) {
	if (ansf) {
		printf("%.9lf %.9lf\n", (x1 + x2) / 2, (y1 + y2) / 2);
		exit(0);
	}

	double xh = (x1 + x2) / 2;
	double yh = (y1 + y2) / 2;

	fi(1, n) {
		q[i] = 0;
	}

	int b = 0;
	double bv = get_sum(x1, xh, y1, yh);

	double v = get_sum(xh, x2, y1, yh);
	if (v < bv) {
		b = 1;
		bv = v;
	}

	v = get_sum(x1, xh, yh, y2);
	if (v < bv) {
		b = 2;
		bv = v;
	}

	v = get_sum(xh, x2, yh, y2);
	if (v < bv) {
		b = 3;
		bv = v;
	}

	if (bv < 1e-12) {
		ansf = 1;
	}
	
	if (b == 0)	fun(x1, xh, y1, yh);
	if (b == 1)	fun(xh, x2, y1, yh);
	if (b == 2)	fun(x1, xh, yh, y2);
	if (b == 3)	fun(xh, x2, yh, y2);	
}

void solve() {
	fun(0, w, 0, h);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d %d", &n, &w, &h);
	fi(1, n) {
		scanf("%lf %lf", &p1[i].x, &p1[i].y);
		scanf("%lf %lf", &p2[i].x, &p2[i].y);
		scanf("%lf %lf", &p3[i].x, &p3[i].y);
	}

	solve();

	return 0;
}