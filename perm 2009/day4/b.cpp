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

int const N = 1e5 + 41;

int n, m;
vector<int> e[N];
int d[N][2];
int ans;

void dfs(int u, int p) {
	fi(0, sz(e[u])) {
		int to = e[u][i];
		if (to == p) continue;
		dfs(to, u);
	}
	fi(0, sz(e[u])) {
		int to = e[u][i];
		if (to == p) continue;
		d[u][0] += d[to][1];
		d[u][1] += min(d[to][1], d[to][0]);
	}
	d[u][1] += 1;
}

void solve() {
	dfs(0, -1);
	ans = min(d[0][1], d[0][0]);
}

#define FILENAME "control"

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif
	scanf("%d", &n);
	fi(0, n) {
		int k;
		scanf("%d", &k);
		fj(0, k) {
			int u;
			scanf("%d", &u);
			--u;
			if (i < u) {
				e[u].pb(i);
				e[i].pb(u);
			}
		}
	}

	solve();

	printf("%d\n", ans);

	return 0;
}