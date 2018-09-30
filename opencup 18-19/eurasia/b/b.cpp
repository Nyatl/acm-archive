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

const int MAX = 200 * 1000 + 41;
const ll LINF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;

struct Node {
	char type;
	ll time;
	vi par;
	vi chd;
	Node(char type, ll time) : type(type), time(time) {
		par.clear();
		chd.clear();
	}
};

int n;
ll d;
vector<Node> v;
vi per;
bool f[MAX];

void adddep(int x, int y) {
	v[x].chd.pb(y);
	v[y].par.pb(x);
}

void add(int x) {
	if (f[x]) return;
	for (int p : v[x].par) add(p);
	per.pb(x);
	f[x] = true;
}

int bsz;
int cnt[MAX];
set<int> buf;
bool shown[MAX];
ll T;
int c; // decoded
int q; // shown
bool bad = false;
ll dt[MAX];

void tryrem(int x) {
	if (!shown[x]) return;
	if (cnt[x] > 0) return;
	buf.erase(x);
}

void show() {
	int x = q;//per[q];
	err("show %d\n", x);
	if (!buf.count(x)) {
		bad = true;
		err("failed to show %d\n", x);
		return;
	}
	shown[x] = true;
	tryrem(x);
	T = max(T, d * q);

	dbg(buf);
	dbg(T);
	q++;
}

void dec() {
	int x = per[c];
	err("decode %d\n", x);
	buf.insert(x);
	T += v[x].time;
	dt[x] = T;
	if (x * d < dt[x] || sz(buf) > bsz) {
		bad = true;
		err("failed to decode %d\n", x);
		return;
	}

	for (int z : v[x].par) cnt[z]--;
	for (int z : v[x].par) tryrem(z);
	c++;
	dbg(buf);
	dbg(T);
}

bool check(ll bsz) {
	dbg("---------------------------------------------------------------------------");
	dbg(bsz);
	::bsz = bsz;
	fi(0, n - 1) {
		cnt[i] = sz(v[i].chd);
		shown[i] = false;
		dt[i] = LINF;
	}
	buf.clear();
	c = 0;
	q = 0;
	T = -LINF;
	bad = false;

	fi(0, bsz - 1) {
		dec();
	}
	T = 0;

	while (c < n || q < n) {
		bool f = false;
		if (q < n && q * d >= dt[q]) {
			f = true;
			show();
			if (bad) return false;
		}
		while (c < n && sz(buf) < bsz) {
			f = true;
			dec();
			if (bad) return false;
		}
		if (!f) {
			err("stuck: c == %d, q == %d\n", c, q);
			return false;
		}
	}
	dbg0(dt, n);
#ifdef LOCAL
	vi times;
	fi(0, n - 1) times.pb(i * d);
	dbg(times);
	fi(0, n - 1) {
		assert(times[i] >= dt[i]);
	}
#endif
	return true;
}

void solve() {
	scanf("%d %lld", &n, &d);
	fi(0, n - 1) {
		char c;
		ll t;
		scanf(" %c %lld", &c, &t);
		v.push_back(Node(c, t));
	}

	int last = -1;
	fi(0, n - 1) {
		if (v[i].type == 'I') {
			last = i;
		}
		if (v[i].type == 'P') {
			adddep(last, i);
			last = i;
		}
		if (v[i].type == 'B') {
			adddep(last, i);
		}
	}
	last = n;
	fdi(n - 1, 0) {
		if (v[i].type == 'I') {
			last = i;
		}
		if (v[i].type == 'P') {
			last = i;
		}
		if (v[i].type == 'B') {
			adddep(last, i);
		}
	}

	fi(0, n - 1) {
		add(i);
	}
	dbg(per);

//	dbg(check(4));
//	dbg0(dt, n);
//	return;


	ll l = 0;
	ll r = n + 1;
	while (r - l > 1) {
		ll h = (r + l) / 2;
		if (check(h)) {
			r = h;
		} else {
			l = h;
		}
	}

	ll ans = r;

	printf("%lld\n", ans);
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