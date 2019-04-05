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
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(auto i=a; i<=b; i++)
#define fj(a, b) for(auto j=a; j<=b; j++)
#define fo(a, b) for(auto o=a; o<=b; o++)
#define fy(a) for(auto &y : a)
#define fz(a) for(auto &z : a)
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

#ifdef LOCAL
void err(const char *format, ... ) {
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s", __buffer);
}
#else
#define err(...) {}
#endif

#ifdef LOCAL
void errln(const char *format, ... ) {
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s\n", __buffer);
}
#else
#define errln(...) {}
#endif

#ifdef LOCAL
void errln() {
	fprintf(stderr, "\n");
}
#endif

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
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#else
#define dbg(x) {}
#define dbg0(x, n) {}
#define dbg1(x, n) {}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

const int MAX = 500005;

int n, m;

vi e[MAX];
int deg[MAX];
vpii ans;

int color[MAX];
int C;

int circle[MAX];

void dfs(int x) {
	if (color[x]) return;
	color[x] = C;
	for (int y : e[x]) {
		dfs(y);
	}
}

int f[MAX];

bool dfs1(int x, int p = -1) {
	if (f[x] == 1) return true;
	if (f[x] == 2) return false;
	f[x] = 1;
	bool res = false;
	for (int y : e[x]) {
		if (y == p) continue;
		res |= dfs1(y, x);
	}
	f[x] = 2;
	return res;
}

int del[MAX];

void solve() {
	fi(1, n) {
		if (color[i]) continue;
		C++;
		dfs(i);
	}
	
	fi(1, n) {
		if (f[i]) continue;
		if (dfs1(i)) {
			circle[color[i]] = 1;
		}
	}
	
	// trees
	fi(1, n) {
		if (circle[color[i]]) continue;
		if (sz(e[i]) == 1) {
			ans.pb(mp(i, e[i][0]));
		}
	}
	dbg1(circle, C);
	dbg1(color, n);
	// !trees
	queue<int> qu;
	
	fi(1, n) {
		deg[i] = sz(e[i]);
	}
	
	fi(1, n) {
		if (circle[color[i]]) {
			if (sz(e[i]) == 1) {
				qu.push(i);
			}
		}
	}
	
	while (sz(qu)) {
		int t = qu.front();
		qu.pop();
		if (del[t]) continue;
		if (deg[t] != 1) continue;
		dbg(t);
		del[t] = true;
		for (int y : e[t]) {
			if (del[y]) continue;
			
			deg[y]--;
			qu.push(y);
		}
	}
	dbg1(deg, n);
	dbg1(del, n);
	fi(1, n) {
		if (circle[color[i]]) {
			if (!del[i]) {
				for (int y : e[i]) {
					if (del[y]) {
						ans.pb(mp(i, y));
					}
				}
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
	scanf("%d %d", &n, &m);
	fi(1, m) {
		int u, v;
		scanf("%d %d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}

	solve();
	
	printf("%d\n", sz(ans));
	sort(all(ans));
	for (pii& z : ans) {
		printf("%d %d\n", z.first, z.second);
	}
	exit();
	return 0;
}
