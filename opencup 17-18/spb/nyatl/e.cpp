#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:134217728")

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

#define FILENAME "decimal-form"

long double inf = 1e18;

int n;
long double x;

ll ansa, ansb;
long double ansd;

int ansf = 0;

ll limit;

char tmp[100];
char str[100];

long double V(ll a, ll b) {
	return (long double)a / b;
}

void relax(ll a, ll b) {
	if (a > 1000000000 || b > 1000000000) return;
	long double diff = fabs((long double)a / (long double)b - x);
	if (diff < ansd) {
		ansd = diff;
		ansa = a;
		ansb = b;
	}


}

int Q;

void fun(ll a1, ll b1, ll a2, ll b2) {
	if (b1 > 1000000000 || b2 > 1000000000) return;
	if (ansf) return;
	//if (ansd < 1e-19) return;
	relax(a1, b1);
	relax(a2, b2);
	ll a3 = a1 + a2;
	ll b3 = b1 + b2;
	relax(a3, b3);

	if (x < (long double)a3 / b3) {
		ll l = 1;
		ll r = limit / b1 + 1;

		while (l < r) {
			ll h = (l + r) / 2 + 1;
			ll ha = a1 * h + a2;
			ll hb = b1 * h + b2;
			if (x < V(ha, hb) && ha <= limit && hb <= limit) {
				l = h;
			} else {
				r = h - 1;
			}
		}

		//l = 1;

		a3 = a2 + a1 * l;
		b3 = b2 + b1 * l;

		fun(a1, b1, a3, b3);
	} else {
		ll l = 1;
		ll r = limit / b2 + 1;

		while (l < r) {
			ll h = (l + r) / 2 + 1;
			ll ha = a2 * h + a1;
			ll hb = b2 * h + b1;
			if (x > V(ha, hb) && ha <= limit && hb <= limit) {
				l = h;
			} else {
				r = h - 1;
			}
		}

		//l = 1;

		a3 = a1 + a2 * l;
		b3 = b1 + b2 * l;

		fun(a3, b3, a2, b2);
	}
}

ll gcd(ll a, ll b) {
	return a == 0 ? b : gcd(b % a, a);
}

void solve() {
	ansd = 1e20;
	ansa = -1;
	ansb = -1;
	ansf = 0;
	Q = 0;

	limit = 1;
	fi(1, 9) {
		limit *= 10;
	}

	relax((ll)(x * limit + 1e-5), limit);

	fun(0, 1, 1, 1);

	ll g = gcd(ansa, ansb);
	ansa /= g;
	ansb /= g;

	printf("%lld %lld\n", ansa, ansb);
	fflush(stdout);
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	scanf("%d", &n);
	fi(1, n) {
		scanf("%s", str);
		unsigned long long tmp;
		sscanf(str, "0.%llu", &tmp);
		x = tmp / inf;
		cerr << setprecision(18) << fixed << x << endl;
		solve();
	}
	return 0;
}