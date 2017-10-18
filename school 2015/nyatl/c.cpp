#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <cmath>
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
#include <cstdarg>
#include <memory.h>
#include <assert.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#ifdef DENIS
#define fi(a, b) for(int i=a; i<b; i++)
#define fj(a, b) for(int j=a; j<b; j++)
#define fo(a, b) for(int o=a; o<b; o++)
#define fdi(a, b) for(int i=a-1; i>=b; i--)
#define fdj(a, b) for(int j=a-1; j>=b; j--)
#define fdo(a, b) for(int o=a-1; o>=b; o--)
#else
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)

#endif
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()

char __buffer[100000];

void err(const char *format, ... ) {
#ifdef _DEBUG
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "%s\n", __buffer);
#endif
}

void _dbg(int x) {
	fprintf(stderr, "%d", x);
}

void _dbg(long long x) {
	fprintf(stderr, "%lld", x);
}

void _dbg(double x) {
	fprintf(stderr, "%.9lf", x);
}

void _dbg(char x) {
	fprintf(stderr, "%c", x);
}

void _dbg(vector<int> x) {
	for (int i = 0; i < sz(x); i++) {
		fprintf(stderr, "%d ", x[i]);
	}
}

void _dbg(vector<long long> x) {
	for (int i = 0; i < sz(x); i++) {
		fprintf(stderr, "%lld ", x[i]);
	}
}

void _dbg(vector<double> x) {
	for (int i = 0; i < sz(x); i++) {
		fprintf(stderr, "%.9lf ", x[i]);
	}
}

void _dbg(vector<char> x) {
	for (int i = 0; i < sz(x); i++) {
		fprintf(stderr, "%c ", x[i]);
	}
}

void _dbg0(int *x, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stderr, "%d ", x[i]);
	}
}

void _dbg0(long long *x, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stderr, "%lld ", x[i]);
	}
}

void _dbg0(double *x, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stderr, "%.9lf ", x[i]);
	}
}

void _dbg0(char *x, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stderr, "%c ", x[i]);
	}
}

void _dbg1(int *x, int n) {
	for (int i = 1; i <= n; i++) {
		fprintf(stderr, "%d ", x[i]);
	}
}

void _dbg1(long long *x, int n) {
	for (int i = 1; i <= n; i++) {
		fprintf(stderr, "%lld ", x[i]);
	}
}

void _dbg1(double *x, int n) {
	for (int i = 1; i <= n; i++) {
		fprintf(stderr, "%.9lf ", x[i]);
	}
}

void _dbg1(char *x, int n) {
	for (int i = 1; i <= n; i++) {
		fprintf(stderr, "%c ", x[i]);
	}
}

void as(bool cond) {
	if (!cond) {
		fprintf(stderr, "ASSERT!\n");
	}
	assert(cond);
}

#ifdef _DEBUG
#define dbg(x) cerr << #x << ": "; _dbg(x); cerr << endl;
#define dbg0(x, n) cerr << #x << ": "; _dbg0(x, n); cerr << endl;
#define dbg1(x, n) cerr << #x << ": "; _dbg1(x, n); cerr << endl;
#else
#define dbg(x) while (0);
#define dbg0(x, n) while (0);
#define dbg1(x, n) while (0);
#endif

typedef long long ll;

#define filename "demo"

#define MAX 101000

int n, l, r;

int b[MAX], g[MAX];
int v[MAX];

vector <pair<int, int> > ans;

int d[MAX];
int p[MAX];

int sign(int x) {
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

int ps[MAX];

int sum(int L, int R) {
	return ps[R] - ps[L - 1];
}

int sign(int l, int r) {
	return sign(sum(l, r));
}

void init() {
	fi(1, n) {
		ps[i] = ps[i - 1] + v[i];
	}
}

struct Rec {
	int d;
	int s;
	int p;
	bool operator<(const Rec &r) const {
		if (d != r.d) return d > r.d;
		if (s != r.s) return s < r.s;
		return p < r.p;
	}
	Rec (int d, int s, int p) : d(d), s(s), p(p) {}
};

set<Rec> t;

#define INF 2000000100

void solve() {

	fi(1, n) {
		d[i] = -INF;
	}

	d[0] = 0;

	fi(1, n) {
		if (i - l >= 0) {
			t.insert(Rec(d[i - l], ps[i - l], i - l));
		}
		if (i - r - 1 >= 0) {
			t.erase(Rec(d[i - r - 1], ps[i - r - 1], i - r - 1));
		}
		if (sz(t)) {
			Rec b = *t.begin();
			if (b.d + sign(ps[i] - b.s) > d[i]) {
				d[i] = b.d + sign(ps[i] - b.s);
				p[i] = b.p;
			}

			set<Rec>::iterator it = t.lower_bound(Rec(b.d - 1, -INF, -INF));
			if (it != t.end()) {
				Rec b2 = *it;
				if (b2.d + sign(ps[i] - b2.s) > d[i]) {
					d[i] = b2.d + sign(ps[i] - b2.s);
					p[i] = b2.p;
				}
			}
		}
	}

	int x = n;
	while (x >= 1) {
		int y = p[x];
		ans.pb(mp(y + 1, x));
		x = y;
	}
	
	reverse(ans.begin(), ans.end());
}

int main() {
	freopen(filename ".in", "r", stdin);
	freopen(filename ".out", "w", stdout);

	scanf("%d %d %d", &n, &l, &r);

	fi(1, n) {
		scanf("%d %d", &b[i], &g[i]);
	}	
	
	fi(1, n) {
		v[i] = b[i] - g[i];
	}

	init();

	solve();

	printf("%d\n", sz(ans));
	fi(0, sz(ans) - 1) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	
	return 0;
}