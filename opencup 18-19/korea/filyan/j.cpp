#include <bits/stdc++.h>

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

///////////////////////////////////////////////////

const int MAX = 300 * 1000 + 41;
const ll INF = 1000LL * 1000LL * 1000LL * MAX;

int n;
ll L, R;

int h[MAX];

vector<tuple<ll, ll, ll>> rects;

ll getcnt0(ll len, ll w) {
	w = min(w, len);
	if (w <= 0) return 0;
	return (len - w + 1 + len) * w / 2;
}

ll getleqcnt(ll l, ll r, ll w) {
	return getcnt0(l + r + 1, w) - getcnt0(l, w) - getcnt0(r, w);
}

ll getexactcnt(ll l, ll r, ll w) {
	return getleqcnt(l, r, w) - getleqcnt(l, r, w - 1);
}

ll getleq(ll area) {
	ll res = 0;
	for (auto z : rects) {
		ll resp = getleqcnt(get<0>(z), get<1>(z), area / get<2>(z));
		res += resp;
	}
	return res;
}

ll ans[MAX];

void addtoans(ll l, ll r, ll area) {
	if (l > R || L > r) return;
	ll lp = max(l, L);
	ll rp = min(r, R);
	while (lp <= rp) {
		ans[(int) (lp - L + 1)] = area;
		lp++;
	}
}

void solve() {
	ll le = 0;
	ll ri = INF;
	while (ri - le > 1) {
		ll h = (le + ri) / 2;
		if (getleq(h) < L) {
			le = h;
		} else {
			ri = h;
		}
	}
	ll x = getleq(le);
	le++;
	multiset<tuple<ll, ll, ll, ll>> t;
	for (auto z : rects) {
		ll l = get<0>(z);
		ll r = get<1>(z);
		ll h = get<2>(z);
		ll w = (le + h - 1) / h;
		if (getexactcnt(l, r, w) == 0) continue;
		t.insert(make_tuple(h * w, h, l, r));
	}

	while (x < R) {
		auto cur = (*t.begin());
		t.erase(t.begin());
		ll area = get<0>(cur);
		ll h = get<1>(cur);
		ll l = get<2>(cur);
		ll r = get<3>(cur);
		ll ways = getexactcnt(l, r, area / h);
		if (!ways) continue;
		addtoans(x + 1, x + ways, area);
		x += ways;
		t.insert(make_tuple(area + h, h, l, r));
	}

	int cnt = (int) (R - L + 1);
	fi(1, cnt) {
		printf("%lld ", ans[i]);
	}
}

void init() {
	vpii st;
	vi l(n + 1), r(n + 1);

  fi(1, n) {
  	while (sz(st) && st.back().first > h[i]) {
  		st.pop_back();
  	}
  	l[i] = (sz(st) ? st.back().second + 1 : 1);
  	st.pb(mp(h[i], i));
  }

  st.clear();

  fdi(n, 1) {
		while (sz(st) && st.back().first >= h[i]) {
  		st.pop_back();
  	}
  	r[i] = (sz(st) ? st.back().second - 1 : n);
  	st.pb(mp(h[i], i));  	
  }
/*
  fi(1, n) {
  	err("i = %d l = %d r = %d\n", i, l[i], r[i]);
  }
*/
	fi(1, n) {
		rects.pb(make_tuple(i - l[i], r[i] - i, h[i]));
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

  scanf("%d", &n);
  fi(1, n) {
  	scanf("%d", &h[i]);
  }
  scanf("%lld %lld", &L, &R);
  init();

	solve();

	exit();
	return 0;
}



