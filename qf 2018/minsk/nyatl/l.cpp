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

#define ID "l"

#define MOD 1000000007

#define MAX 1010

int add(int a, int b) {
	return (a + b) % MOD;
}

int n, k;

bool u[MAX * 75];
int d[MAX * 75];
bool u2[MAX * 75];
int d2[MAX * 75];

int sqr(int x) {
	return x * x;
}

int dist(int x1, int y1, int x2, int y2) {
	return sqr(x1 - x2) + sqr(y1 - y2);
}

int dx[] = {0, 1};
int dy[] = {1, 0};

bool inside(int x, int y) {
	return x <= n && y <= n;
}

int to_num(pair<pii, pii> p) {
	return p.first.first * 72 + (p.second.first - p.first.first);
}

void solve() {
	queue<pair<pii, pii>> qu;
	qu.push(mp(mp(1, 2), mp(2, 1)));
	int num = to_num(mp(mp(1, 2), mp(2, 1)));
	dbg(num);
	u[num] = 1;
	d[num] = 1;
	int ans;
	int last = 3;
	while (sz(qu)) {
		pair<pii, pii> p = qu.front();
		int diag = p.first.first + p.first.second;
		if (diag != last) {
			last = diag;
			cpy(u, u2);
			cpy(d, d2);
			clr(u2);
			clr(d2);
		}
		int num = to_num(p);
		ans = d[num];
		dbg(ans);
		qu.pop();
		int x1 = p.first.first;
		int y1 = p.first.second;
		int x2 = p.second.first;
		int y2 = p.second.second;
		fi(0, 1) {
			int X1 = x1 + dx[i];
			int Y1 = y1 + dy[i];
			if (!inside(X1, Y1)) continue;
			fj(0, 1) {
				int X2 = x2 + dx[j];
				int Y2 = y2 + dy[j];
				if (!inside(X2, Y2)) continue;
				if (X1 == X2 && Y1 == Y2) continue;
				if (dist(X1, Y1, X2, Y2) > k) continue;
				int num2 = to_num(mp(mp(X1, Y1), mp(X2, Y2)));
				d2[num2] = add(d2[num2], d[num]);
				if (u2[num2]) continue;
				u2[num2] = 1;
				qu.push(mp(mp(X1, Y1), mp(X2, Y2)));
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d", &n, &k);

	k = k * k;

	solve();

	exit();
	return 0;
}