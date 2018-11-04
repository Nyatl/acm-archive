#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define fi(a, b) for (int i = a; i <= b; i++)
#define fj(a, b) for (int j = a; j <= b; j++)
#define fo(a, b) for (int o = a; o <= b; o++)
#define fdi(a, b) for (int i = a; i >= b; i--)
#define fdj(a, b) for (int j = a; j >= b; j--)
#define fdo(a, b) for (int o = a; o >= b; o--)
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template<typename T>
ostream &operator <<(ostream &s, vector<T> v) {
	for (auto z : v) {
		s << z << " ";
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << #x << " : " << x << endl;}
#else
#define dbg(x) while (0) {}
#endif

///////////////////////////////////  

bool check(vi &a) {
	fi(0, sz(a) - 1) {
		if (a[i] != a[sz(a) - 1 - i]) {
			return false;
		}
	}
	return true;
}

vi a;

void print(int num, int val) {
	vi a = ::a;
	a.insert(a.begin() + num, val);
	dbg(a);
	if (check(a)) {
		printf("%d %d\n", num, val);
		exit(0);
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	fi(1, n) {
		int tmp;
		scanf("%d", &tmp);
		a.pb(tmp);
	}
	//a2 = a;
	//reverse(a2.begin(), a2.end());
	
	if (check(a)) {
		print(sz(a) / 2, a[sz(a) / 2]);
	}

	fi(0, sz(a) / 2) {
		if (a[i] != a[sz(a) - i - 1]) {
			print(i, a[sz(a) - i - 1]);
			print(sz(a) - i, a[i]);
			break;
		}
	}
	
	
	printf("-1\n");
}  

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}