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

ll const SHIFT = 1000 * 1000;
ll const MAX = 1000 * 1000LL * 1000 * 1000LL;
ll const ZERO = MAX / 2;
int const MOD = 1000 * 1000 + 41;

int n;
ll sum;

ll getll(double x) {
	return (ll) (x * SHIFT + 0.5);
}

vpll Fq[MOD], Fs[MOD];

void updtable(vpll &v, ll x, ll val) {
	int p = -1;
	fi(0, sz(v) - 1) {
		if (v[i].first == x) {
			p = i;
			break;
		}
	}
	if (p == -1) {
		v.pb(mp(x, val));
	} else {
		v[p].second += val;
	}
}

ll gettable(vpll &v, ll x) {
	int p = -1;
	fi(0, sz(v) - 1) {
		if (v[i].first == x) {
			p = i;
			break;
		}
	}
	if (p == -1) {
		return 0LL;
	} else {
		return v[p].second;
	}
}

void upd(vpll F[MAX], ll x, ll val) {
	assert(x >= 0 && x < MAX);
	while (x < MAX) {
		updtable(F[x % MOD], x, val);
//		F[x] += val;
		x |= (x + 1);
	}	
}

ll getsum(vpll F[MAX], ll x) {
	ll res = 0;
	while (x >= 0) {
//		if (F.find(x) != F.end()) res += F[x];
		res += gettable(F[x % MOD], x);	
		x = (x & (x + 1)) - 1;
	}
	return res;
}

ll getrealpos(ll x) {
	return (x + sum * SHIFT) % (n * SHIFT) + ZERO;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);
	int id = 0;
	fi(1, n * 2) {
		int type;
		scanf("%d", &type);
		if (type == 0) {
			double c, rd;
			scanf("%lf %lf", &c, &rd);
			ll x = getll(c);
			ll rad = getll(rd);
			x = getrealpos(x);
			
			ll l = x - rad;
			ll r = x + rad + 1;

			upd(Fq, l, 1);
			upd(Fq, r, -1);
			upd(Fs, l, id);
			upd(Fs, r, -id);
			id++;
		}	else {
			double c;
			scanf("%lf", &c);
			ll x = getll(c);
			x = getrealpos(x);
			int ans = getsum(Fq, x);
			ll resp = getsum(Fs, x);
//			err("x = %lld ans = %d resp = %lld\n", x - ZERO, ans, resp);
			sum = (sum + resp) % n;
			printf("%d\n", ans);
		}
	}	

	exit();
	return 0;
}



