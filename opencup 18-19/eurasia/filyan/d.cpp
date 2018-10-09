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

/////////////////////////////////

int const MAX = 1e5 + 41;

int n, k, m;
int x[MAX];
int y[MAX];
int a[MAX];
int b[MAX];

int par[MAX];
int size[MAX];

set<pii> bad;

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void repaint(int cur, int nxt) {
	err("repaint!\n");
	auto it = bad.lower_bound(mp(cur, -41));
	vpii a;
	while (1) {
		if (it == bad.end()) break;
		if (it->first != cur) break;
		a.pb((*it));
		it++;
	}
	for (auto z : a) {
		bad.erase(z);
		bad.erase(mp(z.second, z.first));
		bad.insert(mp(nxt, z.second));
		bad.insert(mp(z.second, nxt));
	}
}

bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return 1;
	if (bad.count(mp(a, b))) return false;
	if (bad.count(mp(b, a))) return false;

	if (size[a] < size[b]) swap(a, b);

	repaint(b, a);

	size[a] += size[b];
	par[b] = a;
	return true;
}

void solve() {
	fi(1, k) {
		bad.insert(mp(x[i], y[i]));
		bad.insert(mp(y[i], x[i]));		
		size[x[i]]++;
		size[y[i]]++;
	}
	fi(1, n) {
		par[i] = i;
	}

	vi ans;
	fi(1, m) {
		err("ASdasd\n");
		if (uni(a[i], b[i])) {
			ans.pb(i);
		}
	}
	printf("%d\n", sz(ans));
	for (auto z : ans) {
		printf("%d ", z);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d %d", &n, &k, &m);
	fi(1, k) {
		scanf("%d %d", &x[i], &y[i]);	
	}
	fi(1, m) {
		scanf("%d %d", &a[i], &b[i]);
	}

	solve();		
	
	exit();
	return 0;
}