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
typedef unsigned int uint;

/////////////////////////////////

int const MOD = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

unordered_map<uint, int> d;
int n;
int req;

int qbit(uint m) {
	return __builtin_popcount(m);
} 

bool bit(uint m, int i) {
	return (1 & (m >> i));
}

uint f;

int rec(uint mask) {
	if (qbit(mask) > req) return 0;
	if (f == mask) {
		return 1;
	}
	if (d.find(mask) != d.end()) {
		return d[mask];
	}
	int res = 0;
	if (!bit(mask, n - 1) && !bit(mask, n - 2)) {
		uint nmask = mask;
		nmask ^= (1 << (n - 1));
		res = add(res, rec(nmask));
	}
	fi(0, n - 3) {
		if (!bit(mask, i) && !bit(mask, i + 1) && bit(mask, i + 2)) {
			uint nmask = mask;
			nmask ^= (1 << (i + 2)) ^ (1 << (i + 1));
			res = add(res, rec(nmask));
		}
	}
	d[mask] = res;
	return res;
}

int ans[41];

void solve() {
/*
	f = 0;
	for (int i = 1; i < n; i += 2) {
		f ^= (1 << i);
	}
	d.clear();
	req = n / 2;
	err("%d %d\n", n, rec(0));	
	printf("ans[%d] = %d;\n", n, rec(0));
	*/
ans[3] = 1;
ans[4] = 1;
ans[5] = 2;
ans[6] = 5;
ans[7] = 33;
ans[8] = 319;
ans[9] = 9666;
ans[10] = 484101;
ans[11] = 86126251;
ans[12] = 921102616;
ans[13] = 690667755;
ans[14] = 277772735;
ans[15] = 168927647;
ans[16] = 863966777;
ans[17] = 656710249;
ans[18] = 529211723;
ans[19] = 952552517;
ans[20] = 226276192;
ans[21] = 197949884;
ans[22] = 305182080;
ans[23] = 473057943;
ans[24] = 9119576;
ans[25] = 607610013;
ans[26] = 800401364;
ans[27] = 125881901;
ans[28] = 404394074;
ans[29] = 47341655;
ans[30] = 126866039;
ans[31] = 937077929;
ans[32] = 680342212;
	printf("%d\n", ans[n]);

}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*
	for (n = 3; n <= 32; n++) {
		err("n = %d\n", n);
		solve();		 	
	}  
	*/
	scanf("%d", &n);
	solve();
	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}