#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
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
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<int> si;
typedef set<pii> spii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef set<ll> sl;
typedef set<pll> spll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

#ifdef LOCAL
#define PRINT
#endif

// #undef PRINT

void err(const char *format, ... ) {
#ifdef PRINT
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln(const char *format, ... ) {
#ifdef PRINT
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s\n", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln() {
#ifdef PRINT	
	fprintf(stderr, "\n");
#endif	
}

double START_TIME;

void exit() {
#ifdef LOCAL	
	cerr << "TIME: " << setprecision(5) << fixed << (clock() - START_TIME) / CLOCKS_PER_SEC << endl;
#endif	
	exit(0);
}

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}

#ifdef PRINT
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

#define MOD 1000000007 

#define MAX 305

int a[MAX][MAX];
int n;

int add(int a, int b) {
	return (a + b) % MOD;
}

int mult(int a, int b) {
	return (int)(((ll)a * b) % MOD);
}

int tmp[MAX][MAX];
int tmp2[MAX][MAX];

void mult(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX]) {
	fj(1, n) {
		fi(1, n) {
			int s = 0;
			c[j][i] = 0;
			fo(1, n) {
				s = add(s, mult(a[j][o], b[o][i]));
			}
			c[j][i] = s;
		}			
	}
}

void mult(int a[MAX][MAX], int b[MAX], int c[MAX]) {
	fj(1, n) {
		int s = 0;
		c[j] = 0;
		fo(1, n) {
			s = add(s, mult(a[j][o], b[o]));
		}
		c[j] = s;
	}
}

int x[MAX][MAX];

void pw(int a[MAX][MAX], ll b, int c[MAX][MAX]) {
	memcpy(x, a, sizeof(x));
	clr(tmp2);
	fi(1, n) {
		tmp2[i][i] = 1;
	}
	while (b) {
		if (b & 1) mult(tmp2, x, tmp2);		
		mult(x, x, x);
		b >>= 1;
	}
	cpy(c, tmp2);
}

bool check(int a[MAX][MAX]) {
	fj(1, n) {
		fi(1, n) {
			if (a[j][i] != 0) return false;
		}
	}
	return true;
}

bool check(int a[MAX]) {
	fi(1, n) {
		if (a[i] != 0) return false;
	}
	return true;
}

int a0[MAX][MAX];
int a2[MAX][MAX];
int b[MAX][MAX];

void print(int a[MAX][MAX]) {
	fj(1, n) {
		fi(1, n) {
			err("%d", a[j][i]);
		}
		errln();
	}
	errln();
}

int ap[64][MAX][MAX];

int v[1505][MAX];

void solve() {
	if (check(a)) {
		printf("1\n");
		return;
	}
	ll ans = 0;
	fi(1, n) {
		v[0][i] = rand() % (MOD - 1) + 1;
	}
	fi(1, 1500) {
		mult(a, v[i - 1], v[i]);
		if (check(v[i])) break;
		ans++;
	}
	ans++;
	mult(a, v[1500], v[1501]);
	if (!check(v[1501])) {
		printf("Infinity\n");
		return;
	}
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);
	fj(1, n) {
		fi(1, n) {
			scanf("%d", &a[j][i]);
		}
	}
	
	solve();

	exit();
	return 0;
}
