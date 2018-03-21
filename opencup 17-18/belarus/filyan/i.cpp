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

/////////////////////////////////

int const MAX = 1000 * 1000 + 41;
int const INF = 1000 * 1000 * 1000 + 41;

int n;
int a[MAX];
int pl[MAX];
int pr[MAX];
int nxt[MAX];
ll ans;

void calcleft() {
	vpii st;
	fi(1, n) {
		while (sz(st) > 0 && st.back().first < a[i]) {
			st.pop_back();
		}
		if (!sz(st)) {
			pl[i] = 1;
		} else {
			pl[i] = st.back().second + 1;
		}
		st.pb(mp(a[i], i));
	}
}

void calcright() {
	vpii st;
	fdi(n, 1) {
		while (sz(st) > 0 && st.back().first < a[i]) {
			st.pop_back();
		}
		if (!sz(st)) {
			pr[i] = n;
		} else {
			pr[i] = st.back().second - 1;
		}
		st.pb(mp(a[i], i));
	}
}

int lst[MAX];

void calcnxt() {
	fi(0, MAX - 1) {
		lst[i] = INF;
	}	
	fdi(n, 1) {
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
}

namespace SPT {
	int const LOGN = 20;
	int spt[MAX][LOGN];
	int deg[MAX];

	void build() {
		fi(0, LOGN - 1) {
			deg[(1 << i)] = i;
		}
		fi(1, MAX - 1) {
			if (!deg[i]) deg[i] = deg[i - 1];
		}
		fi(1, n) {
			spt[i][0] = nxt[i];
		}
		fj(1, LOGN - 1) {
			for(int i = 1; i + (1 << j) - 1 <= n; i++) {
				spt[i][j] = min(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	int getmin(int l, int r) {
		int d = deg[r - l + 1];
		return min(spt[l][d], spt[r - (1 << d) + 1][d]);
	}
};

int res[MAX];
int f[MAX];

void buildf() {
	fi(1, n) {
		int l = -1;
		int r = n - i + 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (SPT::getmin(i, i + m) <= i + m) {
				r = m;
			}	else {
				l = m;
			}
		}
		f[i] = l + 1;
	}
}

struct Event {
	int p, x, s;
	Event() {};
	Event(int p, int x, int s) : p(p), x(x), s(s) {};
};

vector<Event> e[MAX];

namespace Fen {
	int F[MAX];

	void add(int x, int v) {
		while (x < MAX) {
			F[x] += v;
			x |= (x + 1);
		}
	}

	int get(int x) {
		int res = 0;
		while (x > 0) {
			res += F[x];
			x = (x & (x + 1)) - 1;
		}
		return res;
	}
};

void solve() {
	calcleft();
	calcright();
	calcnxt();
	SPT::build();
	buildf();
	/*
	fi(1, n) {
		err("f[%d] = %d\n", i, f[i]);
	}
	*/
	fi(1, n) {
		int l = max(pl[i], i - a[i] + 1);
		int r = min(pr[i], i + a[i] - 1) - a[i] + 1;
		if (l > r) continue;
//		err("i = %d l = %d r = %d\n", i, l, r);
		e[l - 1].pb(Event(i, a[i] - 1, 1));
		e[l - 1].pb(Event(i, MAX - 1, -1));
		e[r].pb(Event(i, a[i] - 1, -1));
		e[r].pb(Event(i, MAX - 1, 1));
	}
	fi(1, n) {
		Fen::add(f[i], 1);
		for (Event z : e[i]) {
			int v = Fen::get(z.x) * z.s;
			res[z.p] += v;
		}
	}
	fi(1, n) {
		ans += res[i];
	}
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}