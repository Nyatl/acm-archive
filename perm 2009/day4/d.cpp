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

int const N = 20;
int const INF = 1e9 + 41;

int d[(1 << N)];

int c[N][N];
int n, m, ans;

bool bit(int mask, int id) {
	return (mask & (1 << id));
}

void solve() {
	fi(0, (1 << n)) d[i] = -INF;
	d[0] = 0;
	fi(0, (1 << n)) {
		if (d[i] == -INF) continue;
		fj(0, n) {
			if (!bit(i, j)) {
				fo(j + 1, n) {
					if (!bit(i, o)) {
						if (c[o][j] != 0) {
							int ni = (i ^ (1 << j));
							ni ^= (1 << o);
							d[ni] = max(d[ni], d[i] + c[o][j]);
						}
					}
				}
			}
		}
	}
	ans = d[(1 << n) - 1];
	if (ans == -INF) ans = 0;
}

#define FILENAME "psycho"

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d", &m);
	fi(0, m) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		--u;
		--v;
		::c[u][v] = ::c[v][u] = c;
	}

	solve();

	printf("%d\n", ans);

	return 0;
}