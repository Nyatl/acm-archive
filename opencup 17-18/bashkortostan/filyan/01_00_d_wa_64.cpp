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

int const MAX = 7e3 + 41;

int n, k;
int d[MAX][MAX];
int a[MAX];

int const INF = 1e9 + 41;

void solve() {
	fi(0, MAX - 1) {
		fj(0, MAX - 1) {
			d[i][j] = INF;
		}
	}
	sort(a + 1, a + n + 1);
	int m = (int) (unique(a + 1, a + n + 1) - a);
	n = m;
	d[1][0] = 0;
	fi(1, n) {
		memcpy(d[i + 1], d[i], sizeof(d[i]));
		fj(0, MAX - 1) {
			fo(1, MAX - 1) {
				if (j + o * a[i] >= MAX) break;
				d[i + 1][a[i] * o + j] = min(d[i][j] + o, d[i + 1][a[i] * o + j]);
			}
		}
	}
	int ans = INF;
	fi(k, MAX - 1) {
		ans = min(ans,	 d[n + 1][i] + d[n + 1][i - k]);		
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