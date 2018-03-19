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


/////////////////////////////////

int const MAXN = 15;
int const MASK = (1 << MAXN);
int const MAX = 241;

int n, m, x[MAX], y[MAX];
ll d[MAXN + 1][MASK];

bool bit(int m, int i) {
	return (m & (1 << i));
}

int a[MAXN];

int hacksort(int mask, int p) {
	fi(0, n - 1) {
		if (bit(mask, i)) {
			a[i] = 0;
		} else {
			a[i] = 2;
		}
	}
	a[p] = 1;
	fi(0, m - 1) {
		if (a[x[i]] > a[y[i]]) {
			swap(a[x[i]], a[y[i]]);
		}
	}		
	fi(0, n - 1) {
		if (a[i] == 1) {
			return i;
		}
	}
	assert(false);
	return 41;
}

void solve() {
	d[0][0] = 1;
	fi(0, n - 1) {
		for(int mask = 0; mask < (1 << n); mask++) {
			if (!d[i][mask]) continue;
			fj(0, n - 1) {
				if (!bit(mask, j)) {
					if (hacksort(mask, j) == i) {
						d[i + 1][(mask | (1 << j))] += d[i][mask];
					}
				}
			}
		}						
	}
	ll ans = 1;
	fi(1, n) {
		ans *= i;
	}
	ans -= d[n][(1 << n) - 1];
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%d %d", &n, &m);
	fi(0, m - 1) {
		scanf("%d %d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
	}
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}