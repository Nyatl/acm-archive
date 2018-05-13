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

int const MAX = 1e3 + 41;

int n;
string a[MAX];
string b[MAX];

void solve() {
	map<string, int> q;
	fi(1, n) {
		q[a[i]] = 0;
		q[b[i]] = 0;
	}
	fi(1, n) {
		q[b[i]] ^= 1;
	}
	vector<string> ans;
	int b = -1;
	for (auto z : q) {
		if (z.second > b) {
			b = z.second;
			ans.clear();
			ans.pb(z.first);
		} else if (z.second == b) {
			ans.pb(z.first);
		}
	}
	sort(ans.begin(), ans.end());
	for (string z : ans) {
		cout << z << endl;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	fi(1, n) {
		cin >> a[i] >> b[i];
	}  
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}