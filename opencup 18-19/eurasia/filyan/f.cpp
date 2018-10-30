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

const double INF = 1e18;
const int MAX = 3700 * 1000 + 41;

int cnt[41];

char str[5141];

double dp[MAX];
double dp2[MAX];

int state[41];
int maxsize;

int getstate(int q1, int q2, int q4, int q8, int rem) {
	int res = 0;
	int mn = 1;
	
	res += q1 * mn;	
	mn *= (cnt[1] + 1);

	res += q2 * mn;	
	mn *= (cnt[2] + 1);

	res += q4 * mn;	
	mn *= (cnt[4] + 1);

	res += q8 * mn;	
	mn *= (cnt[8] + 1);

	res += rem * mn;
//	ass(res < MAX);
	return res;
}

void solve1() {
	fill_n(&dp[0], MAX, INF);
	dp[getstate(0, 0, 0, 0, 0)] = 0;
	for (int a = 0; a <= cnt[1]; a++) {
		for (int b = 0; b <= cnt[2]; b++) {
			for (int c = 0; c <= cnt[4]; c++) {
				for (int d = 0; d <= cnt[8]; d++) {
					for (int e = 0; e <= 7; e++) {
						int x = getstate(a, b, c, d, e);
						if (dp[x] == INF) {
							continue;
						}
						if (a + 1 <= cnt[1]) {						
							int add = 0;
							while ((e + add) % 1 != 0) {
								add++;
							}
							int e2 = (e + add + 1) % 8;
							int y = getstate(a + 1, b, c, d, e2);
							dp[y] = min(dp[y], dp[x] + add + 1);
						}
						if (b + 1 <= cnt[2]) {						
							int add = 0;
							while ((e + add) % 2 != 0) {
								add++;
							}
							int e2 = (e + add + 2) % 8;
							int y = getstate(a, b + 1, c, d, e2);
							dp[y] = min(dp[y], dp[x] + add + 2);
						}
						if (c + 1 <= cnt[4]) {						
							int add = 0;
							while ((e + add) % 4 != 0) {
								add++;
							}
							int e2 = (e + add + 4) % 8;
							int y = getstate(a, b, c + 1, d, e2);
							dp[y] = min(dp[y], dp[x] + add + 4);
						}
						if (d + 1 <= cnt[8]) {						
							int add = 0;
							while ((e + add) % 8 != 0) {
								add++;
							}
							int e2 = (e + add + 8) % 8;
							int y = getstate(a, b, c, d + 1, e2);
							dp[y] = min(dp[y], dp[x] + add + 8);
						}
					}
				}
			}
		}
	}
	double ans = INF;
	for (int e = 0; e <= 7; e++) {
		int add = 0;
		int x = getstate(cnt[1], cnt[2], cnt[4], cnt[8], e);
		while ((e + add) % maxsize != 0) {
			add++;
		}
		ans = min(ans, dp[x] + add);
	}
	printf("%lld", (ll) (ans + 0.5));
}

void solve2() {
	fill_n(&dp[0], MAX, -INF);
	dp[getstate(0, 0, 0, 0, 0)] = 0;
	for (int a = 0; a <= cnt[1]; a++) {
		for (int b = 0; b <= cnt[2]; b++) {
			for (int c = 0; c <= cnt[4]; c++) {
				for (int d = 0; d <= cnt[8]; d++) {
					for (int e = 0; e <= 7; e++) {
						int x = getstate(a, b, c, d, e);
						if (dp2[x] == -INF) {
							continue;
						}
						if (a + 1 <= cnt[1]) {						
							int add = 0;
							while ((e + add) % 1 != 0) {
								add++;
							}
							int e2 = (e + add + 1) % 8;
							int y = getstate(a + 1, b, c, d, e2);
							dp[y] = max(dp[y], dp[x] + add + 1);
						}
						if (b + 1 <= cnt[2]) {						
							int add = 0;
							while ((e + add) % 2 != 0) {
								add++;
							}
							int e2 = (e + add + 2) % 8;
							int y = getstate(a, b + 1, c, d, e2);
							dp[y] = max(dp[y], dp[x] + add + 2);
						}
						if (c + 1 <= cnt[4]) {						
							int add = 0;
							while ((e + add) % 4 != 0) {
								add++;
							}
							int e2 = (e + add + 4) % 8;
							int y = getstate(a, b, c + 1, d, e2);
							dp[y] = max(dp[y], dp[x] + add + 4);
						}
						if (d + 1 <= cnt[8]) {						
							int add = 0;
							while ((e + add) % 8 != 0) {
								add++;
							}
							int e2 = (e + add + 8) % 8;
							int y = getstate(a, b, c, d + 1, e2);
							dp[y] = max(dp[y], dp[x] + add + 8);
						}
					}
				}
			}
		}
	}
	double ans = -INF;
	for (int e = 0; e <= 7; e++) {
		int add = 0;
		int x = getstate(cnt[1], cnt[2], cnt[4], cnt[8], e);
		while ((e + add) % maxsize != 0) {
			add++;
		}
		ans = max(ans, dp[x] + add);
	}
	printf(" %lld", (ll) (ans + 0.5));
}

double const EPS = 1e-18;

void solve3() {
	fill_n(&dp[0], MAX, 0);
	fill_n(&dp2[0], MAX, 0);
	dp2[getstate(cnt[1], cnt[2], cnt[4], cnt[8], 0)] = 1;

	for (int a = cnt[1]; a >= 0; a--) {
		for (int b = cnt[2]; b >= 0; b--) {
			for (int c = cnt[4]; c >= 0; c--) {
				for (int d = cnt[8]; d >= 0; d--) {
					for (int e = 0; e <= 7; e++) {
						int rem = a + b + c + d;

						int x = getstate(a, b, c, d, e);
						if (dp2[x] < EPS) {
							continue;
						}

						if (a >= 1) {						
							double pr = (double) a / rem;
							int add = 0;
							while ((e + add) % 1 != 0) {
								add++;
							}
							int e2 = (e + add + 1) % 8;
							int y = getstate(a - 1, b, c, d, e2);
							dp[y] += pr * (dp[x] + dp2[x] * (add + 1));
							dp2[y] += dp2[x] * pr;
						}
						if (b >= 1) {
							double pr = (double) b / rem;
							int add = 0;
							while ((e + add) % 2 != 0) {
								add++;
							}
							int e2 = (e + add + 2) % 8;
							int y = getstate(a, b - 1, c, d, e2);
							dp[y] += pr * (dp[x] + dp2[x] * (add + 2));
							dp2[y] += dp2[x] * pr;
						}
						if (c >= 1) {
							double pr = (double) c / rem;
							int add = 0;
							while ((e + add) % 4 != 0) {
								add++;
							}
							int e2 = (e + add + 4) % 8;
							int y = getstate(a, b, c - 1, d, e2);
							dp[y] += pr * (dp[x] + dp2[x] * (add + 4));
							dp2[y] += dp2[x] * pr;
						}
						if (d >= 1) {
							double pr = (double) d / rem;
							int add = 0;
							while ((e + add) % 8 != 0) {
								add++;
							}
							int e2 = (e + add + 8) % 8;
							int y = getstate(a, b, c, d - 1, e2);
							dp[y] += pr * (dp[x] + dp2[x] * (add + 8));
							dp2[y] += dp2[x] * pr;
						}
					}
				}
			}
		}
	}
	//
	//
	double ans = 0;
	for (int e = 0; e <= 7; e++) {
		int add = 0;
		int x = getstate(0, 0, 0, 0, e);
		dbg(dp[x]);
		while ((e + add) % maxsize != 0) {
			add++;
		}
		ans += dp[x] + dp2[x] * add;
	}
	printf(" %.15lf\n", ans);
}

void solve() {
	solve1();
	solve2();
	solve3();
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("struct {");
	while (1) {
		string tmp = "";
		while (scanf(" %[^;]", str) == 1) {
			tmp += str;
			if (tmp.find(";") != string::npos) {
				break;
			}
		}
		scanf(";");
		dbg(tmp);

		if (tmp.find("}") != string::npos) {
			break;
		}

		if (tmp.find("*") != string::npos) {
			cnt[8]++;
			continue;
		}
		if (sz(tmp) >= 4 && tmp.substr(0, 4) == "char") {
			cnt[1]++;
			continue;
		}
		if (sz(tmp) >= 5 && tmp.substr(0, 5) == "short") {
			cnt[2]++;
			continue;
		}
		if (sz(tmp) >= 7 && tmp.substr(0, 7) == "int64_t") {
			cnt[8]++;
			continue;
		}
		if (sz(tmp) >= 3 && tmp.substr(0, 3) == "int") {
			cnt[4]++;
			continue;
		}
		if (sz(tmp) >= 5 && tmp.substr(0, 5) == "float") {
			cnt[4]++;
			continue;
		}		
		if (sz(tmp) >= 6 && tmp.substr(0, 6) == "double") {
			cnt[8]++;
			continue;
		}
		dbg("FREE LINE!\n");
	}
	dbg1(cnt, 8);

	fi(1, 8) {
		if (cnt[i]) {
			maxsize = i;
		}
	}

	solve();

	exit();
	return 0;
}



