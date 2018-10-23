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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(auto i=a; i<=b; i++)
#define fj(a, b) for(auto j=a; j<=b; j++)
#define fo(a, b) for(auto o=a; o<=b; o++)
#define fdi(a, b) for(auto i=a; i>=b; i--)
#define fdj(a, b) for(auto j=a; j>=b; j--)
#define fdo(a, b) for(auto o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

void err(const char *format, ... ) {
#ifdef LOCAL
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
#ifdef LOCAL
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
#ifdef LOCAL	
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

#ifdef LOCAL
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

#define ID "l"

#define MAX 100100

int n;
int k;
int a[MAX];
int len[MAX];

int ans1[MAX];
int ans2[MAX];

void solve(int x) {
	if (ans1[x] != -1) return;
	int c = 1;
	int res1 = 0;
	int res2 = 0;

	dbg(x);

	while (1) {
		int c2 = c + len[c];
		int want = max(c2, min(c + x, n + 1));
		dbg(c);
		dbg(c2);
		dbg(want);
		res1++;
		res2 += want - c2;
		c = want;
		if (c == n + 1) break;
	}
	
	ans1[x] = res1;
	ans2[x] = res2;
}

int sum1[MAX];
int sum2[MAX];

void init() {
	fi(2, n) {
		sum1[i] = sum1[i - 1] + (a[i] >= a[i - 1]);
		sum2[i] = sum2[i - 1] + (a[i] < a[i - 1]);
	}
	fi(1, n) {
		if (a[i + 1] >= a[i]) {
			int l = i, r = n;
			while (l < r) {
				int h = (l + r) / 2 + 1;
				if (sum1[h] - sum1[i] != h - i) {
					r = h - 1;
				} else {
					l = h;
				}
			}
			len[i] = l - i + 1;
		} else {
			int l = i, r = n;
			while (l < r) {
				int h = (l + r) / 2 + 1;
				if (sum2[h] - sum2[i] != h - i) {
					r = h - 1;
				} else {
					l = h;
				}
			}
			len[i] = l - i + 1;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);

	fi(1, n) {
		scanf("%d", &a[i]);
	}

	init();

	memset(ans1, -1, sizeof(ans1));
	memset(ans2, -1, sizeof(ans2));

	scanf("%d", &k);

	fi(1, k) {
		int t;
		scanf("%d", &t);
		solve(t);		
		printf("%d %d\n", ans1[t], ans2[t]);
	}

	exit();
	return 0;
}