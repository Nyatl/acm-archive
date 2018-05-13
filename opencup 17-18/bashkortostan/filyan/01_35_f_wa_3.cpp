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

int const MAX = 1e4 + 41;

int n, m;
set<int> e[MAX];

int u[MAX];
int ans;
vi st;

void dfs(int x) {
	st.pb(x);
	u[x] = 1;
	for (int y : e[x]) {
		if (u[y]) continue;
		dfs(y);
	}
}



int calc(vi v) {
	if (sz(v) < 4) return 0;
	for (int x : v) {
		if (sz(e[x]) > 4) return 0;
	}
	//
	err("hi\n");
	for (int x : v) {
		err("%d ", x);
	}
	err("\n");
	//
	int root = -1;
	for (int x : v) {
		if (sz(e[x]) == 3) {
			root = x;
		}
	}
	if (root == -1) return 0;
	int x = root;
	while (1) {
		err("x = %d\n", x);
		if (sz(e[x]) != 3) return 0;
		int l = 0;
		for (int y : e[x]) {
			if (sz(e[y]) == 1) {
				l++;
				e[y].erase(x);
			}
		}
		if (l != 2) {
			if (l != 3) return 0;
			break;
		}
		int z = -1;
		for (int y : e[x]) {
			if (sz(e[y]) != 1) {
				z = y;
			}
		}
		x = z;
	}
	return 1;
}

void solve() {
	fi(1, n) {
		if (!u[i]) {
			st.clear();
			dfs(i);
			ans += calc(st);
		}
	}
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	fi(1, m) {
		int x, y;
		scanf("%d %d", &x, &y);
		e[x].insert(y);
		e[y].insert(x); 
	}  
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}