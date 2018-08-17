#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back

template<typename T>
ostream& operator<<(const ostream& os, const vector<T> &v) {
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
#define dbg0(x) while(0){}
#define dbg1(x) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "wall"

#define MAX 100100

int n;
int m;
ll a[MAX];
ll b[MAX];

bool check(ll H) {
	int c;
	c = 1;
	fi(1, n) {
		if (a[i] < H) {
			while (1) {
				if (c > m) return false;
				if (a[i] + b[c] >= H) {
					c++;
					break;
				}
				c++;
			}
		}
	}
	return true;
}

vpii get_answer(ll H) {
	int c;
	vpii res;
	c = 1;
	fi(1, n) {
		if (a[i] < H) {
			while (1) {
				if (c > m) assert(0);
				if (a[i] + b[c] >= H) {
					res.pb(mp(i, c));
					c++;
					break;
				}
				c++;
			}
		}
	}
	return res;
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%d", &n);
	fi(1, n) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &m);
	fi(1, m) {
		scanf("%lld", &b[i]);
	}
	ll l = 1, r = 1'000'000'000'000'000'000LL;
	while (l < r) {
		ll h = (l + r) / 2 + 1;
		if (check(h)) {
			l = h;
		} else {
			r = h - 1;
		}
	}
	vpii ans = get_answer(l);
	printf("%lld %d\n", l, sz(ans));
	fi(0, sz(ans) - 1) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}