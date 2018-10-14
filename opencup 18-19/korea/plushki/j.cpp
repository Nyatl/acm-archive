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

const int MAX = 300 * 1000 + 41;
const int INF = 1000 * 1000 * 1000;
const ll LINF = INF * 1LL * INF;

int n;
int a[MAX];
int bl[MAX], br[MAX];
ll L, R;
map<int, vector<pii>> seg; // <hegith, vector<left, right>>
vector<ll> ans;
ll to_skip;

ll calc_eq(ll w, ll l, ll r) {
	w--;
	if (w < 0) return 0;
	if (w > r + l) return 0;
	ll res = min(w, l) + min(w, r) - w + 1;
	return res;
}

ll calc_leq2(ll w, ll len) {
	w = min(len, w);
	ll res = (w + 1) * (len + 1) - w * (w + 1) / 2;
	return res;
}

ll calc_leq(ll w, ll l, ll r) {
	w--;
	if (w < 0) return 0;
/*
	ll res = 0;
	fi(0, w) {
		res += calc_eq(i, l, r);
	}
	return res;
*/
	ll res = 0;
	res += calc_leq2(w, l + r);
	res -= calc_leq2(w, l - 1);
	res -= calc_leq2(w, r - 1);
	return res;
}

ll calc_eq(ll h, ll w) {
	ll res = 0;
	for (auto &z : seg[h]) {
		res += calc_eq(w, z.first, z.second);
	}
	return res;
}

ll calc(ll val) {
	ll res = 0;
	for (auto &z : seg) {
		ll h = z.first;
		ll w = val / h;
		for (auto &p : z.second) {
			int left = p.first;
			int right = p.second;
			res += calc_leq(w, left, right);
		}
	}
	return res;
}

void add(ll val, ll cnt) {
	fi(1, cnt) {
		if (sz(ans) >= (R - L + 1)) break;
		ans.pb(val);
	}
	dbg(ans);
}

void solve() {

	ll l = 0;
	ll r = LINF;
	while (r - l > 1) {
		ll mid = (l + r) >> 1;
		if (calc(mid) > L) { // ?
			r = mid;
		} else {
			l = mid;
		}
	}
	ll val = r;
	dbg(val);

	set<pair<ll, ll>> t; // <val2, height>
	for (auto &z : seg) {
		ll h = z.first;
		ll w = val / h;
		w++;
		ll val2 = h * w;
		t.insert(mp(val2, h));
	}


	ll nxtval = t.begin()->first;
	dbg(nxtval);
	ll L2 = calc(nxtval);
	dbg(L2);
	add(val, L2 - L);

	while (sz(ans) < (R - L) + 1) {
		auto p = *t.begin();
		t.erase(t.begin());
		ll h = p.second;
		ll val = p.first;
		ll w = val / h;

		ll to_add = calc_eq(h, w);
		if (to_add == 0) continue;
		add(val, to_add);

		w++;
		ll val2 = h * w;
		t.insert(mp(val2, h));
	}
	for (ll z : ans) {
		printf("%lld ", z);
	}
	printf("\n");
}

void prep() {
	vi v;
	fi(1, n) {
		while (sz(v) && a[v.back()] >= a[i]) {
			br[v.back()] = i;
			v.pop_back();
		}
		if (v.empty()) {
			bl[i] = 0;
		} else {
			bl[i] = v.back();
		}
		v.pb(i);
	}
	for (int x : v) {
		br[x] = n + 1;
	}
	dbg1(bl, n);
	dbg1(br, n);
	fi(1, n) {
		seg[a[i]].pb(mp(i - bl[i] - 1, br[i] - i - 1));
	}
	dbg(seg);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
	scanf("%lld %lld", &L, &R);
	L--;
	R--;
	prep();

//	dbg(calc(2));
//	exit();
	solve();
	exit();
	return 0;
}