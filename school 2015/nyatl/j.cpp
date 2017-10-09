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

#define filename "primeseq"

const int MAX = 1000 * 1000 * 10;

bool c[MAX];

string getS(int n) {
	string s;
	for (int i = 2; n > 0; i++) {
		if (!c[i]) {
			s += to_string(i);
			n--;
		}
	}
	return s;
}

string solve(int n, int k) {

	string s = "z" + getS(n) + "z";
	
	vector<pair<int, int>> refs;
	fi(0, sz(s)) refs.pb(mp(i - 1, i + 1));
	
	int cur = 1;
	while(k > 0) {
		int prev = refs[cur].first;
		int next = refs[cur].second;
		
		if (s[cur] >= s[next]) {
			cur = next;
			continue;
		}
		
		refs[prev].second = refs[cur].second;
		refs[next].first = refs[cur].first;
		
		k--;
		cur = prev;
	}
	
	assert(k == 0);
	
	
	cur = 0;
	string ans;
	while (cur < sz(s)) {
		int next = refs[cur].second;
		ans += s[next];
		cur = next;
	}
	return ans;
}

int main() {
	freopen(filename ".in", "r", stdin);
	freopen(filename ".out", "w", stdout);
	
	fi(2, MAX - 1) {
		if (c[i]) continue;
		for (int j = 2 * i; j < MAX; j += i) {
			c[j] = true;
		}
	}
	
	
	int t;
	scanf("%d", &t);
	
	fi(1, t) {
		int n, k;
		scanf("%d%d", &n, &k);
		string ans = solve(n, k);
		ans.resize(sz(ans) - 2);
		printf("%s\n", ans.c_str());
	}
	
	return 0;
}

