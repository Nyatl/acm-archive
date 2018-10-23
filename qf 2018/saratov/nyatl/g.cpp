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

#define ID "g"

#define MAX 110

int n, m;
int a0[MAX];
int a[MAX];

int hero0[MAX];
int hero[MAX];
int num[MAX];

bool move(int x, int dx, int last) {
	int cur = hero[x];
	errln("%d -> %d", x, last);
	dbg1(a, n);
	dbg(cur);	
	while (1) {
		cur += a[x];
		if (cur < 0) return false;
		if (x == last) return true;
		x += dx;
		dbg(cur);
	}
	return false;
}

void solve(int x0) {
	errln();
	errln("%d\n", x0);
	vi ans;
	int last = -1;
	int lq = 0, rq = 0;
	fi(1, x0) {
		if (hero[i]) lq++;		
	}
	fi(x0 + 1, n) {
		if (hero[i]) rq++;		
	}

	fo(1, lq) {
		int f = 0;
		fdi(x0, 1) {
			if (!hero[i]) continue;
			if (move(i, 1, x0)) {
				fj(i, x0) {
					a[j] = 0;					
				}
				hero[i] = 0;
				f = 1;
				ans.pb(num[i]);
				break;
			}
		}	
		if (!f) return;
	}

	fo(1, rq) {
		int f = 0;
		fi(x0, n) {
			if (!hero[i]) continue;
			if (move(i, -1, x0)) {
				fj(x0, i) {
					a[j] = 0;					
				}
				hero[i] = 0;
				f = 1;
				ans.pb(num[i]);
				break;
			}
		}	
		if (!f) return;
	}
	printf("%d\n", x0);
	for (auto z : ans) {
		printf("%d ", z);
	}
	printf("\n");
	exit();
}

int x[MAX], hp[MAX];

void init() {
	fi(1, m) {
		hero[x[i]] = hp[i];
		num[x[i]] = i;
	}
	dbg1(hero, n);
	dbg1(num, n);
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d", &n, &m);
	fi(1, m) {
		scanf("%d %d", &x[i], &hp[i]);
	}

	fi(1, n) {
		scanf("%d", &a[i]);
	}

	init();

	cpy(a0, a);
	cpy(hero0, hero);

	fi(1, n) {
		cpy(a, a0);
		cpy(hero, hero0);
		solve(i);
	}

	printf("-1\n");

	exit();
	return 0;
}