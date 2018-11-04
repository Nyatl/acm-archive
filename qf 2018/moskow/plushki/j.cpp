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
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template<typename A, typename B>
ostream &operator <<(ostream &s, pair<A, B> v) {
	s << "(" << v.first << ", " << v.second << ")";
	return s;
}

template<typename T>
ostream &operator <<(ostream &s, set<T> v) {
	for (auto z : v) {
		s << z << " ";
	}
	return s;
}

template<typename T>
ostream &operator <<(ostream &s, vector<T> v) {
	for (auto z : v) {
		s << z << " ";
	}
	return s;
}

template<typename A, typename B>
ostream &operator <<(ostream &s, map<A, B> v) {
	for (auto z : v) {
		s << "(" << z.first << " -> " << z.second << "),";
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << #x << " : " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << #x << " : " << x << endl; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << #x << " : " << x << endl; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while (0) {}
#define dbg0(x, n) while (0) {}
#define dbg1(x, n) while (0) {}
#endif

///////////////////////////////////

#ifdef LOCAL
const int MAX = 100;
#else
const int MAX = 200 * 1000 + 41;
#endif

int n, m;

int D[MAX];
int E[MAX];
int a[MAX];
int b[MAX];
int rem[MAX];

vi devs[MAX];
vi tasks[MAX];

bool check(int k) {
	fill_n(&rem[0], MAX, k);
	
	ll q = 0;
	fdi(MAX - 1, 1) {
		for (int z : devs[i]) {
			q += rem[z];
			rem[z] = 0;
		}
		dbg(q);
		for (int z : tasks[i]) {
			if (rem[E[z]] > 0 && D[z] <= b[E[z]]) {
				rem[E[z]]--;
				continue;
			}
			if (q > 0) {
				q--;
				continue;
			}
			return false;
		}
	}
	return true;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &m);
	fi(1, n) {
		scanf("%d", &D[i]);
	}
	fi(1, n) {
		scanf("%d", &E[i]);
	}
	fi(1, m) {
		scanf("%d %d", &a[i], &b[i]);
	}
	
	fi(1, n) {
		tasks[D[i]].pb(i);
	}
	fi(1, m) {
		devs[a[i]].pb(i);
	}
	
	int l = 0;
	int r = MAX - 1;
	while (r - l > 1) {
		int h = (r + l) >> 1;
		if (check(h)) {
			r = h;
		} else {
			l = h; 
		}
	}
	
	if (r > n) {
		printf("-1\n");
	} else {
		printf("%d\n", r);
	}

	return 0;
}	