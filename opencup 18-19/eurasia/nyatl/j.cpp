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

#define INF 1000000000
#define MAX 150

int n, m;

char relief[MAX][MAX];
char cover[MAX][MAX];

int k;

int rx1[100100], ry1[100100], rx2[100100], ry2[100100];

int E;

int sx, sy, fx, fy;

pii d[MAX][MAX];
pii p[MAX][MAX];
int color[MAX][MAX];

set <tuple<int, int, int, int> > rivers;

bool inside(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {-1, -1, 0, 1, 1, 0};
int dy[] = {0, -1, -1, 0, 1, 1};

int get_cost(int x, int y, int x2, int y2) {
	if (rivers.count(make_tuple(x, y, x2, y2))) {
		return 1000000;
	}
	int res = 1;
	if (relief[y][x] == 'p' && relief[y2][x2] == 'h') res++;
	if (cover[y2][x2] == 'f' || cover[y2][x2] == 'm') res++;
	return res;
}

void dijkstra() {
	set<pair<pii, pii> > t;
	fill_n(&d[0][0], MAX * MAX, mp(INF, INF));
	d[sy][sx] = mp(1, 0);
	p[sy][sx] = mp(-1, -1);	
	t.insert(mp(d[sy][sx], mp(sx, sy)));
	while (sz(t)) {
		pii g = t.begin()->second;
		int x = g.first;
		int y = g.second;
		t.erase(t.begin());
		if (color[y][x]) continue;
		color[y][x] = 1;
		int round = d[y][x].first;
		int energy = d[y][x].second;
		if (energy >= E) {
			round++;
			energy = 0;
		}
		fi(0, 5) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (!inside(x2, y2)) continue;
			if (relief[y2][x2] == 'm') continue;
			int energy2 = energy + get_cost(x, y, x2, y2);
			if (mp(round, energy2) < d[y2][x2]) {
				d[y2][x2] = mp(round, energy2);
				p[y2][x2] = mp(x, y);
				t.insert(mp(d[y2][x2], mp(x2, y2)));
			}
		}
	}

	if (d[fy][fx] == mp(INF, INF)) {
		printf("They shall not pass\n");
		return;
	}

	printf("Come this way\n");
	printf("%d\n", d[fy][fx].first);
	vpii ans;
	int x = fx;
	int y = fy;
	while (x >= 0 && y >= 0) {
		ans.pb(mp(x, y));
		int x2 = p[y][x].first;
		int y2 = p[y][x].second;
		x = x2;
		y = y2;
	}
	reverse(all(ans));
	printf("%d\n", sz(ans));
	fi(0, sz(ans) - 1) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}

void solve() {
	dijkstra();
}

void init() {
	fi(1, k) {
		rivers.insert(make_tuple(rx1[i], ry1[i], rx2[i], ry2[i]));
		rivers.insert(make_tuple(rx2[i], ry2[i], rx1[i], ry1[i]));
	}
}

int main() {
#ifdef LOCAL
	freopen("j.in", "r", stdin);
	freopen("j.out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d", &n, &m);
	fj(0, m - 1) {
		fi(0, n - 1) {
			scanf(" %c%c", &relief[j][i], &cover[j][i]);
		}
	}

	scanf("%d", &k);
	fi(1, k) {
		scanf("%d %d %d %d", &rx1[i], &ry1[i], &rx2[i], &ry2[i]);
	}

	scanf("%d", &E);

	scanf("%d %d %d %d", &sx, &sy, &fx, &fy);

	init();
	solve();

	exit();
	return 0;
}