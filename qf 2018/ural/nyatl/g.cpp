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
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
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

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
 
#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))
 
#define LL long long
#define VI vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

char str[500];
char tmp[500];
int n;

int d[500][500];
int p[500][500];

int fun(int l, int r) {
	if ((r - l + 1) % 2 == 1) return false;
	if (l > r) return true;
	if (d[l][r] != -1) return d[l][r];
	int res = 0;
	if (str[l] == '<' && str[r] == '>' && fun(l + 1, r - 1)) {
		p[l][r] = -1;
		res = 1;
	}
	if (str[l] == '>' && str[r] == '<' && fun(l + 1, r - 1)) {
		p[l][r] = -1;
		res = 1;
	}
	fi(l + 1, r - 2) {
		if (fun(l, i) && fun(i + 1, r)) {
			p[l][r] = i;
			res = 1; 
		}
	}
	return d[l][r] = res;
}

void print(int l, int r) {
	if (l > r) return;
	errln("Print %d %d (%d)", l, r, p[l][r]);	
	if (p[l][r] == -1) {
		printf("[");
		print(l + 1, r - 1);
		printf("]");
	} else {
	    print(l, p[l][r]);
	    print(p[l][r] + 1, r);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%s", tmp + 1);

	int len = (int)strlen(tmp + 1);

	for (int i = 1; i <= len; i += 2) {
		n++;
		str[n] = tmp[i];
	}

    dbg(str + 1);

	memset(d, -1, sizeof(d));

	fun(1, n);

	if (d[1][n] != 1) {
		printf("Keine Loesung\n");
		return 0;
	}

	print(1, n);

	exit();
	return 0;
}