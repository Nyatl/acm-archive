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

#define TASK "game"

const int MAX = 400005;

int n, m, k;

int fenN;

int fen[MAX];

void init(int n) {
	fenN = n;
	fi(0, n) {
		fen[i] = 0;
	}
}

void add(int x) {
	for (;x <= n; x |= (x + 1)) {
		fen[x]++;
	}
}

int sum(int x) {
	int res = 0;
	for (;x >= 0; x = (x & (x + 1)) - 1) {
		res += fen[x];
	}
	return res;
}

int sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int a[MAX];

vi pos[MAX];

bool check(int H) {
	init(n + 10);
	fdi(H, 1) {
		int f = 0;
		fdj(sz(pos[i]) - 1, 0) {
			int x = pos[i][j];
			if (sum(x) < k) {
				add(x);
				f = 1;
				break;
			}
		}
		if (!f) return false;
	}
	return true;
}

void solve() {
	fi(1, n) {
		pos[i].clear();
	}

	fi(1, n) {
		a[i] = min(a[i], n + 1);
		pos[a[i]].pb(i);
	}

	int l = 0;
	int r = min(n, m);
	while (l < r) {
		int h = (l + r) / 2 + 1;
		if (check(h)) {
			l = h;
		} else {
			r = h - 1;
		}
	}
	printf("%d\n", l);
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);

	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		fi(1, n) {
			scanf("%d", &a[i]);
		}
		solve();
	}
	return 0;
}