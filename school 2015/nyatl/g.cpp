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

int n;
FILE *file;

int X[3], Y[3];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
char dc[] = {'L', 'D', 'R', 'U'};

vector <pair<int, int> > lg;

int inside(int x, int y) {
	if (x < 1 || x > n) return false;
	if (y < 1 || y > n) return false;	
	return true;
}

int Q;

int query(int num, int dir) {
	Q++;
	int res;
	printf("0 %d %c\n", num, dc[dir]);
	fflush(stdout);
#ifdef _DEBUG
	int x2 = X[num] + dx[dir];
	int y2 = Y[num] + dy[dir];
	int t;
	if (num == 1) t = 2;
	else t = 1;
	if (inside(x2, y2) && (x2 != X[t] || y2 != Y[t])) {
		X[num] = x2;
		Y[num] = y2;		
		res = 1;
	} else {
		res = 0;
	}
#else
	scanf("%d", &res);
#endif
	if (res) {
		lg.pb(mp(num, dir));
	}
	return res;
}

void solve1() {
	if (n == 2) {
		query(1, 0);
	} else {
		while (query(1, 0));
	}
	if (!query(2, 1)) {
		query(2, 3);
	}
	if (n == 2) {
		query(1, 0);
	} else {	
		while (query(1, 0));
	}

	if (n == 2) {
		query(1, 1);
	} else {
		while (query(1, 1));	
	}
	query(2, 2);
	while (query(1, 1));	
}

void solve2() {
	while (query(2, 0));
	query(2, 3);
	query(2, 0);
	while (query(2, 1));
}

int main() {
#ifdef _DEBUG
	file = fopen("g.in", "r");
	fscanf(file, "%d", &n);	
	fscanf(file, "%d %d %d %d", &X[1], &Y[1], &X[2], &Y[2]);
#else
	scanf("%d", &n);
#endif	
	solve1();
	solve2();
	int x1 = 1;
	int y1 = 1;	
	int x2 = 1;
	int y2 = 2;
	fdi(sz(lg) - 1, 0) {
		int dir = (lg[i].second + 2) % 4;
		if (lg[i].first == 1) {
			x1 += dx[dir];
			y1 += dy[dir];
		} else {
			x2 += dx[dir];
			y2 += dy[dir];
		}
	}
	dbg(Q);
	dbg(6 * n);	
	printf("1 %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	return 0;
}

