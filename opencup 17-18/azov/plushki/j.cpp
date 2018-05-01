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
ostream& operator<<(ostream& s, pair<A, B> p) {
	s << "(" << p.first << ", " << p.second << ")";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	fi(0, sz(v) - 1) {
		s << v[i] << " ";
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, set<T> t) {
	for (auto z : t) {
		s << z << " ";
	}
	return s;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& s, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		s << "\t" << z.first << " -> " << z.second << endl;
	}
	return s;
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

const int MAX = 100 * 1000 + 41;

vi e1[MAX];
vi e2[MAX];
int h[MAX];

int N, M;

vi calcdist(vi e[MAX], int n) {
	
	fi(1, n) h[i] = -1;
	queue<int> q;

	fi(1, n) {
		if (sz(e[i]) == 1) {
			h[i] = 0;
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int y : e[x]) {
			if (h[y] == -1) {
				h[y] = h[x] + 1;
				q.push(y);
			}
		}
	}
	
	vi res;
	fi(1, n) res.pb(h[i]);
	
	sort(all(res));
	return res;
}

double checkval = 0;

double calceq(vi &h1, vi &h2) {
	double res = 0;
	for (int z : h1) {
		auto p2 = upper_bound(all(h2), z); 
		auto p1 = lower_bound(all(h2), z);
		double pos = (1. / sz(h1)) * (p2 - p1) / sz(h2);
		res += z * pos; 
		checkval += pos;
	}

	return res;
}  

double calcdif(vi &h1, vi &h2) {
	double res = 0;
	for (int z : h1) {
		auto p2 = h2.end();
		auto p1 = upper_bound(all(h2), z);
		double pos = (1. / sz(h1)) * (p2 - p1) / sz(h2);
		res += z * pos; 
		checkval += pos;
	}

	return res;
}  


void solve() {
	scanf("%d", &N);
	fi(1, N - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		e1[x].pb(y);
		e1[y].pb(x);
	}
	scanf("%d", &M);
	fi(1, M - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		e2[x].pb(y);
		e2[y].pb(x);
	}
	
	vi h1 = calcdist(e1, N);
	vi h2 = calcdist(e2, M);
	
	dbg(h1);
	dbg(h2);
	
	double ans1 = calceq(h1, h2);
	double ans2 = calcdif(h1, h2);
	double ans3 = calcdif(h2, h1);

	double ans = ans1 + ans2 + ans3;
	
	dbg(checkval);
	
	printf("%.12lf", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	solve();
	exit();
	return 0;
}
