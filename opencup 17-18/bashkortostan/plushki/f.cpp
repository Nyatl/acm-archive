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

const int MAX = 10000 + 5;

int n, m;

vi e[MAX];

int C;

int color[MAX];

void dfs(int x) {
	if (color[x] != 0) {
		return;
	}
	color[x] = C;
	for (int z : e[x]) {
		dfs(z);
	}
}

vi comps[MAX];

int f[MAX];

int dfs2(int x) {
	if (f[x]) return 1;
	f[x] = 1;
	int cntG = 0;
	for (int z : e[x]) {
		if (sz(e[z]) > 1) {
			cntG++;
		}
	}
	if (sz(e[x]) == 3) {
		if (cntG > 1) {
			return 0;
		}
	} else if (sz(e[x]) == 4) {
		if (cntG > 2) {
			return 0;
		}
	}
	for (int z : e[x]) {
		if (sz(e[z]) > 1) {
			int r = dfs2(z);
			if (r == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int check(int x) {
	int cnt = sz(comps[x]);
	if (cnt < 4) {
		return 0;
	}
	if (cnt % 3 != 1) return 0;
	int cnt1 = 0;
	int cnt3 = 0;
	int cnt4 = 0;
	fi (0, cnt - 1) {
		int cntloc = sz(e[comps[x][i]]);
		if (cntloc == 1) {
			cnt1++;
		} else if (cntloc == 3) {
			cnt3++;
		} else if (cntloc == 4) {
			cnt4++;
		} else {
			return 0;
		}
	}
	if (cnt3 != 1) {
		return 0;
	}
	if (cnt4 != (cnt - 4) / 3) {
		return 0;
	}
	fi (0, cnt - 1) {
		if (sz(e[comps[x][i]]) == 3) {
			int r = dfs2(comps[x][i]);
			if (r == 0) {
				return 0;
			}
		}
	}
	return 1;
}

void solve() {
	scanf("%d %d", &n, &m);
	fi(1, m) {
		int x, y;
		scanf("%d %d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	fi(1, n) {
		if (color[i]) continue;
		C++;
		dfs(i);
	}
	fi(1, n) {
		comps[color[i]].pb(i);
	}
	int ans = 0;
	fi(1, C) {
		ans += check(i);
	}
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
