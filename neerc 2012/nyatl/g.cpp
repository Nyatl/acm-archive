#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define cpy(x, y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back

template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> &p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> &v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 0; ABC < n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 1; ABC <= n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "great"

#define MAX 100

ll n, k;
ll len;
ll a[MAX];
ll a2[MAX];
ll p[MAX];

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	ll x = n;
	ll c = 0;
	while (x) {
		c++;
		a[c] = x % k;
		x /= k;
	}
	len = c;

	reverse(a + 1, a + len + 1);

	dbg1(a, len);

	ll f = 0;
	ll q = 0;
	fi(1, len) {
		if (i % 2 == len % 2) {
			q++;			
			a2[q] = f ? k - 1 : a[i];
		} else {
			if (a[i] > 0) f = 1;
		}
	}

	cpy(a, a2);
	len = q;

	dbg1(a, len);
	
	p[len] = 1;
	fdi(len - 1, 1) {
		p[i] = p[i + 1] * k;
	}
	ll ans = 0;
	fi(1, len) {
		ans += a[i] * p[i];
	}
	printf("%lld\n", ans + 1);
	return 0;
}