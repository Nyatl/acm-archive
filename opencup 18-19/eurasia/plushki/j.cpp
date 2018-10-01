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
#include <unordered_map>
#include <unordered_set>

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
ostream& operator<<(ostream& s, pair<A, B> p) {
	s << "(" << p.first << ", " << p.second << ")";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	fi(0, sz(v) - 1) {
		s << v[i] << " ";
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, set<T> t) {
	for (auto z : t) {
		s << z << " ";
	}
	return s;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& s, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		s << "\t" << z.first << " -> " << z.second << endl;
	}
	return s;
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

int const MAX = 141;


int w, h;

char ty[MAX][MAX][41];


int qr;
int m;

struct Point {
	int x, y;
	Point () {};
	Point (int x, int y) : x(x), y(y) {};
	bool operator<(const Point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	};
	bool operator==(const Point &a) const {
		return x == a.x && y == a.y;
	};
};

Point st, en;

set<pair<Point, Point>> river;

int const M = MAX * MAX;
int const INF = 1e9 + 41;

vector<pair<Point, int>> e[MAX][MAX];

int dx[6] = {-1, +0, +1, +1, +0, -1};
int dy[6] = {-1, -1, +0, +1, +1, +0};

bool inside(Point p) {
	if (p.x < 0 || p.x >= w) return false;
	if (p.y < 0 || p.y >= h) return false;
	return 1;
}

bool cango(Point p) {
	if (!inside(p)) return 0;
	if (ty[p.y][p.x][1] == 'm') return 0;
	return 1;
}

int getcost(Point a, Point b) {
	if (river.count(mp(a, b))) return INF;
	int res = 1;
	if (ty[b.y][b.x][2] == 'f' || ty[b.y][b.x][2] == 'm') res++;
	if (ty[a.y][a.x][1] == 'p' && ty[b.y][b.x][1] == 'h') res++;
	return res;
}

void buildgraph() {
	fi(0, h - 1) {
		fj(0, w - 1) {
			Point me = Point(j, i);
			fo(0, 5) {
				int x1 = j + dx[o];
				int y1 = i + dy[o];
				Point to = Point(x1, y1);
				if (!cango(to)) continue;				
				int cost = getcost(me, to);
				e[i][j].pb(mp(to, cost));
			}
		}
	}
}

Point from[MAX][MAX];
int dist[MAX][MAX];
int remod[MAX][MAX];

struct State {
	Point p;
	int dist, remod;
	State () {};
	State (Point p, int dist, int remod) : p(p), dist(dist), remod(remod) {};
	bool operator<(const State &a) const {
		if (dist != a.dist) return dist < a.dist;
		if (remod != a.remod) return remod > a.remod;
		return p < a.p;
	};
};

bool u[MAX][MAX];

void dickstra() {
	fi(0, h - 1) {
		fj(0, w - 1) {
			dist[i][j] = INF;			
		}
	}
	dist[st.y][st.x] = 1;
	remod[st.y][st.x] = m;
	from[st.y][st.x] = st;

	set<State> t;
	t.insert(State(st, 1, m));
	while (sz(t)) {
		State cur = (*t.begin());
		t.erase(t.begin());
		if (u[cur.p.y][cur.p.x]) continue;

		for (auto edge : e[cur.p.y][cur.p.x]) {
			int x1 = edge.first.x;
			int y1 = edge.first.y;
			int newrem = cur.remod - edge.second;
			int newdist = cur.dist;
			if (newrem <= 0) {
				newrem = m;
				newdist++;
			}
			if (newdist < dist[y1][x1] || (newdist == dist[y1][x1] && newrem > remod[y1][x1])) {
				dist[y1][x1] = newdist;
				remod[y1][x1] = newrem;
				t.insert(State(Point(x1, y1), newdist, newrem));
				from[y1][x1] = cur.p;
			}			
		}

		u[cur.p.y][cur.p.x] = 1;
	}
}

void solve() {
	err("HELLO!\n");
	buildgraph();
	err("graph built!\n");
	dickstra();
	err("dickstra done!\n");

/*
	fi(0, h - 1) {
		fj(0, w - 1) {
			err("y = %d x = %d dist = %d rem = %d from(y, x) = %d %d\n", i, j, dist[i][j], remod[i][j], from[i][j].y, from[i][j].x);
		}
	}
*/	

	if (dist[en.y][en.x] == INF) {
		printf("They shall not pass\n");
		return;
	}
	printf("Come this way\n");
	if (remod[en.y][en.x] == m) {
		dist[en.y][en.x]--;
	}
	printf("%d\n", dist[en.y][en.x]);

	//return;

	Point cur = en;
	vector<Point> path;
	while (1) {
		path.pb(cur);
		if (cur == st) break;
		cur = from[cur.y][cur.x];
	}

	reverse(path.begin(), path.end());

	printf("%d\n", sz(path));
	for (auto z : path) {
		printf("%d %d\n", z.x, z.y);
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
			scanf(" %s", ty[i][j] + 1);
		}
	}	

	scanf("%d", &qr);
	fi(1, qr) {
		int xa, xb, ya, yb;
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		river.insert(mp(Point(xa, ya), Point(xb, yb)));
		river.insert(mp(Point(xb, yb), Point(xa, ya)));
	}
	scanf("%d", &m);

	scanf("%d %d %d %d", &st.x, &st.y, &en.x, &en.y);

	solve();

	exit();
	return 0;
}
