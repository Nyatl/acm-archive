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
#include <cmath>

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

 #undef PRINT

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

const ll MOD = 1000 * 1000 * 1000 + 7;
int n;
map<ll, int> cnt; 

bool getbit(ll mask, int x) {
	return (mask & (1LL << x));
}

bool cor(ll x) {
	fi(0, 40) {
		bool t1 = getbit(x, i);
		bool t2 = getbit(x, i + 1);
		if (t1 && t2) return false;
	}
	return true;
}

int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}


int rec(ll x) {

	if (cnt.find(x) != cnt.end()) {
		return cnt[x];
	}
	
	int res = 0;
	if ((x & 3LL) == 1) {
		res = sum(res, rec(x ^ 1LL));
	}
	fdi(n - 2, 1) {
		if (getbit(x, i) && !getbit(x, i - 1) && !getbit(x, i + 1)) {
			ll y = (x ^ (1LL << i) ^ (1LL << (i - 1)));
			if (!cor(y)) continue;
			//dbg(mp(x, y));
			res = sum(res, rec(y));
		}
	}
	dbg(x);
	dbg(res);
	return (cnt[x] = res);
}
/*
void solve() {
	//scanf("%d", &n);
	dbg(n);
	cnt[0] = 1;
	ll beg = 0;
	fi(0, n - 1) {
		if (i % 2 == 1) {
			beg ^= (1LL << (n - 1 - i));
		}
	}
//	dbg(beg);
	int ans = rec(beg);
	printf("%d\n", ans);
}
*/

int ans[] = {1,
1,
2,
5,
33,
319,
9666,
484101,
86126251,
921102616,
690667755,
277772735,
168927647,
863966777,
656710249,
529211723,
952552517,
226276192,
197949884,
305182080,
473057943,
9119576,
607610013,
800401364,
125881901,
404394074,
47341655,
126866039,
937077929,
680342212,
};

void solve() {
	
}
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	// test();
	/*fi(3, 32) {
		n = i;
		cnt.clear();
		solve();
	}*/
	int n;
	scanf("%d", &n);
	printf("%d\n", ans[n - 3]);
	exit();
	return 0;
}
