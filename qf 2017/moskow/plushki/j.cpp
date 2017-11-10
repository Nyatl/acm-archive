#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <tuple>
#include <map>
#include <ctime>
#include <memory>
#include <memory.h>
#include <iomanip>
#include <functional>
#include <cassert>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define sz(a) ((int)((a).size()))
#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fo(a, b) for(int o = (a); o < (b); ++o)
#define fdi(a, b) for(int i = (int)(a) - 1; i >= (b); --i)
#define fdo(a, b) for(int o = (int)(a) - 1; o >= (b); --o)
#define fdj(a, b) for(int j = (int)(a) - 1; i >= (b); --j)
#define all(a) (a).begin(),(a).end()
#define _(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////////////////////

const ld eps = 1e-10;

struct point {
	ld x, y;
	point() {}
	point(ld x, ld y) : x(x), y(y) {}
	ld r(point a) {
		return hypot(x - a.x, y - a.y);
	}
};

struct figure {
	vector<point> v;
	figure() {}
	figure(point f, point s, point t) {
		v.push_back(f);
		v.push_back(s);
		v.push_back(t);
	}
	ld area() {
		ld ret = 0;
		fi(0, sz(v)) {
			int o = i + 1;
			if (o >= sz(v)) {
				o -= sz(v);
			}
			ret += (v[i].x - v[o].x) * (v[i].y + v[o].y);
		}
		return abs(ret);
	}
};

struct line {
	ld a, b, c;
	line() {}
	line(point f, point s) {
		b = f.x - s.x;
		a = s.y - f.y;
		c = -a * f.x - b * f.y;
	}
	point intersect(const line & l) const {
		return{ (l.c * b - c * l.b) / (a * l.b - l.a * b), (c * l.a - l.c * a) / (a * l.b - l.a * b) };
	}
};

ld area(point & f, point & s, point & t) {
	return (s.x - f.x) * (t.y - f.y) - (s.y - f.y) * (t.x - f.x);
}

int n, w, h;

vector<figure> trs;

vector<int> skipCnts;

bool inside(point & f, point & s, point & p) {
	return area(f, s, p) > eps;
}

ld area(figure sq, int tri) {
	figure& triangle = trs[tri];
	fi(0, 3) {
		if (sz(sq.v) < 3) {
			return 0.;
		}
		point f = triangle.v[i];
		int o = i + 1;
		if (o >= 3) {
			o -= 3;
		}
		point s = triangle.v[o];

		figure sq1 = sq;
		sq.v.clear();

		point S = sq1.v.back();
		fj(0, sz(sq1.v)) {
			if (inside(f, s, sq1.v[j])) {
				if (!inside(f, s, S)) {
					sq.v.push_back(line(f, s).intersect(line(S, sq1.v[j])));
				}
				sq.v.push_back(sq1.v[j]);
			} else if (inside(f, s, S)) {
				sq.v.push_back(line(f, s).intersect(line(S, sq1.v[j])));
			}
			S = sq1.v[j];
		}

	}
	return sq.area();
}

ld allarea(figure & sq) {
	ld ret = 0;
	fi(0, sz(trs)) {
		ld res = area(sq, i);
		if (res > eps) {
			ret += res;
		} else {
			skipCnts[i]++;
		}
	}
	return ret;
}

point nxtPoint() {
	int a, b;
	scanf("%d%d", &a, &b);
	return point(a, b);
}

void printAns(figure a) {
	point p((a.v[0].x + a.v[2].x) / 2, (a.v[0].y + a.v[2].y) / 2);
	printf("%.9lf %.9lf\n", p.x, p.y);
	exit(0);
}

void solve() {
	scanf("%d%d%d", &n, &w, &h);
	fi(0, n) {
		point f = nxtPoint(), s = nxtPoint(), t = nxtPoint();
		if (area(f, s, t) < 0) {
			swap(s, t);
		}
		trs.push_back({ f, s, t });
	}
	figure sq;
	sq.v = { point(0, 0), point(w, 0), point(w, h), point(0, h) };
	while (true) {
		point aa = sq.v[0];
		ld hh = sq.v[2].y - sq.v[1].y;
		ld ww = sq.v[1].x - sq.v[0].x;
		figure ml, mr;
		if (ww > hh) {
			ml.v = { aa, {aa.x + ww / 2, aa.y}, {aa.x + ww / 2, aa.y + hh}, {aa.x, aa.y + hh} };
			mr.v = { {aa.x + ww / 2, aa.y}, {aa.x + ww, aa.y}, {aa.x + ww, aa.y + hh}, {aa.x + ww / 2, aa.y + hh} };
		} else {
			ml.v = { aa, { aa.x + ww, aa.y}, { aa.x + ww, aa.y + hh / 2}, { aa.x, aa.y + hh / 2} };
			mr.v = { { aa.x, aa.y + hh / 2}, { aa.x + ww, aa.y + hh / 2}, { aa.x + ww, aa.y + hh}, { aa.x, aa.y + hh} };
		}
		skipCnts.assign(sz(trs), 0);

		ld mla = allarea(ml);
		ld mra = allarea(mr);

		if (mla < eps) {
			printAns(ml);
		} else if (mra < eps) {
			printAns(mr);
		}

		if (mla < mra) {
			sq = ml;
		} else {
			sq = mr;
		}

		fi(0, sz(skipCnts)) {
			if (skipCnts[i] == 2) {
				swap(skipCnts[i], skipCnts[sz(skipCnts) - 1]);
				swap(trs[i], trs[sz(trs) - 1]);
				skipCnts.pop_back();
				trs.pop_back();
			}
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}