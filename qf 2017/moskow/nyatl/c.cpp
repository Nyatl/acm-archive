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

typedef long long ll;

#define MAX 100100

int n;

vector<int> e[MAX];

vector<int> p[25];
pair<int, int> ans[MAX];

int d[MAX];

int dfs(int x, int p) {
	int res = 1;
	fi(0, sz(e[x]) - 1) {
		int y = e[x][i];
		if (y == p) continue;
		res += dfs(y, x);
	}
	return d[x] = res;
}

void dfs2(int x, int depth, int prev = -1) {
	assert(depth <= 20);
	int b = -1;
	int bv = -1;
	p[depth].pb(x);
	fi(0, sz(e[x]) - 1) {
		int y = e[x][i];
		if (y == prev) continue;
		if (d[y] > bv) {
			bv = d[y];
			b = y;
		}
	}

	if (b != -1) {
		fi(0, sz(e[x]) - 1) {
			int y = e[x][i];
			if (y == prev) continue;
			if (y != b) {
				dfs2(y, depth + 1, x);
			}
		}
		fi(0, sz(e[x]) - 1) {
			int y = e[x][i];
			if (y == prev) continue;
			if (y == b) {
				dfs2(y, depth, x);
			}
		}
	}
}

void solve() {
	dfs2(1, 1);
}

void init() {
	dfs(1, -1);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	fi(1, n - 1) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].pb(b);
		e[b].pb(a);
	}

	init();
	solve();

	fi(1, 20) {
		fj(0, sz(p[i]) - 1) {
			ans[p[i][j]] = mp(j + 1, i);
		}
	}

	fi(1, n) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}
