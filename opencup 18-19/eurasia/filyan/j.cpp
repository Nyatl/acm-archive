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

int const MAX = 141;
int const INF = 1000 * 1000 * 1000 + 41;

int w, h;
char type[MAX][MAX][14];
bool river[MAX][MAX][MAX][MAX];
int sx, sy, ex, ey;
int M;

int dx[6] = {-1, +0, +1, +1, +0, -1};
int dy[6] = {-1, -1, +0, +1, +1, +0};

struct Edge {
	int x, y, cost;
	Edge () {};
	Edge (int x, int y, int cost) : x(x), y(y), cost(cost) {};
};

vector<Edge> e[MAX][MAX];

bool inside(int y, int x) {
	if (y < 0 || y > h) return 0;
	if (x < 0 || x > w) return 0;
	return 1;
}

bool cango(int y, int x) {
	if (!inside(y, x)) return 0;
	if (type[y][x][1] == 'm') return 0;
	return 1;
}

int getcost(int y1, int x1, int y2, int x2) {
	if (river[y1][x1][y2][x2]) return INF;
	int res = 1;
	if (type[y1][x1][1] == 'p' && type[y2][x2][1] == 'h') res++;
	if (type[y2][x2][2] == 'f' || type[y2][x2][2] == 'm') res++;
	return res;
}

void buildgraph() {
	fi(0, h - 1) {
		fj(0, w - 1) {
			fo(0, 5) {
				int ni = i + dy[o];
				int nj = j + dx[o];
				if (!cango(ni, nj)) continue;
				int cost = getcost(i, j, ni, nj);
				e[i][j].pb(Edge(nj, ni, cost));
			}
		}
	}
}

int d[MAX][MAX];
int ro[MAX][MAX];
int was[MAX][MAX];

struct State {
	int x, y, d, ro;
	State (int x, int y, int d, int ro) : x(x), y(y), d(d), ro(ro) {};
	State () {};
	bool operator<(const State &a) const {
		if (d != a.d) return d < a.d;
		if (ro != a.ro) return ro > a.ro;
		if (x != a.x) return x < a.x;
		return y < a.y;
	};
};

State from[MAX][MAX];

set<State> t;

void dijk() {
	fi(0, MAX - 1) {
		fj(0, MAX - 1) {
			d[i][j] = INF;
		}
	}	
	d[sy][sx] = 1;
	ro[sy][sx] = M;
	t.insert(State(sx, sy, 1, M));
	while (sz(t)) {
		State cur = (*t.begin());
		t.erase(t.begin());
		if (was[cur.y][cur.x]) continue;		
		was[cur.y][cur.x] = 1;
		for (auto edge : e[cur.y][cur.x]) {
			int nd = cur.d;
			int nro = cur.ro - edge.cost;
			if (nro <= 0) {
				nd++;
				nro = M;
			}
			if (d[edge.y][edge.x] > nd || (d[edge.y][edge.x] == nd && ro[edge.y][edge.x] < nro)) {
				d[edge.y][edge.x] = nd;
				ro[edge.y][edge.x] = nro;
				from[edge.y][edge.x] = cur;
				t.insert(State(edge.x, edge.y, nd, nro));
			}
		}
	}	
}

void solve() {
	buildgraph();
	dijk();
	if (!was[ey][ex]) {
		printf("They shall not pass\n");		
		return;
	}
	if (ro[ey][ex] == M) {
		d[ey][ex]--;
	}

	vector<pii> path;
	printf("Come this way\n");
	printf("%d\n", d[ey][ex]);
	int x = ex;
	int y = ey;
	while (1) {
		path.pb(mp(x, y));
		if (x == sx && y == sy) break;
		State nxt = from[y][x];
		x = nxt.x;
		y = nxt.y;
	}
	printf("%d\n", sz(path));
	fdi(sz(path) - 1, 0) {
		printf("%d %d\n", path[i].first, path[i].second);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d", &w, &h);
	fi(0, h - 1) {
		fj(0, w - 1) {
			scanf(" %[a-z]", type[i][j] + 1);
//			err("type = %s\n", type[i][j] + 1);
		}
	}	
	int q;
	scanf("%d", &q);
	fi(1, q) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		river[y1][x1][y2][x2] = river[y2][x2][y1][x1] = 1;
	}

	scanf("%d", &M);
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

	solve();

	exit();
	return 0;
}



