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

#define ID "c"

#define MAX 1010000

int n, m, k;

struct Plan {
	ll cores;
	ll price;
	int num;
	Plan() {}
	Plan(ll cores, ll price, int num): cores(cores), price(price), num(num) {}
	bool operator<(const Plan &p) const {
		if (price != p.price) return price < p.price;
		if (cores != p.cores) return cores < p.cores;
		return num < p.num;
	}
};

ostream& operator<<(ostream& os, Plan p) {
	os << "(" << p.num << ": c" << p.cores << " p" << p.price << ")";
	return os;
}

Plan plan[MAX];

vi to_add[MAX];
vi to_del[MAX];

set<Plan> t[3];

ll best_cores;
ll best_price;

void del(int num) {
	if (t[1].count(plan[num])) {
		best_cores -= plan[num].cores;
		best_price -= plan[num].price * plan[num].cores;
		t[1].erase(plan[num]);
	} else {
		t[2].erase(plan[num]);
	}
}

void add(int num) {
	if (sz(t[1]) && plan[num].price < t[1].rbegin()->price) {
		t[1].insert(plan[num]);
		best_cores += plan[num].cores;
		best_price += plan[num].price * plan[num].cores;
	} else {
		t[2].insert(plan[num]);
	}
}

void balance() {
	while (sz(t[1]) && best_cores - t[1].rbegin()->cores > k) {
		best_cores -= t[1].rbegin()->cores;
		best_price -= t[1].rbegin()->price * t[1].rbegin()->cores;
		t[2].insert(*t[1].rbegin());
		t[1].erase(*t[1].rbegin());
	}

	while (sz(t[2]) && best_cores < k) {
		best_cores += t[2].begin()->cores;
		best_price += t[2].begin()->price * t[2].begin()->cores;
		t[1].insert(*t[2].begin());
		t[2].erase(*t[2].begin());
	}
}

ll get_ans() {
	if (best_cores <= k) return best_price;
	ll u = best_cores - k;
	return best_price - u * t[1].rbegin()->price;
}

void solve() {
	ll ans = 0;
	fi(1, n) {
		errln();
		dbg(i);
		for (auto z : to_del[i]) {
			del(z);
		}
		dbg(t[1]);
		dbg(t[2]);
		for (auto z : to_add[i]) {
			add(z);
		}
		dbg(t[1]);
		dbg(t[2]);
		balance();
		dbg(t[1]);
		dbg(t[2]);
		ans += get_ans();
		dbg(ans);
	}
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen(ID ".in", "r", stdin);
	freopen(ID ".out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d %d", &n, &k, &m);

	fi(1, m) {
		int l, r, c, p;
		scanf("%d %d %d %d", &l, &r, &c, &p);
		plan[i] = Plan(c, p, i);
		to_add[l].pb(i);
		to_del[r + 1].pb(i);
	}

	solve();

	exit();
	return 0;
}