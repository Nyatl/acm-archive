#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define sz(x) (int)x.size()
#define mp(a, b) make_pair(a, b)
#define pb push_back

template<typename T>
ostream& operator<<(const ostream& os, const vector<T> &v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl;
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 0; ABC < n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 1; ABC <= n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x) while(0){}
#define dbg1(x) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "notation"

const int MAX = 1000;

ll x;

int a[MAX];

void solve() {
	if (x == 0) {
		printf("1\n0\n");
		return;
	}
	ll x0 = x;
	x = abs(x);
	int c = 0;
	while (x) {
		if (x & 1) {

		if (x0 > 0) {
			if (c % 2 == 0) {
				a[c]++;
			} else {
				a[c]++;
				a[c + 1]++;
			}
		} else {
			if (c % 2 == 0) {
				a[c]++;
				a[c + 1]++;
			} else {
				a[c]++;
			}
		}
	}
		c++;
		x >>= 1;
	}
	fi(0, MAX - 1) {
		if (a[i] > 1) {
			int b = a[i] / 2;
			a[i] %= 2;
			a[i + 1] += b;
			a[i + 2] += b;
		}
	}
	int n = 0;
	fi(0, MAX - 1) {
		if (a[i]) {
			n = i + 1;
		}
	}
	printf("%d\n", n);
	fi(0, n - 1) {
		printf("%d ", a[i]);
	}
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%lld", &x);
	solve();
	return 0;
}