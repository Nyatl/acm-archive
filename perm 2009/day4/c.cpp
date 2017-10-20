#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <tuple>
#include <map>
#include <ctime>
#include <memory>
#include <memory.h>
#include <iomanip>
#include <functional>
#include <cassert>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define sz(a) ((int)((a).size()))
#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fo(a, b) for(int o = (a); o < (b); ++o)
#define fdi(a, b) for(int i = (int)(a) - 1; i >= (b); --i)
#define fdo(a, b) for(int o = (int)(a) - 1; o >= (b); --o)
#define fdj(a, b) for(int j = (int)(a) - 1; i >= (b); --j)
#define all(a) (a).begin(),(a).end()
#define _(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////////////////////

struct edge {
	int t;
	int e;
	edge() {}
	edge(int t, int e) : t(t), e(e) {}
};

const int N = 1005;

int col[N];

vector<edge> g[N];

void bad() {
	printf("No\n");
	exit(0);
}

void dfs(int v, int c) {
	if (col[v]) {
		if (col[v] != c) {
			bad();
		}
		return;
	}
	col[v] = c;
	fi(0, sz(g[v])) {
		dfs(g[v][i].t, c * g[v][i].e);
	}
}

void solve() {
	int n;
	int m;
	scanf("%d", &n);
	scanf("%d", &m);
	fi(0, m) {
		int f, s;
		char r;
		scanf(" %c %d %d", &r, &f, &s);
		int e = ((r == 'E') ? -1 : 1);
		g[f].push_back({ s, e });
		g[s].push_back({ f, e });
	}
	fi(1, n + 1) {
		if (!col[i]) {
			dfs(i, 1);
		}
	}
	printf("Yes\n");
}

#define FILENAME "gangs"

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif
	solve();

	return 0;
}