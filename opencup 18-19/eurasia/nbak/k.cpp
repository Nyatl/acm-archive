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

#ifndef LOCAL
typedef __int128 lll;
#else
typedef long long lll;
#endif


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

struct Time {
	int h, m, s;
	Time() {}
	Time(int h, int m, int s) : h(h), m(m), s(s) {}
	Time(double x) {
		x *= 24;
		h = (int)x;
		x -= h;
		x *= 60;
		m = (int)x;
		x -= m;
		x *= 60;
		s = (int)x;
	}
	Time operator+(const Time &t) const {
		int h2, m2, s2;
		h2 = h + t.h;
		m2 = m + t.m;
		s2 = s + t.s;
		m2 += s2 / 60;
		s2 %= 60;
		h2 += m2 / 60;
		m2 %= 60;
		h2 %= 24;
		return Time(h2, m2, s2);
	}
};

struct Point {
	double x, y, z;
	Point() {}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
};

double toRad(double x) {
	return x * M_PI / 180.;
}

Point rotateOX(const Point &p, double alp) {
	double x = p.x;
	double y = p.y * cos(alp) - p.z * sin(alp);
	double z = p.y * sin(alp) + p.z * cos(alp);
	return Point(x, y, z);
}

Point rotateOY(const Point &p, double alp) {
	double x = p.z * sin(alp) + p.x * cos(alp);
	double y = p.y;
	double z = p.z * cos(alp) - p.x * sin(alp);
	return Point(x, y, z);
}

Point rotateOZ(const Point &p, double alp) {
	double x = p.x * cos(alp) - p.y * sin(alp);
	double y = p.x * sin(alp) + p.y * cos(alp);
	double z = p.z;
	return Point(x, y, z);
}

void solve() {
	double phi, alp;
	Time t;
	scanf("%lf %lf", &alp, &phi);
	scanf("%d:%d:%d", &t.h, &t.m, &t.s);
	
	phi = toRad(phi);
	alp = toRad(alp);
	
	double l = 0;
	double r = M_PI / 2;
	
	fi(1, 20) {
		double h = (l + r) / 2;
		Point p(1, 0, 0);
		p = rotateOY(p, phi);
		p = rotateOZ(p, h);
		p = rotateOX(p, alp);
		if (p.z > 0) {
			r = h;
		} else {
			l = h;
		}
	}
	
	double x = (l + r) / 2;
	Time ans = t + Time(x / (2 * M_PI));
	
	printf("%02d:%02d:%02d\n", ans.h, ans.m, ans.s);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	while (tests--) {
		solve();
	}
	return 0;
}