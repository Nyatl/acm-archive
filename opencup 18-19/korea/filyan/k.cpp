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

int n;
int c[MAX];
int d[MAX];

int cost1[MAX];

vpii e[MAX][2];

//tree
const ll INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 41;
ll t[2][MAX * 4];

void upd(int id, int p, ll val, int x = 0, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[id][x] = max(t[id][x], val);
	} else {
		int tm = (tl + tr) >> 1;
		if (p <= tm) {
			upd(id, p, val, x * 2 + 1, tl, tm);
		} else {
			upd(id, p, val, x * 2 + 2, tm + 1, tr);
		}
		t[id][x] = max(t[id][x * 2 + 1], t[id][x * 2 + 2]);
	}
}

ll getmax(int id, int l, int r, int x = 0, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return 0;
	if (l <= tl && tr <= r) {
		return t[id][x];
	}
	int tm = (tl + tr) >> 1;
	ll v1 = getmax(id, l, r, x * 2 + 1, tl, tm);
	ll v2 = getmax(id, l, r, x * 2 + 2, tm + 1, tr);
	return max(v1, v2);
}

//

void init() {
	fi(1, n) {
		if (c[i] == 1) {
			cost1[i] = d[i];
		}
	}
	fi(1, n) {
		if (c[i] == 1) continue;
		//0
		{
			int y = i + c[i] - 1;
			if (y <= n) {
				e[y][0].pb(mp(i, d[i]));
			}
		}
		//1
		{
			int x = i - c[i] + 1;
			if (x >= 1) {
				e[i][1].pb(mp(x, d[i]));
			}
		}
	}
}

ll ans[MAX];
ll ans0[MAX];
ll ans1[MAX];

vpll toupd[MAX][2];

void buildupd(int x) {
	sort(e[x][0].begin(), e[x][0].end());
	sort(e[x][1].begin(), e[x][1].end());
	for (auto z : e[x][0]) {
		int l = 1;
		int r = z.first;
		ll b = max(getmax(1, l, r), getmax(0, l, r - 1));
		if (sz(toupd[x][0])) {
			b = max(b, toupd[x][0].back().second);
		}
		int w = z.second;
		toupd[x][0].pb(mp(r, b + w));
	}

	if (sz(e[x][1])) {
		int l = 1;
		int r = e[x][1][0].first;
		ll b = max(getmax(1, l, r), getmax(0, l, r - 1));
		for (auto z : toupd[x][0]) {
			if (z.first < r) {
				b = max(b, z.second);
			}
		}
	  b += e[x][1][0].second;
	  toupd[x][1].pb(mp(r, b));
	}	
}

void push(int x, int par) {
	for (auto z : toupd[x][par]) {
		upd(par, (int) z.first, z.second);
	}
}

void solve() {
	int x = n;
	while (x > 0) {
		buildupd(x);
		push(x, 0);
		ans0[x] = getmax(0, 1, x - 1);
		ans1[x] = getmax(1, 1, x);
		ans[x] = max(ans0[x], ans1[x]) + cost1[x];
		push(x, 1);
		x--;
	}
	fi(1, n) {
		printf("%lld ", ans[i]);
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
  	scanf("%d", &c[i]);
  }
 	fi(1, n) {
 		scanf("%d", &d[i]);
 	}
 	init();

	solve();

	exit();
	return 0;
}



