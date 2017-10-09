#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <map>
#ifndef _DEBUG
#include <unordered_map>
#endif
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

#define filename "robot"

#define MAX 1010
#define MAXT 100100

int n;
int m;
char str[MAXT];
char matr[MAX][MAX];
int k;
pair<int, int> r[400];

int sx, sy;
int fx, fy;

int dx[256];
int dy[256];

void init() {
	dx['L'] = -1;
	dx['R'] = 1;
	dy['U'] = -1;
	dy['D'] = 1;
	fj(1, n) {
		fi(1, n) {
			if (matr[j][i] == '#') {
				k++;
				r[k].first = i;
				r[k].second = j;
			}
			if (matr[j][i] == '@') {
				sx = i;
				sy = j;
			}
		}
	}
	
	int x = sx;
	int y = sy;
	
	fi(1, m) {
		x += dx[str[i]];
		y += dy[str[i]];
	}
	fx = x;
	fy = y;
}

int R[MAXT];

bool inside(int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= n;
}

void solve() {
	fi(1, m) {
		R[i] = m;
	}
	
	int x = sx;
	int y = sy;

	int c = 1;

	int rx = fx;
	int ry = fy;

	int X1 = 0 + (fx - sx);
	int X2 = n + 1 + (fx - sx);
	int Y1 = 0 + (fy - sy);
	int Y2 = n + 1 + (fy - sy);

#ifndef _DEBUG
	unordered_map<int, int> xd;
	unordered_map<int, int> yd;
	unordered_map<int, int> d;
#else
	map<int, int> xd;
	map<int, int> yd;
	map<int, int> d;
#endif

	fdi(m, 1) {
			
		X1 -= dx[str[i]];
		Y1 -= dy[str[i]];
		X2 -= dx[str[i]];
		Y2 -= dy[str[i]];

		xd[rx] = i;
		yd[ry] = i;

		if (xd.find(X1) != xd.end()) {
			R[i] = min(R[i], xd[X1] - 1);
		}

		if (xd.find(X2) != xd.end()) {
			R[i] = min(R[i], xd[X2] - 1);
		}

		if (yd.find(Y1) != yd.end()) {
			R[i] = min(R[i], yd[Y1] - 1);
		}

		if (yd.find(Y2) != yd.end()) {
			R[i] = min(R[i], yd[Y2] - 1);
		}

		rx -= dx[str[i]];
		ry -= dy[str[i]];
	}

	fj(1, k) {
		r[j].first += fx - sx;
		r[j].second += fy - sy;
	}

	rx = fx;
	ry = fy;

	fdi(m, 1) {
		d[rx * 1000000 + ry] = i;
		fj(1, k) {
			r[j].first -= dx[str[i]];
			r[j].second -= dy[str[i]];
 
			unordered_map<int, int>::iterator it = d.find(r[j].first * 1000000 + r[j].second);

			if (it != d.end()) {
				R[i] = min(R[i], it->second - 1);
			}

		}
		rx -= dx[str[i]];
		ry -= dy[str[i]];
	}

}

int main() {
	freopen(filename ".in", "r", stdin);
	freopen(filename ".out", "w", stdout);

	scanf("%d %d", &n, &m);
	scanf("%s", str + 1);

	fj(1, n) {
		scanf("%s", matr[j] + 1);
	}	

	init();

	solve();

	ll ans = 0;
	
	fi(1, m) {
		if (R[i] >= i) {
			ans += R[i] - i + 1;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}

