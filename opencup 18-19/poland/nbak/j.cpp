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

const int MAX = 100005;

int n, k;
int a[MAX];
ll p[MAX];

ll get(int pos, int x) {
	int l = 1;
	int r = pos;
	while (r - l) {
		int h = (l + r) / 2;
		dbg(h);
		if (a[pos] - a[h] > x) {
			l = h + 1;
		} else {
			r = h;
		}
	}
	int g1 = l;
	dbg(mp(pos, l));
	dbg1(a, n);
	dbg(x);
	assert(a[pos] - a[l] <= x);
	l = pos;
	r = n + 1;
	while (r - l > 1) {
		int h = (l + r) / 2;
		if (a[h] - a[pos] > x) {
			r = h;
		} else {
			l = h;
		}
	}
	assert(a[l] - a[pos] <= x);
	int g2 = l;
	dbg0(p, n + 1);
	dbg(pos);
	dbg(mp(g1, g2));
	ll res = (p[g2] - p[pos - 1]) - (ll)a[pos] * (g2 - pos + 1);
	res += (ll)a[pos] * (pos - g1) - (p[pos - 1] - p[g1 - 1]);
	dbg(res);
	return res;
}

pii get2(int pos, int x) {
	int l = 1;
	int r = pos;
	while (r - l) {
		int h = (l + r) / 2;
		if (a[pos] - a[h] > x) {
			l = h + 1;
		} else {
			r = h;
		}
	}
	int g1 = l;
	l = pos;
	r = n + 1;
	while (r - l > 1) {
		int h = (l + r) / 2;
		if (a[h] - a[pos] > x) {
			r = h;
		} else {
			l = h;
		}
	}
	int g2 = l;
	return mp(g1, g2);	
}

int get4(int pos, int c1, int c2, int q) {
	int res = 0;
	while (c1 >= 1 || c2 <= n) {
		int res1 = a[pos] - a[c1];
		int res2 = a[c2] - a[pos];
		if (q < res1 && q < res2) {
			break;
		}
		if (res1 < res2) {
			q -= res1;
			c1--;
		} else {
			q -= res2;
			c2++;
		}
		res++;
	}
	return res;
}

int get(int pos) {
	int l = 0;
	int r = k + 1;
	while (r - l > 1) {
		int h = (l + r) / 2;
		if (get(pos, h) > k) {
			r = h;
		} else {
			l = h;
		}
	}
	dbg(l);
	dbg(get(pos, l));
	pii p2 = get2(pos, l);
	int res = p2.second - p2.first + 1;
	dbg(p2);
	//ll cnt = (p[p2.second] - p[p2.first - 1]) - (ll)a[pos] * (p2.second - p2.first + 1LL);
	ll cnt = (p[p2.second] - p[pos - 1]) - (ll)a[pos] * (p2.second - pos + 1);
	cnt += (ll)a[pos] * (pos - p2.first) - (p[pos - 1] - p[p2.first - 1]);
	dbg(res);
	res += get4(pos, p2.first - 1, p2.second + 1, k - cnt);
	return res;
}

void solve() {
	sort(a + 1, a + 1 + n);
	a[0] = -1000000000;
	a[n + 1] = 2000000000;
	fi(1, n) {
		p[i] = p[i - 1] + a[i];
	}
	int ans = 0;
	fi(1, n) {
		if (ans == n) break;
		if (a[i] != a[i - 1]) {
			dbg(i);
			ans = max(ans, get(i));
			dbg(ans);
		}
	}
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	scanf("%d %d", &n, &k);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
	solve();
	exit();
	return 0;
}
