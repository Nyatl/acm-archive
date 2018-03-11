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

#define MAX 110

int n, k, m;

int h0[MAX][MAX];
int h[MAX][MAX];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inside(int x, int y) {
	if (x < 1 || x > n) return false;
	if (y < 1 || y > n) return false;
	return true;
}

int a[MAX][MAX], b[MAX][MAX];

void solve() {
	queue<pii> qu;
	fj(1, n) {
		fi(1, n) {
			if (h[j][i] != -1) {
				qu.push(mp(i, j));
				a[j][i] = h[j][i];
				b[j][i] = h[j][i];				
			} else {
				a[j][i] = 0;
				b[j][i] = 1000000000;
			}
		}
	}
	
	dbg(a[3][3]);
	dbg(b[3][3]);
	
	while (!qu.empty()) {
		pii p = qu.front();
		int x = p.first;
		int y = p.second;
		qu.pop();		
		fi(0, 3) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (!inside(x2, y2)) continue;
			int a2 = max(a[y][x] - m, a[y2][x2]);
			int b2 = min(b[y][x] + m, b[y2][x2]);
			if (a2 != a[y2][x2] || b2 != b[y2][x2]) {
				a[y2][x2] = a2;
				b[y2][x2] = b2;
				qu.push(mp(x2, y2));
			}
		}
	}
	
	fj(1, n) {
		fi(1, n) {
			err("%d-%d", a[j][i], b[j][i]);
		}
		errln();
	}
	errln();	
	
	fj(1, n) {
		fi(1, n) {
			h[j][i] = a[j][i];
		}
	}
	
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	memset(h, -1, sizeof(h));
	
	scanf("%d %d %d", &n, &m, &k);

	fi(1, k) {
		int x, y, t;
		scanf("%d %d %d", &y, &x, &t);
		h[y][x] = t;		
	}

	cpy(h0, h);		
	
	solve();
	
	fj(1, n) {
		fi(1, n) {
			fo(0, 3) {
				int x2 = i + dx[o];
				int y2 = j + dy[o];
				if (inside(x2, y2) && abs(h[j][i] - h[y2][x2]) > m || h0[j][i] != -1 && h[j][i] != h0[j][i]) {
					printf("NO\n");
					return 0;
				}
			}
		}
	}

	printf("YES\n");

	fj(1, n) {
		fi(1, n) {
			printf("%d ", h[j][i]);
		}
		printf("\n");
	}
		
	exit();
	return 0;
}
