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

int const MAX = 1e5 + 41;

int n, k;
int d[2][MAX];
int a[MAX];

int const INF = 1e9 + 41;

void solve() {
	fi(0, 1) {
		fj(0, MAX - 1) {
			d[i][j] = INF;
		}
	}
	sort(a + 1, a + n + 1);
	int m = (int) (unique(a + 1, a + n + 1) - a);
	n = m;
	d[0][0] = 0;
	fi(1, n) {
		memcpy(d[1], d[0], sizeof(d[0]));
		fo(0, 20) {			
			int q = (1 << o);
			fj(0, MAX - 1) {
				if (j + q * a[i] >= MAX) break;
				d[1][a[i] * q + j] = min(d[0][j] + q, d[1][a[i] * q + j]);
			}
		}
		memcpy(d[0], d[1], sizeof(d[1]));
	}
	int ans = INF;
	fi(k, MAX - 1) {
		ans = min(ans, d[0][i] + d[0][i - k]);		
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