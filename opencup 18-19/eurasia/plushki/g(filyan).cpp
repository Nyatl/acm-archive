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

///////////////////////////////////////////////////

typedef long double ld;

int const MAX = 100 * 1000 + 41;

int n, m;

struct Point {
	ll x, y;//x - mass, y - cost
	int id;
	Point () {};
	Point (ll x, ll y, int id = 0) : x(x), y(y), id(id) {};
	Point operator-(const Point &a) const {
		return Point(x - a.x, y - a.y);
	};
	ll operator*(const Point &a) const {
		return x * a.y - y * a.x;
	};
	bool operator<(const Point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	};
};

vector<Point> points[MAX];

void prepare() {
	fi(1, n) {
		sort(points[i].begin(), points[i].end());
		vector<Point> tmp = points[i];
		points[i].clear();
		for (auto z : tmp) {
			if (!sz(points[i]) || z.y < points[i].back().y) {
				points[i].pb(z);
			}
		}
	}
	fi(1, n) {
		vector<Point> tmp = points[i];
		points[i].clear();
		for (auto z : tmp) {
			while (sz(points[i]) > 1) {
				Point v1 = points[i][sz(points[i]) - 1] - z;
				Point v2 = points[i][sz(points[i]) - 2] - z;
				if (v1 * v2 >= 0) {
					points[i].pop_back();
				} else {
					break;
				}
			}
			points[i].pb(z);
		}
	}
}

int A[MAX];
int B[MAX];
int X[MAX];
int Y[MAX];

void refreshanswer(int id, int a, int b = -1, int x = -1, int y = -1) {
	A[id] = a;
	B[id] = b;
	X[id] = x;
	Y[id] = y;
}

struct State {
	Point v;
	int id, pt;
	State () {};
	State (Point v, int id, int pt) : v(v), id(id), pt(pt) {};
	bool operator<(const State &a) const {
		if (v * a.v != 0) return (v * a.v > 0);
		if (id != a.id) return id < a.id;
		return (pt < a.pt);
	};
};

void solve() {
	prepare();	

	fi(1, n) {
		ass(sz(points[i]));
		refreshanswer(i, points[i][0].id);
	}	
	
	set<State> states;
	fi(1, n) {
		if (sz(points[i]) > 1) {
			states.insert(State(points[i][0] - points[i][1], i, 1));			
		}
	}
	
	int rem = m;
	ld sum = 0;
	fi(1, n) {
		rem -= points[i][0].x;
		ass(rem >= 0);
		sum += points[i][0].y;
	}

	while (sz(states)) {
		auto x = (*states.begin());
		states.erase(states.begin());
		if (!rem) break;
		if (rem >= abs(x.v.x)) {
			rem += x.v.x;
			sum -= x.v.y;
			refreshanswer(x.id, points[x.id][x.pt].id);
			if (x.pt + 1 < sz(points[x.id])) {
				states.insert(State(points[x.id][x.pt] - points[x.id][x.pt + 1], x.id, x.pt + 1));			}
		} else {
			refreshanswer(x.id, points[x.id][x.pt - 1].id, points[x.id][x.pt].id, abs(x.v.x) - rem, abs(x.v.x));
			ld k = (ld) rem / abs(x.v.x);
			sum -= k * x.v.y;
			rem = 0;
		}
	}

	printf("%.15Lf\n", (ld) sum);
	fi(1, n) {
		if (B[i] == -1) {
			printf("%d %d\n", 1, A[i]);
		} else {
			printf("%d %d %d %d %d\n", 2, A[i], B[i], X[i], Y[i]);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

  scanf("%d %d", &n, &m);
  fi(1, n) {
  	int k;
  	scanf("%d", &k);
  	fo(1, k) {
			Point p;
			p.id = o;
			scanf("%lld %lld", &p.x, &p.y);
			points[i].pb(p);
  	}
  }
	solve();

	exit();
	return 0;
}



