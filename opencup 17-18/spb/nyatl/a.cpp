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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define FILENAME "base-i-1"

#define MAX 2100000

int a[MAX];
int b[MAX];

char tmp[MAX];

int ans[MAX];
int ansl;

void solve() {
	fi(1, 2000000) {
		ans[i] += a[i] + b[i];
		if (ans[i] >= 2) {
			ans[i + 2] += ans[i] / 2;
			ans[i + 3] += ans[i] / 2;
			ans[i] %= 2;
		}
		if (ans[i]) {
			ansl = max(ansl, i);
		}
	}
	dbg(ansl);
	ansl = max(ansl, 1);
	fdi(ansl, 1) {
		printf("%d", ans[i]);
	}
	printf("\n");
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

    scanf("%s", tmp + 1);
    int l = strlen(tmp + 1);
    int c = 0;
    fdi(l, 1) {
        c++;
        a[c] = tmp[i] - '0';
	}

    scanf("%s", tmp + 1);
    l = strlen(tmp + 1);
    c = 0;
    fdi(l, 1) {
        c++;
        b[c] = tmp[i] - '0';
	}
	solve();
	return 0;
}