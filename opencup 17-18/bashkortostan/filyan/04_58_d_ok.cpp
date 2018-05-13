#include <bits/stdc++.h> 
using namespace std;

#define sz(x) (int)x.size() 
#define pb push_back 
#define mp make_pair 
#define fi(a, b) for(int i=a; i<=b; i++) 
#define fj(a, b) for(int j=a; j<=b; j++) 
#define fo(a, b) for(int o=a; o<=b; o++) 
#define fdi(a, b) for(int i=a; i>=b; i--) 
#define fdj(a, b) for(int j=a; j>=b; j--) 
#define fdo(a, b) for(int o=a; o>=b; o--) 

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) while(false) {}
#endif

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef vector<int> vi; 
typedef vector<pii> vpii; 
typedef vector<pll> vpll; 
typedef long double ld;
typedef unsigned long long ull;

/////////////////////////////////

int const MAX = 1e6 + 41;

int n, k;
int d[MAX];
int a[MAX];

int const INF = 1e9 + 41;

int ans;

int u[MAX];

int const M = 8e3 + 41;

int dp[2][M];

void calcdp() {
	fi(0, M - 1) {
		dp[0][i] = dp[1][i] = INF;
	}
	dp[0][0] = 0;
	
	fi(1, n) {
		memcpy(dp[1], dp[0], sizeof(dp[0]));
		fo(0, M - 1) {			
			int q = (1 << o);
			if (q > k) break;
			fj(0, M - 1) {
				if (j + q * a[i] >= M) break;
				dp[1][a[i] * q + j] = min(dp[1][j] + q, dp[1][a[i] * q + j]);
			}
		}
		memcpy(dp[0], dp[1], sizeof(dp[1]));
	}

	fi(k, M - 1) {
		ans = min(ans, dp[0][i] + dp[0][i - k]);
	}
}

void solve() {	
	fi(0, MAX - 1) {
		d[i] = INF;
	}
	sort(a + 1, a + n + 1);
	int m = (int) (unique(a + 1, a + n + 1) - a);
	n = m;
	ans = k;

	calcdp();

	d[0] = 0;
	set<pii> t;
	t.insert(mp(0, 0));
	while (sz(t)) {
		pii x = (*t.begin());
		if (x.first >= ans) break;
		t.erase(t.begin());
		if (u[x.second]) continue;		
		fi(1, n) {
			fo(0, 20) {
				int q = (1 << o);
				if (q + x.first >= ans) break;
				if (x.second + q * a[i] >= MAX) break;
				if (d[x.second + q * a[i]] > x.first + q) {
					d[x.second + q * a[i]] = x.first + q;
					t.insert(mp(d[x.second + q * a[i]], x.second + q * a[i]));
				}				
			}			
			fo(0, 20) {
				int q = (1 << o);
				if (q + x.first >= ans) break;
				if (x.second - q * a[i] < 0) break;
				if (d[x.second - q * a[i]] > x.first + q) {
					d[x.second - q * a[i]] = x.first + q;
					t.insert(mp(d[x.second - q * a[i]], x.second - q * a[i]));
				}				
			}						
		}
		u[x.second] = 1;
	}
	fi(k, MAX - 1) {
		ans = min(ans, d[i] + d[i - k]);
	}
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &k);
	fi(1, n) {
		scanf("%d", &a[i]);
	}  
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}