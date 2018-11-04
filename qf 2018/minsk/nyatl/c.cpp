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
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(auto i=a; i<=b; i++)
#define fj(a, b) for(auto j=a; j<=b; j++)
#define fo(a, b) for(auto o=a; o<=b; o++)
#define fy(a) for(auto &y : a)
#define fz(a) for(auto &z : a)
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

#define ID "c"

int n, m;

#define MAX 40000

vi e[MAX];
int num[MAX];

int k;
int color[MAX];
int cnt[MAX];

void solve() {
	memset(num, -1, sizeof(num));
	k = 1 << n;
	num[1] = 0;
	int q = 0;
	fy(e[1]) {
		num[y] = 1 << q;
		q++;
	}

	queue<int> qu;
	qu.push(1);
	color[1] = 1;
	while (sz(qu)) {
		int x = qu.front();
		qu.pop();
		dbg(x);
		fy(e[x]) {
			if (color[y]) continue;
			color[y] = 1;
			qu.push(y);
		}
		if (num[x] == -1) {
			vi v;
			fy(e[x]) {
				if (num[y] == -1) continue;
				v.pb(num[y]);
			}
			num[x] = 0;
			fy(v) {
				num[x] |= y;
			}
		}
	}
	dbg1(num, k);
	fi(1, k) {
		if (sz(e[i]) != n || num[i] == -1) {
			printf("No\n");
			exit();
		}
	}
	fi(1, k) {
		fy(e[i]) {
			if (cnt[num[i] ^ num[y]] != 1) {
				printf("No\n");
				exit();
			}
		}
	}

	set<int> u;

	fi(1, k) {
		if (u.count(num[i])) {
			printf("No\n");
			exit();
		}
		u.insert(num[i]);
	}

	printf("Yes\n");
	fi(1, k) {
		printf("%d ", num[i]);
	}
	printf("\n");
}

void init() {
	fi(0, MAX - 1) {
		int x = i;
		int res = 0;
		while (x) {
			res += x & 1;
			x >>= 1;
		}
		cnt[i] = res;
	}
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	init();

	scanf("%d %d", &n, &m);

	if (m != (1 << (n - 1)) * n) {
		printf("No\n");
		return 0;
	}

	fi(1, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		a++;
		b++;
		e[a].pb(b);
		e[b].pb(a);
	}

	solve();

	exit();
	return 0;
}