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
#define dbg0(x,n) while(0){}
#define dbg1(x,n) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "fraction"

const int MAX = 1500;
const int MAXD = 1200;
int n, k, r;

int bl;

int a[MAX];
int b[MAX];
int c[MAX];

vi ans;

void addOne(int pos) {
	a[pos]++;
	while (a[pos] > 1) {
		a[pos - 1] += a[pos] / 2;
		a[pos] %= 2;
		pos--;
	}
}

int divCheck(int pos) {
	if (pos <= 0) {
		return 0;
	}
	if (pos > 0) {
		if (a[pos - 1]) {
			return 1;
		}
	}
	fi(0, bl - 1) {
		if (a[pos + i] < b[i]) {
			return 0;
		}
		if (a[pos + i] > b[i]) {
			return 1;
		}
	}
	return 1;
}

void divRed(int pos) {
	int o = 0;
	fdi(bl - 1, 0) {
		a[pos + i] -= b[i];
		a[pos + i] -= o;
		if (a[pos + i] < 0) {
			a[pos + i] += 2;
			o = 1;
		} else {
			o = 0;
		}
	}
}

void div() {
	memset(c, 0, sizeof(c));
	fi (0, MAXD) {
		if (divCheck(i - bl + 1)) {
			c[i] = 1;
			divRed(i - bl + 1);
		} else {
			c[i] = 0;
		}
	}
	fi(0, MAX - 1) {
		a[i] = c[i];
	}
}


void mul(int x) {
	memset(c, 0, sizeof(c));
	fi(0, MAXD) {
		if (a[i]) {
			c[i] = x;
		}
	}
	fdi(MAXD, 0) {
		if (c[i] > 1) {
			c[i - 1] += c[i] / 2;
			c[i] %= 2;
		}
	}
	fi(0, MAX - 1) {
		a[i] = c[i];
	}
}

void rnd(int q) {
	if (a[q + 1]) {
		addOne(q);
	}
	fi(q + 1, MAX - 1) {
		a[i] = 0;
	}
}

void toBin(int x) {
	bl = 0;
	while (x) {
		b[bl] = x % 2;
		x /= 2;
		bl++;
	}
	reverse(b, b + bl);
}

int check(int x) {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	a[0] = 1;
	toBin(x);
	div();
	if (x == 40) {
		dbg0(a, 40);
	}
	rnd(n);
	if (x == 40) {
		dbg0(a, 40);
	}
	mul(x);
	if (x == 40) {
		dbg0(a, 40);
	}
	rnd(k);
	if (x == 40) {
		dbg0(a, 40);
	}
	if (a[0] != 1) return 1;
	fi(1, MAX - 1) {
		if (a[i]) return 1;
	}
	return 0;
}

void solve() {
	fi(1, r) {
		if (check(i)) {
			ans.pb(i);
		}
	}
	printf("%d\n", sz(ans));
	for (int z : ans) {
		printf("%d ", z);
	}
	printf("\n");
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%d %d %d", &n, &k, &r);
	solve();
	return 0;
}