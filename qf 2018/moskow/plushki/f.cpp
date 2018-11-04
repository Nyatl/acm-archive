#include <bits/stdc++.h>

#define y1 _y1

using namespace std;

#define sz(x) (int) x.size()
#define fi(a, b) for (int i = a; i <= b; i++)
#define fj(a, b) for (int j = a; j <= b; j++)
#define fo(a, b) for (int o = a; o <= b; o++)
#define fdi(a, b) for (int i = a; i >= b; i--)
#define fdj(a, b) for (int j = a; j >= b; j--)
#define fdo(a, b) for (int o = a; o >= b; o--)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template<typename A, typename B>
ostream &operator <<(ostream &s, pair<A, B> v) {
	s << "(" << v.first << ", " << v.second << ")";
	return s;
}

template<typename T>
ostream &operator <<(ostream &s, set<T> v) {
	for (auto z : v) {
		s << z << " ";
	}
	return s;
}

template<typename T>
ostream &operator <<(ostream &s, vector<T> v) {
	for (auto z : v) {
		s << z << " ";
	}
	return s;
}

template<typename A, typename B>
ostream &operator <<(ostream &s, map<A, B> v) {
	for (auto z : v) {
		s << "(" << z.first << " -> " << z.second << "),";
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << #x << " : " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << #x << " : " << x << endl; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << #x << " : " << x << endl; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while (0) {}
#define dbg0(x, n) while (0) {}
#define dbg1(x, n) while (0) {}
#endif

///////////////////////////////////  

int n, k;
const double EPS = 1e-9;

double sqr(double x) {
	return x * x;
}

bool eq(double a, double b) {
	return abs(a - b) < EPS;
}

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	bool operator<(const Point &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator==(const Point &p) const {
		return eq(x, p.x) && eq(y, p.y);
	}
	Point operator-(const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator+(const Point &p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator*(double k) const {
		return Point(x * k, y * k);
	}
};

ostream &operator <<(ostream &s, Point p) {
	s << "(" << p.x << "," << p.y << ")";
	return s;
}


struct Line {
	double A, B, C;
	Line() {}
	Line(Point p1, Point p2) {
		A = (-(p2.y - p1.y));
		B = (p2.x - p1.x);
		C = p1.x * p2.y - p1.y * p2.x;
		double g = hypot(A, B);
		A /= g;
		B /= g;
		C /= g;
	}
	double dist(const Point &p) const {
		return A * p.x + B * p.y + C;
	}
	Point norm() const {
		return Point(A, B);
	}
	Point normScaled(double k) {
		return Point(A * k, B * k);
	}
};

double cross(const Point &p1, const Point &p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

double cross(const Point &p1, const Point &p2, const Point &p3) {
	return cross(p2 - p1, p3 - p1);
}

double area(const vector<Point> &v) {
	double res = 0.;
	fi(2, sz(v) - 1) {
		res += cross(v[0], v[i - 1], v[i]);
	}
	return abs(res);
}

Point inter(Point a, Point b, Point c, Point d) {
	double l = 0 - EPS;
	double r = 1 + EPS;
	if (cross(c, a, d) >= 0 + EPS) {
		swap(a, b);
	}
	fi(1, 100) {
		double h = (l + r) / 2;
		Point p = (a + ((b - a) * h));
		if (cross(c, p, d) > 0.) {
			r = h;
		} else {
			l = h;
		}
	}
	return a + ((b - a) * l);
}

bool intersect1(double x1, double y1, double x2, double y2) {
	if (y1 < x1) {
		swap(x1, y1);
	}
	if (y2 < x2) {
		swap(x2, y2);
	}
	return min(y1, y2) >= max(x1, x2) - EPS;
}

bool intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
	if (!intersect1(a.x, b.x, c.x, d.x)) return false;
	if (!intersect1(a.y, b.y, c.y, d.y)) return false;
	double A1 = cross(a, c, b);
	double A2 = cross(b, d, a);
	double A3 = cross(c, b, d);
	double A4 = cross(d, a, c);
	/*dbg(A1);
	dbg(A2);
	dbg(A3);
	dbg(A4);*/
	if ((A1 < 0) ^ (A2 < 0)) return false;
	if ((A3 < 0) ^ (A4 < 0)) return false;
	return true;
}

vector<Point> clip(vector<Point> &v, Point p1, Point p2) {
	if (sz(v) < 3) return vector<Point>();
	vector<Point> res;
	Point last = v.back();
	for (int i = 0; i < sz(v); i++) {
		if (cross(p1, v[i], p2) > 0 + EPS) {
			if ((cross(p1, last, p2) > 0 + EPS)) {
				res.pb(v[i]);
			} else {
				res.pb(inter(last, v[i], p1, p2));
				res.pb(v[i]);
			}
		} else if (cross(p1, last, p2) > 0 + EPS) {
			res.pb(inter(last, v[i], p1, p2));
		}
		last = v[i];
	}
	return res;
}

pair<vector<Point>, vector<Point> > split(vector<Point> &v, Point p1, Point p2) {
	return mp(clip(v, p1, p2), clip(v, p2, p1));
}

vector<Point> flip(vector<Point> &v, Point p1, Point p2) {
	vector<Point> res;
	Line l(p1, p2);
	for (Point &z : v) {
		res.pb(z - l.normScaled(2 * l.dist(z)));
	}
	reverse(all(res));
	return res;
}

vector<Point> unite(vector<Point> &v1, vector<Point> &v2) {
	vector<Point> res;
	/*vector<Point> t1;
	vector<Point> t2;
	fi(0, sz(v1) - 1) {
		fj(0, sz(v2) - 1) {
			if (intersect()) {
				t1.pb(inter())
			}
		}
	}
	*/
	return res;
}

pair<vector<Point>, vector<Point> > fold(vector<Point> &v, Point p1, Point p2) {
	pair<vector<Point>, vector<Point> > splitted = split(v, p1, p2);
	dbg(splitted);
	vector<Point> flipped = flip(splitted.second, p1, p2);
	dbg(flipped);
	/*vector<Point> res = unite(flipped, splitted.second);
	v = res;*/
	return mp(splitted.first, flipped);
}

Point toCheck(4141, 785);

bool inside(Point p, const vector<Point> &v) {
	if (sz(v) == 0) return false;
	Point last = v.back();
	int q = 0;
	for (Point z : v) {
	//	dbg(mp(last, z));
	//	dbg(mp(p, toCheck));
		if (intersect(last, z, p, toCheck)) {
			q++;
	//		dbg(q);
		}
		last = z;
	}
	//dbg(q);
	return (q & 1) == 1;
}

double getArea(vector<vector<Point> > &t) {
	double x0 = 1e18;
	double y0 = 1e18;
	for (auto &z : t) {
		for (auto &p : z) {
			x0 = min(x0, p.x);
			y0 = min(y0, p.y);
		}
	}
	Point p0(x0, y0);
	fi(0, sz(t) - 1) {
		fj(0, sz(t[i]) - 1) {
			t[i][j]  = t[i][j] - p0;
		}
	}/*
	for (auto &z : t) {
		dbg(inside(Point(1, 9), z));
	}
	return 0;*/
	double step = (n * 2.) / 200.;
	//dbg(step);
	int q = 0;
	for (double i = step / 2 + EPS; i <= n * 2.; i += step) {
		for (double j = step / 2 + EPS; j <= n * 2.; j += step) {
			bool f = false;
			for (auto &z : t) {
				if (f) break;
				f |= inside(Point(i, j), z);
			}
			
			if (f) {
				//dbg(mp(i, j));
				q++;
			} else {
				//dbg(mp(i, j));
			}
		}
	}
	return q * sqr(step);
}

int getPercent(double x) {
	x *= 100;
	return (int)x;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
/*	Point h = inter(Point(0,10), Point(10,10), Point(1, 9), toCheck);
	dbg(cross(h, Point(0,10), Point(10,10)));
	dbg(cross(h, Point(1,9), toCheck));
	dbg(intersect(Point(10,10), Point(0,10), Point(1, 9), toCheck));
	return 0;
*/
	scanf("%d %d", &n, &k);
	vector<Point> v;
	v.pb(Point(-n / 2., -n / 2.));
	v.pb(Point(n / 2., -n / 2.));
	v.pb(Point(n / 2., n / 2.));
	v.pb(Point(-n / 2., n / 2.));
	vector<vector<Point> > t;
	t.pb(v);
	fi(1, k) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		vector<vector<Point> > t2;
		dbg(i);
		for (vector<Point> &z : t) {
			auto p = fold(z, Point(x1, y1), Point(x2, y2));
			t2.pb(p.first);
			t2.pb(p.second);
		}
		t = t2;
	}
	dbg(t);	
	double S = getArea(t);
	dbg(S);
	printf("%d\n", getPercent(S / sqr(n)));
	return 0;
}