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

int const INF = 1e9 + 41;

int const N = 1e5 + 41;

struct edge {
	int f, t, c, id;
	edge() {};
	edge(int f, int t, int c, int id) : f(f), t(t), c(c), id(id) {};
};

vector<edge> e[N], et[N];
int d1[N], d2[N];

int n, m, k;
vector<int> ans;

void dijk(vector<edge> e[N], int d[N], int st) {
	set<pii> t;
	fi(0, N) d[i] = INF;
	d[st] = 0;
	t.insert(mp(0, st));
	while (sz(t)) {
		pii cur = (*t.begin());
		t.erase(cur);
		int id = cur.second;
		int di = cur.first;
		fi(0, sz(e[id])){
			int co = e[id][i].c;
			int to = e[id][i].t;
			if (d[to] > di + co) {
				t.erase(mp(d[to], to));
				d[to] = min(d[to], di + co);
				t.insert(mp(d[to], to));
			}
		}
	}
}

void solve() {
	dijk(e, d1, 0);
	dijk(et, d2, n - 1);
	fi(0, n) {
		fj(0, sz(e[i])) {
			int f = e[i][j].f;
			int t = e[i][j].t;
			int c = e[i][j].c;
			int id = e[i][j].id;
			if (d1[f] + c + d2[t] - k <= d1[n - 1]) {
				ans.pb(id);
			}
		}
	}
	sort(all(ans));
}

#define FILENAME "taxman"

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif

	scanf("%d %d %d", &n, &m, &k);
	fi(0, m) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		--u; --v;
		e[u].pb(edge(u, v, c, i));
		et[v].pb(edge(v, u, c, i));
	}

	solve();

	printf("%d\n", sz(ans));
	fi(0, sz(ans)) {
		printf("%d\n", ans[i] + 1);
	}

	return 0;
}