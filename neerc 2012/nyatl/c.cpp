#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
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

#define TASK "caravan"

#define MAX 100100

int n;
vpii v;

bool check(double len) {
	double last = 0;
	fi(0, sz(v) - 1) {
		double l = v[i].first;
		l = max(l, last);
		double r = l + len;
		if (r > v[i].second) return false;
		last = r;
	}
	return true;
}

double ans;
ll ans1 = 1, ans2 = 1;

void relax(ll a, ll b) {
	if (fabs((double)a / b - ans) < fabs((double)ans1 / ans2 - ans)) {
		ans1 = a;
		ans2 = b;
	}
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%d", &n);
	fi(1, n) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.pb(mp(a, b));
	}
	sort(all(v));
	double l, r;
	l = 0;
	r = 1000000;
	fi(1, 60) {
		double h = (l + r) / 2;
		if (check(h)) {
			l = h;
		} else {
			r = h;
		}
	}

	ans = (l + r) / 2;

	dbg(ans);

	fj(1, 100000) {
		ll x = (int)(ans * j);
		fi(x - 10, x + 10) {
			relax(i, j);
		}
	}

	printf("%lld/%lld\n", ans1, ans2);
	return 0;
}