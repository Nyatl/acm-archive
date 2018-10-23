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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(auto i=a; i<=b; i++)
#define fj(a, b) for(auto j=a; j<=b; j++)
#define fo(a, b) for(auto o=a; o<=b; o++)
#define fdi(a, b) for(auto i=a; i>=b; i--)
#define fdj(a, b) for(auto j=a; j>=b; j--)
#define fdo(a, b) for(auto o=a; o>=b; o--)
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

#define ID "a"

#define MAX 201000

int n, C, Q;
vi e[MAX];
int sum[MAX];
int in[MAX];
int link[MAX];
stack<pii> st[MAX];

int par[MAX];
int cnt[MAX];
int color[MAX];
int ans[MAX];

void recalc(int old_color, int new_color, int q = 1) {
	errln("%d -> %d (%d)", old_color, new_color, q);
	if (old_color != 0) {
		ans[cnt[old_color]]--;
		cnt[old_color] -= q;
		ans[cnt[old_color]]++;
	}
	ans[cnt[new_color]]--;
	cnt[new_color] += q;
	ans[cnt[new_color]]++;
}

void recolor(stack<pii> &st, int x, int c) {
	int last = 0;
	while (sz(st) && st.top().first <= x) {
		recalc(st.top().second, c, st.top().first - last);
		last = st.top().first;
		st.pop();
	}
	if (x != last) {
		if (!sz(st)) {
			recalc(0, c, x - last);
		} else {
			recalc(st.top().second, c, x - last);
		}
	}
	st.push(mp(x, c));
}

void recolor(int x, int c) {
	recalc(color[x], c);
	color[x] = c;	
}

void process(int x, int c) {
	while (1) {
		int x2 = link[x];
		if (x != x2) {
			recolor(st[x2], in[x] - in[x2], c);
			x = x2;
		} else if (par[x] != -1) {
			recolor(x, c);
			x = par[x];
		} else {
			break;
		}
	}
}

int dfs(int x, int p = -1) {
	sum[x]++;
	par[x] = p;
	for (auto y : e[x]) {
		if (y == p) continue;
		sum[x] += dfs(y, x);
	}
	return sum[x];
}

int cur;

void dfs2(int x, int p = -1) {
	int fst = 1;
	cur++;
	in[x] = cur;
	for (auto y : e[x]) {
		if (y == p) continue;
		if (fst) {
			link[y] = link[x];
		} else {
			link[y] = y;
		}
		fst = 0;
		dfs2(y, x);
	}
}

void init() {
	dfs(1);
	fi(1, n) {
		sort(all(e[i]), [](int a, int b) {
			return sum[a] > sum[b];
		});
	}
	link[1] = 1;
	dfs2(1);

	ans[0] = C;
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d %d", &n, &C, &Q);

	fi(1, n - 1) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].pb(b);
		e[b].pb(a);
	}

	init();

	fi(1, Q) {
		int x, c, req;
		scanf("%d %d %d", &x, &c, &req);
		process(x, c);
		printf("%d\n", ans[req]);
	}

	exit();
	return 0;
}