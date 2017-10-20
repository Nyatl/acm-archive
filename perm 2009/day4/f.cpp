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

int const N = 1e3 + 41;
int const MOD = 2520;
int const INF = 1e9 + 41;

deque<pii> deq;

int d[N][MOD];
int a[N], b[N];
int n;
int ans;

bool can(int id, int t) {
	if (id == 0 || id == n + 1) return true;
	int cnt = t / (a[id] + b[id]);
	t -= cnt * (a[id] + b[id]);
	if (t == 0) return false;
	if (t <= a[id]) return true;
	else return false;
}

void solve() {
	fi(0, N) fj(0, MOD) d[i][j] = INF;
	d[0][0] = 0;

	deq.pb(mp(0, 0));
	while (sz(deq)) {
		pii cur = deq.front();
		deq.pop_front();
		int id = cur.first;
		int mo = cur.second;
		int di = d[id][mo];
		fi(-5, 6) {
			int to = id + i;
			if (to >= 0 && to <= n + 1) {
				if (can(to, di + 1)) {
					int ndi = (di + 1) % MOD;
					if (d[to][ndi] == INF) {
						d[to][ndi] = di + 1;
						deq.pb(mp(to, ndi));
					}
				}
			}
		}
	}

	ans = INF;
	fi(0, MOD) {
		ans = min(ans, d[n + 1][i]);
	}
	if (ans == INF) {
		printf("No\n");
	} else {
		printf("%d\n", ans);
	}
}

#define FILENAME "river"

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif

	scanf("%d", &n);
	fi(1, n+1) {
		scanf("%d %d", &a[i], &b[i]);
	}

	solve();

	return 0;
}