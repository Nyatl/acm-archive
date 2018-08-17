#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define sz(x) (int)x.size()
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define mp make_pair
#define pb push_back

template<typename T>
ostream& operator<<(const ostream& os, const vector<T> &v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 0; ABC < n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 1; ABC <= n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x) while(0){}
#define dbg1(x) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "coins"

#define MAX 20

int n = 12;
int m;

struct Edge {
	int u, v;
	int w;
};

vi e[MAX];
int deg0[MAX];
int deg[MAX];
int num[MAX][MAX];
Edge edge[100];

int get_count(int w) {
	int res = 0;
	while (w) {
		w /= 2;
		res++;
	}
	return res;
}

void add(int x, int y, int w) {
	e[x].pb(y);
	e[y].pb(x);
	m++;
	edge[m].u = x;
	edge[m].v = y;
	edge[m].w = w;
	deg[x] += get_count(w);
	deg[y] += get_count(w);
	num[x][y] = m;
	num[y][x] = m;
}

int del[MAX][MAX];
int color[MAX];

int dq0;
int dq1;
ll W;

void dfs(int x) {
	if (color[x]) return;
	color[x] = 1;
	if (deg[x] % 2 == 1) dq1++;
	fi(0, sz(e[x]) - 1) {
		int y = e[x][i];
		if (edge[num[x][y]].w - del[x][y] <= 0) continue;
		W -= del[x][y];
		W += edge[num[x][y]].w;
		dfs(y);
	}
}

ll ans = 0;
int mask = 0;

void print() {
#ifndef LOCAL
	return;
#endif
	fi(1, n) {
		dbg(deg[i]);
	}
}

void check() {
	clr(color);
	fi(1, n) {
		if (color[i]) continue;
		dq0 = 0;
		dq1 = 0;
		W = 0;
		dfs(i);
		if (dq1 == 2 || dq1 == 0) {
			ans = max(ans, W / 2);
		}
	}
}

void solve() {
	cpy(deg0, deg);
	fi(0, (1 << m) - 1) {
		mask = i;
		int f = 1;
		cpy(deg, deg0);
		clr(del);
		fj(1, m) {
			if ((1 << (j - 1)) & i) {
				if (edge[j].w == 0) {
					f = 0;
					break;
				}
				del[edge[j].u][edge[j].v] = 1;
				del[edge[j].v][edge[j].u] = 1;
				deg[edge[j].v]--;
				deg[edge[j].u]--;
			}
		}
		if (!f) continue;
		//print();
		check();
	}
}

int read() {
	int res;
	scanf("%d", &res);
	return res;
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	
	add(1, 2, read());
	add(2, 3, read());
	add(3, 4, read());

	add(1, 5, read());
	add(2, 6, read());
	add(3, 7, read());
	add(4, 8, read());

	add(5, 6, read());
	add(6, 7, read());
	add(7, 8, read());

	add(5, 9, read());
	add(6, 10, read());
	add(7, 11, read());
	add(8, 12, read());

	add(9, 10, read());
	add(10, 11, read());
	add(11, 12, read());

	solve();

	printf("%lld\n", ans);
	return 0;
}