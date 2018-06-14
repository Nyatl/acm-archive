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

#define MAX 1010
#define INF 1000000000

int n, m;

char field[MAX][MAX];

int sx, sy;
int fx, fy;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int color[MAX][MAX];
int d[MAX][MAX];

bool inside(int x, int y) {
	if (x < 1 || x > n) return false;
	if (y < 1 || y > m) return false;
	return true;
}

int mem_get_dist[MAX][MAX][4];

int get_dist(int x, int y, int dir) {
	if (mem_get_dist[x][y][dir] != -1) return mem_get_dist[x][y][dir];	
	int res;
	int x2 = x + dx[dir];
	int y2 = y + dy[dir];
	
	if (!inside(x2, y2)) return 1;
	
	if (field[y2][x2] == '#') {
		res = 1 + get_dist(x2, y2, dir);
	} else {
		res = 1;
	}	
	
	return mem_get_dist[x][y][dir] = res;
}

void solve() {
	set<pair<int, pii>> t;
	fill_n((int*)d, MAX * MAX, INF);
	memset(mem_get_dist, -1, sizeof(mem_get_dist));
	t.insert(mp(0, mp(sx, sy)));
	d[sy][sx] = 0;	
	while (sz(t)) {
		pii p = t.begin()->second;
		int x = p.first;
		int y = p.second;
		if (x == fx && y == fy) {
			printf("%d\n", d[y][x]);
			exit();
		}
		t.erase(t.begin());
		if (color[y][x]) continue;
		fi(0, 3) {
			int dist = get_dist(x, y, i);
			int x2 = x + dx[i] * dist;
			int y2 = y + dy[i] * dist;
			
			if (!inside(x2, y2)) continue;
			if (field[y2][x2] != '.') continue;
			
			if (d[y2][x2] > d[y][x] + dist) {
				d[y2][x2] = d[y][x] + dist;
				t.insert(mp(d[y2][x2], mp(x2, y2))); 
			}
			
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d", &m, &n);
	fj(1, m) {
		scanf("%s", field[j] + 1);
	}
	
	fj(1, m) {
		fi(1, n) {
			if (field[j][i] == 'S') {
				field[j][i] = '.';
				sx = i;
				sy = j;
			}
			if (field[j][i] == 'K') {
				field[j][i] = '.';
				fx = i;
				fy = j;
			}
		}
	}
	
	solve();

	printf("-1\n");
	
	exit();
	return 0;
}
