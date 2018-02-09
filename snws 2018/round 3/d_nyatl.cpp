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

template<typename A, typename B>
ostream& operator<<(ostream& s, pair<A, B> p) {
	cerr << "(" << p.first << ", " << p.second << ")";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	fi(0, sz(v) - 1) {
		cerr << v[i] << " ";
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, set<T> t) {
	for (auto z : t) {
		cerr << z << " ";
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl;
#define dbg0(x, n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << ' '; cerr << endl;
#define dbg1(x, n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << ' '; cerr << endl;
#define ass(x) cerr << __LINE__ << " assertion failed: " << #x << endl, assert(0);
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#define ass(x) assert(x)
#endif

int n;
int  O, L;

#define MAX 200100

struct Edge {
	int v;
	Edge *next;
};

Edge *e[MAX];
Edge *e2[MAX];

void insert(int x, int v) {
	Edge *tmp, *tmp2;
	tmp = new Edge;
	tmp->v = v;
	tmp->next = e[x];
	e[x] = tmp;
	
	tmp2 = new Edge;
	tmp2->v = x;
	tmp2->next = e2[v];
	e2[v] = tmp2;
}

int del[MAX];

int color[MAX];
int C;

void dfs0(int x) {
	if (color[x]) return;
	del[x] = 1;
	color[x] = 1;	
	for (Edge *y = e2[x]; y; y=y->next) {
		dfs0(y->v);
	}
}

vi v;

void dfs(int x) {
	if (del[x]) return;
	if (color[x]) return;
	color[x] = 1;	
	for (Edge *y = e[x]; y; y=y->next) {
		dfs(y->v);
	}
	v.pb(x);
}

void dfs2(int x) {
	if (del[x]) return;
	if (color[x]) return;
	color[x] = C;	
	for (Edge *y = e2[x]; y; y=y->next) {
		dfs2(y->v);
	}
}

int ans;

int f[MAX];
int deg[MAX];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d %d", &n, &O, &L);
	fi(1, L) {
		int a, b;
		scanf("%d %d", &a, &b);
		a++;
		b++;
		insert(a, b);
	}
	
	fi(1, O) {
		int x;
		scanf("%d", &x);
		x++;
		f[x] = 1;
		dfs0(x);
	}
	
	dbg1(del, n);
	
	clr(color);
	
	fi(1, n) {
		dfs(i);
	}
	
	reverse(all(v));
	
	clr(color);
	
	fi(0, sz(v) - 1) {
		if (del[v[i]]) continue;
		if (color[v[i]]) continue;
		C++;
		dfs2(v[i]);
	}
	
	dbg1(color, n);
	
	fi(1, n) {
		if (del[i] && !f[i]) ans++;
	}
	
	fi(1, n) {
		if (del[i]) continue;
		for (Edge *y = e[i]; y; y=y->next) {
			if (del[y->v]) continue;
			if (color[i] == color[y->v]) continue;
			deg[color[y->v]]++;
		}
	}

	dbg1(deg, C);
		
	fi(1, C) {
		if (deg[i] == 0) ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
