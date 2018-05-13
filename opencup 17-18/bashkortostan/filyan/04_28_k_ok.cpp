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
int const MAGIC = 41;

ll d[MAX];
int f[MAX];
int a, b;

ll d2[MAX];
int d2f[MAX];

void init() {
	/*
	fi(3, MAX - 1) {
		fj(1, i) {
			if (j * 2 >= i) break;
			ll val = 4 * d[j]	+ (ll) j * (ll) (i - 2 * j) * (ll) (i - 2 * j);
			if (val > d[i]) {
				d[i] = val;
				f[i] = j;
			}
		}
	}
	*/
	/*
	fi(3, 5000) {
		err("i = %d f = %d %.5Lf\n", i, f[i], (ld) i / f[i]);
	}
	*/
	fi(3, MAX - 1) {
		d2f[i] = d2f[i - 1];
		ll x = d2f[i];
		ll val = 4 * d2[x] + x * (i - 2 * x) * (i - 2 * x);
		d2[i] = val;
		if ( (x + 1) * 2 < i) {
			x++;
			ll val2 = 4 * d2[x] + x * (i - 2 * x) * (i - 2 * x);
			if (val2 > d2[i]) {
				d2[i] = val2;
				d2f[i] = x;
			}
		}
	}
}

ll ans;

void solve() {		
	ans = 0;
	int l = 0;
	int r = a / 2;
	if (r * 2 == a) r--;
	while (r - l > MAGIC) {
		int l1 = (r - l) / 3 + l;
		int r1 = r - (r - l) / 3;
		ll na1 = a - l1 * 2;
		ll nb1 = b - l1 * 2;
		ll val1 = l1 * na1 * nb1 + 4 * d2[l1];

		ll na2 = a - r1 * 2;
		ll nb2 = b - r1 * 2;
		ll val2 = r1 * na2 * nb2 + 4 * d2[r1];

		if (val1 < val2) {
			l = l1;
		}	else {
			r = r1;
		}
	}
//	err("l = %d r = %d\n", l, r);
	fi(l, r) {
		ll x = i;
		if (x * 2 >= a) break;
		ll na = a - x * 2;
		ll nb = b - x * 2;
		ll val = na * nb * x + 4 * d2[i];
		ans = max(ans, val);
	}
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	init();
	int t;
	scanf("%d", &t);
	while (t--) {  
		scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		solve();		
	}

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}