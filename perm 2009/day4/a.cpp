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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////////////////////

const ll MOD = 1000000000;

const ld eps = 1e-9;

int const N = 541;
int const M = 1e5 + 41;
ld const SH = 1e9;
ld const INF = 666;

int a[N][N];
int n;
int from[M], to[M], cap[M], flow[M];
ld cost[M];
int cnte;
vector<int> e[M];
map<pii, int> h;
map<int, pii> invh;

ld getcost(ld v) {
	return 5 - log(v);
}

void push(int from, int to, ld cost) {
	e[from].pb(cnte);
	::from[cnte] = from;
	::to[cnte] = to;
	::cost[cnte] = cost;
	::cap[cnte] = 1;
	++cnte;

	e[to].pb(cnte);
	::from[cnte] = to;
	::to[cnte] = from;
	::cost[cnte] = -cost;
	::cap[cnte] = 0;
	++cnte;
}

int getid(int l, int id) {
	if (h.find(mp(l, id)) != h.end()) {
		return h[mp(l, id)];
	}
	int v = sz(h);
	h[mp(l, id)] = v;
	invh[v] = mp(l, id);
	return v;
}

int S, T;

void buildnet() {
	S = getid(0, 0);
	T = getid(3, 0);
	fi(0, n) getid(1, i);
	fi(0, n) getid(2, i);
	fi(0, n) {
		//r
		int id = getid(1, i);
		push(S, id, getcost(100));
	}

	fi(0, n) {
		//c
		int id = getid(2, i);
		push(id, T, getcost(100));
	}

	fi(0, n) fj(0, n) {
		if (a[i][j] >= 80) {
			int idi = getid(1, i);
			int idj = getid(2, j);
			push(idi, idj, getcost(a[i][j]));
		}
	}
}

ld d[N];
int by[N];

ld bellman() {
	int n = sz(h);
	fi(0, n) d[i] = INF;
	d[S] = 0;
	bool f = true;
	while (f) {
		f = false;
		fi(0, n) {
			fj(0, sz(e[i])) {
				int id = e[i][j];
				int to = ::to[id];
				ld co = ::cost[id];
				if (cap[id] > flow[id]) {
					if (d[to] > d[i] + co + eps) {
						d[to] = d[i] + co;
						by[to] = id;
						f = true;
					}
				}
			}
		}
	}

	if (d[T] >= INF) return -1;
	if (d[T] <= INF) {
		int v = T;
		while (v != S) {
			int id = by[v];
#ifdef _DEBUG
			fprintf(stderr, "from = %d to = %d flow = %d cap = %d dist = %.3lf\n",
				from[id], to[id], flow[id], cap[id], d[v]);
#endif
			flow[id] += 1;
			flow[(id ^ 1)] -= 1;
			v = from[id];
		}
	}
	return d[T];
}

struct bigint {
	vector<ll> v;
	int sh = 0;
	bigint() {};
	bigint(ll val) {
		v.pb(val);
	}
	void mul(int val) {
		ll s = 0;
		fi(0, sz(v)) {
			v[i] *= val;
		}
		fi(0, sz(v)) {
			v[i] += s;
			s = v[i] / MOD;
			v[i] %= MOD;
		}
		if (s) {
			v.push_back(s);
		}
	}
};

ll bp(ld x, int d) {
	ld r = 1;
	fi(0, d) r *= x;
	return r;
}

void solve() {
	buildnet();
#ifdef _DEBUG
	for (pair<int, pii> v : invh) {
		fprintf(stderr, "hid = %d l = %d id = %d \n", v.first, v.second.first, v.second.second);
	}
#endif

	int f = 0;
	while (true) {
		ld cur = bellman();
#ifdef _DEBUG 
		fprintf(stderr, "cur %.15lf\n", cur);
#endif
		if (cur < 0) break;
		++f;
	}
	if (f != n) {
		printf("0\n");
		return;
	}

	//ld ans = 100.;
	bigint ans(100);
	ld ansold = 100.;
	fi(0, cnte) {
		if (cap[i] == 1 && flow[i] == 1) {
			int f = from[i];
			int t = to[i];
			if (f == S || f == T) continue;
			if (t == S || t == T) continue;
			pii fp = invh[f];
			pii tp = invh[t];
			ans.mul(a[fp.second][tp.second]);
			ans.sh += 2;
			ansold *= a[fp.second][tp.second] / 100.;
		}
	}

	char s[55];
	ld top;
	if (sz(ans.v) == 1) {
		ld r = ans.v[0];
		int rem = ans.sh;
		top = r / bp(10.0, rem);

	} else {
		ld r = ans.v.back() * MOD + ans.v[sz(ans.v) - 2];
		int rem = ans.sh - (sz(ans.v) - 2) * 9;
		top = r / bp(10.0, rem);
	}
	sprintf(s, "%.15Lf", ansold);
	printf("%s\n", s);
	//printf("%.15Lf\n", ans);
}

#define FILENAME "bond2"

int getrand(int l, int r) {
	return rand() % (r - l + 1) + l;
}

int main() {
	srand(time(NULL) + clock());
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif
	n = 100;
	fi(0, n) fj(0, n) if (i != j) {
		a[i][j] = getrand(1, 100);
	}
	
	unsigned int st = clock();
	////////
	scanf("%d", &n);
	fi(0, n) fj(0, n) {
		scanf("%d", &a[i][j]);
	}
	
	solve();
	
	/////
	unsigned int en = clock();
	fprintf(stderr, "time: %.3lf\n", (en - st) * 1.0 / CLOCKS_PER_SEC);

	return 0;
}