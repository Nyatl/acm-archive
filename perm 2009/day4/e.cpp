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
ll gcd(ll f, ll s) {
	if (f == 0) {
		return s;
	}
	return gcd(s % f, f);
}

ll lcm(ll f, ll s) {
	return f * s / gcd(f, s);
}

const int N = 10005;
const ll INF = 1e18;

struct edge {
	int t;
	int id;
	ll T;
	edge() {}
	edge(int t, int id, ll T) : t(t), id(id), T(T) {}
	edge(int t, int id, int T1, int T2) : t(t), id(id) {
		T = lcm(T1, T2);
	}
};

ll getNxtT(ll cT, ll pT) {
	return ((cT + pT) / pT) * pT;
}

int n, m;
vector<edge> e[N];

ll d[N];
vector<int> ans;
int by[N];
int from[N];
int w[N];

void dijk() {
	priority_queue<pll> t;
	fi(0, N) d[i] = INF;
	d[0] = 0;
	t.push(mp(0, 0));
	while (sz(t)) {
		pll cur = t.top();
		t.pop();
		int id = cur.second;
		if (w[id]) continue;
		w[id] = 1;
		ll di = -cur.first;
		fi(0, sz(e[id])) {
			int to = e[id][i].t;
			ll ndi = getNxtT(di, e[id][i].T);
			if (d[to] > ndi) {
				d[to] = ndi;
				by[to] = e[id][i].id;
				from[to] = id;
				t.push(mp(-d[to], to));
			}
		}
	}
	int v = n - 1;
	while (v != 0) {
		int id = by[v];
		ans.pb(id);
		v = from[v];
	}
}

void solve() {
	scanf("%d", &n);
	scanf("%d", &m);
	fi(1, m + 1) {
		int r1, t1, r2, t2;
		scanf("%d%d%d%d", &r1, &t1, &r2, &t2);
		r1--;
		r2--;
		e[r1].push_back({ r2, i, t1, t2 });
		e[r2].push_back({ r1, i, t1, t2 });
	}
	dijk();
	printf("%lld.5\n", d[n - 1]);
	fdi(sz(ans), 0) {
		printf("%d ", ans[i]);
	}
}

#define FILENAME "pyramid"

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