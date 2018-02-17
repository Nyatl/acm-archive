#define _CRT_SECURE_NO_DEPRECATE

#define y1 y1_______

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

#undef y1

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

const int INF = 1000 * 1000 * 1000;

int n, m;
int x1, y1;
int x2, y2;

int simple(int x1, int y1, int x2, int y2) {
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	if (dx > dy) swap(dx, dy);
	if (dx * 2 >= dy) {
		int dist = dx + dy;
		if (dist % 3 == 0) {
			return dist / 3;
		} else {
			return INF;
		}
	}
	int res = dx;
	dy -= 2 * dx;
	if (dy % 4 != 0) {
		return INF;
	}
	res += dy / 2;
	return res;
}

bool inside(int x, int y) {
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= n) return false;
	if (y >= m) return false;
	return true;
}

int dx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int dy[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

int getdist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int calc() {
	map<pii, int> dist;
	set<pii> cur, nxt;
	nxt.insert(mp(x2, y2));
	fi(0, 200) {
		cur = nxt;
		nxt.clear();
		for (pii p : cur) {
			if (getdist(p, mp(x2, y2)) > 20) continue;
			if (dist.find(p) != dist.end()) continue;
			dist[p] = i;
		}
		
		for (pii p : cur) {
			if (getdist(p, mp(x2, y2)) > 20) continue;
			fi(0, 7) {
				pii y = mp(p.first + dx[i], p.second + dy[i]);
				if (dist.find(y) == dist.end() && inside(y.first, y.second)) nxt.insert(y);
			}
		}
	}
	dbg(dist);
	
	int ans = INF;
	for (auto z : dist) {
		int tmp1 = z.second;
		int tmp2 = simple(x1, y1, z.first.first, z.first.second);
		int tmp = tmp1 + tmp2;
		ans = min(ans, tmp);
		
		if (tmp == 5) {
			err("(%d;%d)->(%d;%d):%d\n", x1, y1, z.first.first, z.first.second, tmp2);
			err("(%d;%d)->(%d;%d):%d\n", z.first.first, z.first.second, x2, y2, tmp1);
			err("-------------------------\n");
		}
	}
	
	return ans;
	
} 

void solve() {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);
	
	int ans = calc();
	swap(x1, y1);
	swap(x2, y2);
	ans = min(ans, calc());
	
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	solve();
	exit();
	return 0;
}
