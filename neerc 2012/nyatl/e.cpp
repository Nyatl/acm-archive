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

#define TASK "exact"

#define MAX 101000

ll x, n;

ll p10[MAX];

struct Box {
	ll p;
	ll q;
	ll num;
	Box() {
	}
	Box(ll p, ll q, ll num):p(p), q(q), num(num) {}
	bool operator<(const Box &b) const {
		return p10[p] * q > p10[b.p] * b.q;
	}
};

vector<Box> box[MAX];

ll a[MAX];
ll c[MAX];
ll k;
ll cur = 0;
vector<ll> ans;

void init() {
	p10[0] = 1;
	fi(1, 18) {
		p10[i] = p10[i - 1] * 10;
	}
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%lld %lld", &x, &n);
	fi(1, n) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		box[a].pb(Box(a, b, i));
	}

	init();

	k = -1;
	while (x) {
		k++;
		a[k] = x % 10;
		x /= 10;
	}

	fi(0, 18) {
		sort(all(box[i]));
	}

	dbg0(a, k + 1);

	fi(0, k) {
		while (cur < a[i] * p10[i]) {
			if (c[i] == sz(box[i])) {
				printf("-1\n");
				return 0;
			}
			ans.pb(box[i][c[i]].num);
			cur += p10[box[i][c[i]].p] * box[i][c[i]].q;
			c[i]++;
		}
		cur -= a[i] * p10[i];
		fj(c[i], sz(box[i]) - 1) {
			box[i + 1].pb(box[i][j]);
		}
		sort(all(box[i + 1]));
	}

	printf("%d\n", sz(ans));
	for (ll z : ans) {
		printf("%lld ", z);
	}
	printf("\n");
	return 0;
}