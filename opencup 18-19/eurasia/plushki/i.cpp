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
#include <unordered_map>
#include <unordered_set>

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

struct Seg {
	ll x1, x2;
	ll num;
	Seg() {}
	Seg(ll x1, ll x2, ll num) : x1(x1), x2(x2), num(num) {}
};

const int ADD = 1;
const int REM = 0;

struct Event {
	ll x;
	ll num;
	int type;
	Event() {}
	Event(ll x, ll num, int type) : x(x), num(num), type(type) {}
	bool operator<(const Event &e) const {
		if (x != e.x) {
			return x < e.x;
		}
		if (type != e.type) {
			return type < e.type;
		}
		return num < e.num;
	}
};

struct State {
	ll x;
	ll sum;
	int cnt;
	State() {}
	State(ll x, ll sum, int cnt) : x(x), sum(sum), cnt(cnt) {}
	bool operator<(const State &s) const {
		return x < s.x;
	}
};

ostream& operator<<(ostream& s, const State & t) {
	s << t.x << ' ' << t.sum << ' ' << t.cnt << ',';
	return s;
}


const int MAX = 400005;

const ll MUL = 1000000;

const int MAGIC = 1400;

ll toLL(double x) {
	return (ll)(x * MUL + 0.5);
}

int n;
ll N;

ll A;

ll getP(ll x) {
	return (A + x) % N;
}

vector<Seg> v;

vector<Event> e;

vector<State> st;

void rebuild() {
	for (Seg &z : v) {
		e.pb(Event(z.x1, z.num, ADD));
		e.pb(Event(z.x2 + 1, z.num, REM));
	}
	sort(all(e));
	st.clear();
	int p = 0;
	ll bal = 0;
	int q = 0;
	while (p < sz(e)) {
		ll x = e[p].x;
		while (p < sz(e) && x == e[p].x && e[p].type == REM) {
			bal -= e[p].num;
			q--;
			p++;
		}
		while (p < sz(e) && x == e[p].x && e[p].type == ADD) {
			bal += e[p].num;
			q++;
			p++;
		}
		st.pb(State(x, bal, q));
	}
	dbg(st);
}

void add(ll x1, ll x2, int num) {
	v.pb(Seg(x1, x2, num * MUL));
	if (sz(v) >= MAGIC) {
		rebuild();

	v.clear();
	}
}

int getSimple(ll x) {
	int res = 0;
	for (Seg &z : v) {
		if (z.x1 <= x && x <= z.x2) {
			res++;
			A += z.num;
		}
	}
	A %= N;
	return res;
}

int getHard(ll x) {
	int res = 0;
	auto it = upper_bound(all(st), State(x, 0, 0));
	if (it == st.begin() || it == st.end()) {
		res = 0;
	} else {
		it--;
		A += it->sum;
		res = it->cnt;
	}
	A %= N;
	return res;
}

int get(ll x) {
	int res = 0;
	res += getSimple(x);
	res += getHard(x);
	return res;
}

void solve() {
	scanf("%d", &n);
	N = MUL * n;
	int q = 0;
	fi(1, 2 * n) {
		int type;
		scanf("%d", &type);
		if (type == 0) {
			double a, b;
			scanf("%lf %lf", &a, &b);
			ll c = getP(toLL(a));
			ll r = toLL(b);
			add(c - r, c + r, q);
			q++;
		} else if (type == 1) {
			double tmp;
			scanf("%lf", &tmp);
			ll x = getP(toLL(tmp));
			int ans = get(x);
			printf("%d\n", ans);
		}
		dbg(A);
	}
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