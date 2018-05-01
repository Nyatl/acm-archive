#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;


template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	for (T z : v) s << z << " ";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, deque<T> v) {
	for (T z : v) s << z << " ";
	return s;
}


template<typename T1, typename T2>
ostream& operator<<(ostream& s, pair<T1, T2> v) {
	s << v.first << " " << v.second;
	return s;
}

#define sz(a) (int)((a).size())
#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fj(a,b) for(int j = (a); j <= (b); ++j)
#define fo(a,b) for(int o = (a); o <= (b); ++o)
#define fdi(a,b) for(int i = (a); i >= (b); --i)
#define fdj(a,b) for(int j = (a); j >= (b); --j)
#define fdo(a,b) for(int o = (a); o >= (b); --o)
#define all(a) (a).begin(),(a).end()

#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << '\t' << #x << ":" << x << endl
#define dbg0(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=0; ABC<n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=1; ABC<=n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while(false) {}
#define dbg0(x, n) while(false) {}
#define dbg1(x, n) while(false) {}
#endif 

const double EPS = 1e-9;

double sqr(double x) {
	return x * x;
}

struct Point {
	double x, y;
	double a, d;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	bool operator<(const Point & p) const {
		if (a != p.a) {
			return a < p.a;
		}
		return d < p.d;
	}
	double r(const Point & p) const {
		return hypot(x - p.x, y - p.y);
	}
};

struct Square {
	Point a, b, c, d;
	Square() {}
	Square(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}
};

struct Point3D {
	double x, y, z;
	Point3D() {}
	Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
	Point projection() {
		return Point(x, z);
	}
};

struct Square3D {
	Point3D a, b, c, d;
	Point3D cen;
	Square3D() {}
	Square3D(Point3D a, Point3D b, Point3D c, Point3D d, Point3D cen) : a(a), b(b), c(c), d(d), cen(cen) {}
	Square projection() {
		return Square(a.projection(), b.projection(), c.projection(), d.projection());
	}
};

struct Cube {
	Square3D s1, s2, s3, s4, s5, s6;
	Cube() {}
	Cube(Square3D s1, Square3D s2, Square3D s3, Square3D s4, Square3D s5, Square3D s6) : s1(s1), s2(s2), s3(s3), s4(s4), s5(s5), s6(s6) {}
};

double cross(const Point & p1, const Point & p2, const Point & p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

vector<Point> convexHull(vector<Point> & v) {
	int b = 0;
	fi(1, sz(v) - 1) {
		if (v[i].x < v[b].x || (v[i].x == v[b].x && v[i].y < v[i].y)) {
			b = i;
		}
	}
	fi(0, sz(v) - 1) {
		v[i].d = v[i].r(v[b]);
		if (v[i].d < EPS) {
			v[i].a = -10;
		} else {
			v[i].a = atan2(v[i].y - v[b].y, v[i].x - v[b].x);
		}
	}
	sort(all(v));
	v.pb(v[0]);
	vector<Point> ch;
	fi(0, sz(v) - 1) {
		while (sz(ch) >= 2) {
			Point & prv = ch[sz(ch) - 2];
			Point & cur = ch[sz(ch) - 1];
			if (cross(prv, cur, v[i]) < EPS) {
				ch.pop_back();
			} else {
				break;
			}
		}
		ch.pb(v[i]);
	}
	return ch;
}

double area(vector<Point> & ch) {
	if (sz(ch) < 3) {
		return 0.;
	}
	double res = 0.;
	fi(1, sz(ch) - 1 - 1) {
		res += cross(ch[0], ch[i], ch[i + 1]);
	}
	return abs(res) / 2;
}

Point3D rotateOX(const Point3D & p, double ang) {
	Point3D res;
	res.x = p.x;
	res.y = p.y * cos(ang) - p.z * sin(ang);
	res.z = p.y * sin(ang) + p.z * cos(ang);
	return res;
}

Point3D rotateOZ(const Point3D & p, double ang) {
	Point3D res;
	res.x = p.x * cos(ang) - p.y * sin(ang);
	res.y = p.x * sin(ang) + p.y * cos(ang);
	res.z = p.z;
	return res;
}

Square3D rotateOX(const Square3D & sq, double ang) {
	Square3D res;
	res.a = rotateOX(sq.a, ang);
	res.b = rotateOX(sq.b, ang);
	res.c = rotateOX(sq.c, ang);
	res.d = rotateOX(sq.d, ang);
	res.cen = rotateOX(sq.cen, ang);	
	return res;
}

Square3D rotateOZ(const Square3D & sq, double ang) {
	Square3D res;
	res.a = rotateOZ(sq.a, ang);
	res.b = rotateOZ(sq.b, ang);
	res.c = rotateOZ(sq.c, ang);
	res.d = rotateOZ(sq.d, ang);
	res.cen = rotateOZ(sq.cen, ang);	
	return res;
}

Cube rotateOX(const Cube & c, double ang) {
	Cube res;
	res.s1 = rotateOX(c.s1, ang);
	res.s2 = rotateOX(c.s2, ang);
	res.s3 = rotateOX(c.s3, ang);
	res.s4 = rotateOX(c.s4, ang);
	res.s5 = rotateOX(c.s5, ang);
	res.s6 = rotateOX(c.s6, ang);
	return res;
}

Cube rotateOZ(const Cube & c, double ang) {
	Cube res;
	res.s1 = rotateOZ(c.s1, ang);
	res.s2 = rotateOZ(c.s2, ang);
	res.s3 = rotateOZ(c.s3, ang);
	res.s4 = rotateOZ(c.s4, ang);
	res.s5 = rotateOZ(c.s5, ang);
	res.s6 = rotateOZ(c.s6, ang);
	return res;
}

double A;

Cube initCube() {
	double h = 0.5;
	Square3D OXY1 = Square3D(Point3D(-h, -h, h), Point3D(h, -h, h), Point3D(h, h, h), Point3D(-h, h, h), Point3D(0, 0, h));
	Square3D OYZ1 = Square3D(Point3D(h, -h, -h), Point3D(h, h, -h), Point3D(h, h, h), Point3D(h, -h, h), Point3D(h, 0, 0));
	Square3D OZX1 = Square3D(Point3D(-h, h, -h), Point3D(h, h, -h), Point3D(h, h, h), Point3D(-h, h, h), Point3D(0, h, 0));
	Square3D OXY2 = Square3D(Point3D(-h, -h, -h), Point3D(h, -h, -h), Point3D(h, h, -h), Point3D(-h, h, -h), Point3D(0, 0, -h));
	Square3D OYZ2 = Square3D(Point3D(-h, -h, -h), Point3D(-h, h, -h), Point3D(-h, h, h), Point3D(-h, -h, h), Point3D(-h, 0, 0));
	Square3D OZX2 = Square3D(Point3D(-h, -h, -h), Point3D(h, -h, -h), Point3D(h, -h, h), Point3D(-h, -h, h), Point3D(0, -h, 0));
	return Cube(OXY1, OYZ1, OZX1, OXY2, OYZ2, OZX2);
}

vector<Point3D> getPoints(const Cube & c) {
	vector<Point3D> res;
	res.pb(c.s1.a);
	res.pb(c.s1.b);
	res.pb(c.s1.c);
	res.pb(c.s1.d);
	res.pb(c.s2.a);
	res.pb(c.s2.b);
	res.pb(c.s2.c);
	res.pb(c.s2.d);
	res.pb(c.s3.a);
	res.pb(c.s3.b);
	res.pb(c.s3.c);
	res.pb(c.s3.d);
	res.pb(c.s4.a);
	res.pb(c.s4.b);
	res.pb(c.s4.c);
	res.pb(c.s4.d);
	res.pb(c.s5.a);
	res.pb(c.s5.b);
	res.pb(c.s5.c);
	res.pb(c.s5.d);
	res.pb(c.s6.a);
	res.pb(c.s6.b);
	res.pb(c.s6.c);
	res.pb(c.s6.d);
	return res;
}

vector<Point> getProj(vector<Point3D> & v3D) {
	vector<Point> res;
	fi(0, sz(v3D)) {
		res.pb(v3D[i].projection());
	}
	return res;
}

double calcArea(const Cube & c) {
	vector<Point3D> v3D;
	v3D = getPoints(c);
	vector<Point> v = getProj(v3D);
	vector<Point> ch = convexHull(v);
	double S = area(ch);
	return S;
}

double getBegR(const Cube & c) {
	double l = 0;
	double r = M_PI / 4;
	fi(1, 100) {
		double h1 = l + (r - l) / 3;
		double h2 = r - (r - l) / 3;
		Cube c1 = rotateOX(c, h1);
		Cube c2 = rotateOX(c, h2);
		double S1 = calcArea(c1);
		double S2 = calcArea(c2);
		if (S1 > S2) {
			r = h2;
		} else {
			l = h1;
		}
	}
	return l + EPS;
}

void solve() {
	scanf("%lf", &A);
	double sqrt2 = sqrt(2);
	Cube c = initCube();
	double l, r;
	if (A < sqrt2 + EPS) {
		l = 0;
		r = M_PI / 4;
	} else {
		c = rotateOZ(c, M_PI / 4);
		l = 0;
		r = getBegR(c);
	}
	fi(1, 100) {
		double h = (l + r) / 2;
		Cube c1 = rotateOX(c, h);
		double S = calcArea(c1);
		if (S > A) {
			r = h;
		} else {
			l = h;
		}
	}
	dbg(l);
	c = rotateOX(c, l);
	dbg(calcArea(c));
	printf("%.15lf %.15lf %.15lf\n", c.s1.cen.x, c.s1.cen.y, c.s1.cen.z);
	printf("%.15lf %.15lf %.15lf\n", c.s2.cen.x, c.s2.cen.y, c.s2.cen.z);
	printf("%.15lf %.15lf %.15lf\n", c.s3.cen.x, c.s3.cen.y, c.s3.cen.z);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int nT;
	scanf("%d", &nT);
	fi(1, nT) {
		printf("Case #%d:\n", i);
		solve();
//		printf("\n");
	}
	return 0;
}