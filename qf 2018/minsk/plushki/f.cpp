#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define fi(a, b) for (int i = a; i <= b; i++) 
#define fj(a, b) for (int j = a; j <= b; j++) 
#define fo(a, b) for (int o = a; o <= b; o++)
#define fdi(a, b) for (int i = a; i >= b; i--) 
#define fdj(a, b) for (int j = a; j >= b; j--) 
#define fdo(a, b) for (int o = a; o >= b; o--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


template<typename A, typename B>
ostream& operator<<(ostream &s, pair<A, B> v) {
	s << "(" << v.first << ", " << v.second << ")" << endl;
	return s;
}

template<typename T>
ostream& operator<<(ostream &s, vector<T> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream &s, set<T> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}
/*
template<typename A, typename B>
ostream& operator<<(ostream &s, map<A, B> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}*/

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#else
#define err(...) while (0) {}
#define dbg(x) while (0) {}
#endif 

//////////////////////

const int MAX = 500005;

//fen
ll F[MAX];

void build() {
	memset(F, 0, sizeof(F));
}

void update(int x, int v) {
	while (x < MAX) {
		F[x] += v;
		x |= (x + 1);
	}
}

ll getsum(int x) {
	ll res = 0;
	while (x >= 1) {
		res += F[x];
		x = (x & (x + 1)) - 1;
	}
	return res;
}

//end fen

int n;

int p[3][MAX];

int p2[3][MAX];

ll get(int c1, int c2) {
	ll res = 0;
	build();
	fi(1, n) {
		int pos = p2[c2][p[c1][i]];
		update(pos, 1);
		res += getsum(pos - 1);
	}
	return res;
}

void solve() {
	ll ans = 0;
	ll A = get(0, 1);
	ll B = get(1, 2);
	ll C = get(0, 2);
	dbg(A);
	dbg(B);
	dbg(C);
	ans -= (ll)n * (n - 1) / 2;
	ans += A;
	ans += B;
	ans += C;
	ans /= 2;	
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	fj(0, 2) {
		fi(1, n) {
			scanf("%d", &p[j][i]);
		}
	}
	fj(0, 2) {
		fi(1, n) {
			p2[j][p[j][i]] = i;
		}
	}
	solve();
	return 0;
}
