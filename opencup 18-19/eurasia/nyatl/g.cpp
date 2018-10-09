#include <bits/stdc++.h>

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

#define MAX 100100

struct Point {
	ll x, y;
	Point() {
	}
	Point(ll x, ll y) {
		this->x = x;
		this->y = y;
	}
	Point operator+(const Point &p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	bool operator<(const Point &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

ostream& operator<<(ostream& os, Point p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

struct Frac {
	ll a = 0;
	ll b = 1;
	Frac() {
	}
	Frac(ll a, ll b) {
		this->a = a;
		this->b = b;
	}
	bool operator<(const Frac &f) const {
		return a * f.b < b * f.a;
	}
};

ll cross(Point p1, Point p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

ll cross(Point p1, Point p2, Point p3) {
	return cross(p2 - p1, p3 - p1);
}

int n;
ll M;
int k[MAX];
vector<Point> p[MAX];
map<Point, int> orig[MAX];
int c[MAX];

ll sum_m = 0;
double sum_w = 0;

Frac get_slope(int num, int c) {
	if (c == 0) return Frac(1000000100, 1);
	Point g = p[num][c] - p[num][c - 1];
	return Frac(abs(g.y), abs(g.x));
}

void print_ans1() {
	dbg(sum_m);
	dbg(sum_w);
	printf("%.15lf\n", sum_w);
	fi(1, n) {
		printf("1 %d\n", orig[i][p[i][c[i]]]);
	}
	exit();
}

void print_ans2(int num, ll alpha1, ll alpha2) {
	dbg(sum_m);
	printf("%.15lf\n", sum_w);
	fi(1, n) {
		if (i == num) {
			printf("2 %d %d %lld %lld\n", orig[i][p[i][c[i] - 1]], orig[i][p[i][c[i]]], alpha1, alpha2);
		} else {
			printf("1 %d\n", orig[i][p[i][c[i]]]);
		}
	}
	exit();
}

void solve() {
	fi(1, n) {
		c[i] = sz(p[i]) - 1;
	}

	fi(1, n) {
		sum_m += p[i][c[i]].x;
		sum_w += p[i][c[i]].y;
	}

	dbg(sum_m);
	dbg(sum_w);

	set <pair<Frac, int> > t;
	fi(1, n) {
		t.insert(mp(get_slope(i, c[i]), i));
	}

	while (1) {
		auto g = *t.begin();
		int num = g.second;
		t.erase(t.begin());

		vector<Point> &p = ::p[num];
		int &c = ::c[num];

		if (sum_m <= M) {
			print_ans1();
		}

		if (sum_m - p[c].x + p[c - 1].x < M) {
			ll alpha1 = p[c].x - (M - (sum_m - p[c].x));
			ll alpha2 = p[c].x - p[c - 1].x;
			sum_w -= p[c].y;
			sum_w += ((double)alpha1 / alpha2) * p[c - 1].y + (1 - (double)alpha1 / alpha2) * p[c].y;
			print_ans2(num, alpha1, alpha2);
		}
		sum_m -= p[c].x;
		sum_w -= p[c].y;
		c--;
		sum_m += p[c].x;
		sum_w += p[c].y;
		t.insert(mp(get_slope(num, c), num));
	}
}

vector<Point> hull(vector<Point> p) {
	sort(all(p));
	vector<int> v;
	v.pb(0);
	fi(1, sz(p) - 1) {
		if (p[i].y >= p[v[sz(v) - 1]].y) continue;
		while (sz(v) >= 2 && cross(p[v[sz(v) - 2]], p[v[sz(v) - 1]], p[i]) <= 0) {
			v.pop_back();
		}
		v.pb(i);
	}
	vector<Point> res;
	for (auto z : v) {
		res.pb(p[z]);
	}
	return res;
}

void init() {
	fi(1, n) {
		p[i] = hull(p[i]);
		dbg(p[i]);
	}
}

int main() {
#ifdef LOCAL
	freopen("g.in", "r", stdin);
	freopen("g.out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %lld", &n, &M);

	fi(1, n) {
		scanf("%d", &k[i]);
		fj(1, k[i]) {
			int x, y;
			scanf("%d %d", &x, &y);
			orig[i][Point(x, y)] = j;
			p[i].pb(Point(x, y));
		}
	}

	init();

	solve();

	exit();
	return 0;
}