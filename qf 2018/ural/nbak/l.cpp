#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#ifndef LOCAL
typedef __int128 lll;
#else
typedef long long lll;
#endif


template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	for (T z : v) s << z << " ";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, deque<T> v) {
	for (T z : v) s << z << " ";
	return s;
}


template<typename T1, typename T2>
ostream& operator<<(ostream& s, pair<T1, T2> v) {
	s << v.first << " " << v.second;
	return s;
}

#define sz(a) (int)((a).size())
#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fj(a,b) for(int j = (a); j <= (b); ++j)
#define fo(a,b) for(int o = (a); o <= (b); ++o)
#define fdi(a,b) for(int i = (a); i >= (b); --i)
#define fdj(a,b) for(int j = (a); j >= (b); --j)
#define fdo(a,b) for(int o = (a); o >= (b); --o)
#define all(a) (a).begin(),(a).end()

#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << '\t' << #x << ":" << x << endl
#define dbg0(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=0; ABC<n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=1; ABC<=n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while(false) {}
#define dbg0(x, n) while(false) {}
#define dbg1(x, n) while(false) {}
#endif

const int MAX = 200005;

const int BLOCK1 = 42;
const int BLOCK2 = BLOCK1 * BLOCK1;

string cols = "RGB";

struct Edge {
	int u, v;
	int c;
	int num;
	Edge() {}
	Edge(int u, int v, int num) : u(u), v(v), num(num) {
		c = -1;
	}
};

int n, m;

vector<Edge *> e[MAX];

vector<Edge *> edges;

int T;
int out[MAX];

int ans[MAX];

void solve() {
	for (Edge *z : edges) {
		if (out[z->u] / BLOCK1 == out[z->v] / BLOCK1) {
			z->c = 0;
		} else if (out[z->u] / BLOCK2 == out[z->v] / BLOCK2) {
			z->c = 1;
		} else {
			z->c = 2;
		}
	}
	for (Edge *z : edges) {
		ans[z->num] = z->c;
	}
	fi(1, m) {
		printf("%c\n", cols[ans[i]]);
	}
}

int color[MAX];

void dfs(int x) {
	if (color[x]) return;
	color[x] = 1;
	for (Edge *z : e[x]) {
		dfs(z->v);
	}
	out[x] = T++;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &m);
	fi(1, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		Edge *edge = new Edge(a, b, i);
		e[a].pb(edge);
		edges.pb(edge);
	}
	fi(1, n) {
		dfs(i);
	}
	solve();
	return 0;
}