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

const int MAX = 200 * 1000 + 41;

int n, C, Q;

vi e[MAX];
int h[MAX];
int child[MAX];
int par[MAX];

int heavy[MAX];
int topmost[MAX];

struct Seg {
	int h1, h2, col;
	Seg () {};
	Seg (int h1, int h2, int col) : h1(h1), h2(h2), col(col) {};
	bool operator<(const Seg &a) const {
		if (h1 != a.h1) return h1 < a.h1;
		if (h2 != a.h2) return h2 < a.h2;
		return col < a.col;
	};
	int getlen() {
		int res = h2 - h1 + 1;
		if (h1 == 0) res--;
		return res;
	}
};

set<Seg> segs[MAX];

void dfs1(int x, int p = -1) {
	par[x] = p;
	child[x] = 1;
	for (int y : e[x]) {
		if (y == p) continue;
		h[y] = h[x] + 1;
		dfs1(y, x);
		child[x] += child[y];
	}
}

void dfs2(int x, int st, int p = -1) {
	topmost[x] = st;
	int b = -1;
	for (int y : e[x]) {
		if (y == p) continue;
		if (b == -1 || child[y] > child[b]) {
			b = y;
		}
	}
	if (child[b] * 2 >= child[x]) {
		heavy[x] = b;
	}
	if (heavy[x] != -1) {
		dfs2(heavy[x], st, x);
	}
	for (int y : e[x]) {
		if (y == p) continue;
		if (y == heavy[x]) continue;
		dfs2(y, y, x);
	}
}

int q[MAX];
int cnt[MAX];

void remedges(int col, int k) {
	if (col == 0) return;
	cnt[q[col]]--;
	q[col] -= k;
	cnt[q[col]]++;
}

void addedges(int col, int k) {
	if (col == 0) return;
	cnt[q[col]]--;
	q[col] += k;
	cnt[q[col]]++;
}

void remfirst(set<Seg> &t) {
	auto cur  = (*t.begin());
	remedges(cur.col, cur.getlen());
	t.erase(cur);
}

void insert(Seg s, set<Seg> &t) {
	if (s.h1 > s.h2) return;
	t.insert(s);
	addedges(s.col, s.getlen());
}

void remove(Seg s, set<Seg> &t) {
	remedges(s.col, s.getlen());
	t.erase(s);
}

Seg intersect(Seg s1, Seg s2) {
	Seg res = Seg(s1.h2 + 1, s2.h2, s2.col);
	return res;
}

void repaint(int x, int color) {
	while (x != -1) {
		int tx = topmost[x];
		Seg cur = Seg(h[tx], h[x], color);
		while (1) {
			if (!sz(segs[tx])) break;
			auto it = segs[tx].begin();
			if (it->h2 <= cur.h2) {
				remfirst(segs[tx]);
				continue;
			}
			if (it->h1 > cur.h2) {				
				break;
			}
			Seg resp = intersect(cur, *it);//order matter
			remove(*it, segs[tx]);
			insert(resp, segs[tx]);
			break;
		}
		insert(cur, segs[tx]);
		x = par[topmost[x]];
	}
}

void solve() {
	fo(1, Q) {
		int u, c, m;
		scanf("%d %d %d", &u, &c, &m);
		repaint(u, c);
		printf("%d\n", cnt[m]);
	}
	dbg0(q, C + 1);
	dbg0(cnt, C + 1);
}

void init() {
	memset(heavy, 255, sizeof(heavy));
	dfs1(1);
	dfs2(1, 1);
	fi(1, n) {
		if (i == 1) continue;
		segs[topmost[i]].insert(Seg(h[i], h[i], 0));
	}
	cnt[0] = C;
//
	dbg1(topmost, n);
	dbg1(heavy, n);
//	
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d %d", &n, &C, &Q);
	fi(1, n - 1) {
		int x, y;
		scanf("%d %d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	init();
	solve();

	exit();
	return 0;
}












