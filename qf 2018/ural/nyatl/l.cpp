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
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
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

#define ID "l"

#define MAX 50100

struct Edge {
	int u, v, c;
	Edge *next;
};

int n, m;

Edge *e[MAX];
vector<Edge*> edges;

void insert(int x, int v) {
	Edge *temp = new Edge;
	temp->u = x;
	temp->v = v;
	temp->c = 0;
	temp->next = e[x];
	e[x] = temp;
	edges.pb(temp);
}

int len[MAX][4];

int cur_time;
int out[MAX];
int color[MAX];

void dfs(int x) {
	if (color[x]) return;
	color[x] = 1;
	for (Edge *y=e[x]; y; y=y->next) {
		dfs(y->v);
	}
	cur_time++;
	out[x] = cur_time;
}

void dfs_verify(int x) {
	if (len[x][1] != -1) return;
	len[x][1] = 0;
	len[x][2] = 0;
	len[x][3] = 0;
	for (Edge *y=e[x]; y; y=y->next) {
		dfs_verify(y->v);
		len[x][y->c] = max(len[x][y->c], len[y->v][y->c] + 1);
	}
}

void verify() {
	memset(len, -1, sizeof(len));
	fi(1, n) {
		dfs_verify(i);
	}
	vpii res;
	fi(1, n) {
		fj(1, 3) {
			if (len[i][j] > 42) return;
		}
	}
	fi(1, m) {
		switch (edges[i - 1]->c) {
			case 1:
				printf("R\n");
				break;
			case 2:
				printf("G\n");
				break;
			case 3:
				printf("B\n");
				break;
		}
	}
	exit();
}

void solve() {
	fi(1, n) {
		dfs(i);
	}

	fz(edges) {
		int x1 = out[z->u];
		int x2 = out[z->v];
		if ((x1 - 1) / 40 == (x2 - 1) / 40) {
			z->c = 1;
		} else if ((x1 - 1) / 1600 == (x2 - 1) / 1600) {
			z->c = 2;
		} else {
			z->c = 3;
		}
	}

	verify();
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d", &n, &m);
	fi(1, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		insert(a, b);
	}

	solve();

	exit();
	return 0;
}
