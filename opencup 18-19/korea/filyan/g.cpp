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

const int MAX = 250 * 1000 + 41;
const ll INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 41;
const int Z = 9;
const int BALANCE = Z * 2 + 1;

int n, k;
int w[MAX];
ll d[2][2][2][BALANCE][Z + 1];

ll ans;

void solve() {
	fill_n(&d[0][0][0][0][0], 2 * 2 * BALANCE * (Z + 1), INF);
	d[0][0][1][Z][0] = 0;

	fi(1, n) {
		fill_n(&d[1][0][0][0][0], 2 * 2 * BALANCE * (Z + 1), INF);
		for (int c = 0; c <= 1; c++) {
			for (int f = 0; f <= 1; f++) {
				for (int bal = 0; bal <= BALANCE - 1; bal++) {
					for (int cnt = 0; cnt <= k; cnt++) {
						if (d[0][c][f][bal][cnt] == INF) continue;
						for (int me = 0; me <= 1; me++) {
							int add = (me ? w[i] : 0);
							{
								int c1 = me;
								bool f1 = (c || me);
								int bal1 = bal;
								int cnt1 = cnt;
								if (f || c1) {
									d[1][c1][f1][bal1][cnt1] = min(d[1][c1][f1][bal1][cnt1], d[0][c][f][bal][cnt] + add);
								}
							}	
							
							{
								int c1 = 1 - me;
								bool f1 = (c || c1);
								int bal1 = bal + (me == 0 ? 1 : -1);
								int cnt1 = cnt;
								if (abs(bal1 - Z) > abs(bal - Z)) {
									cnt1++;
								}
								if (cnt1 > k || cnt1 < 0 || (!f && !c1)) continue;
								d[1][c1][f1][bal1][cnt1] = min(d[1][c1][f1][bal1][cnt1], d[0][c][f][bal][cnt] + add);								
							}

						}
					}
				}
			}
		}
		memcpy(d[0], d[1], sizeof(d[0]));
	}	

	ans = INF;
	fj(0, k) {
		ans = min(ans, d[0][0][1][Z][j]);
		ans = min(ans, d[0][1][1][Z][j]);
	}

	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

  scanf("%d %d", &n, &k);
  fi(1, n) {
  	scanf("%d", &w[i]);
  }
	solve();

	exit();
	return 0;
}



