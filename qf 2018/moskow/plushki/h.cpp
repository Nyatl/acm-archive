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
#define dbg(x) {cerr << __LINE__ << "\t" << #x << " : " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ <<  "\t" << #x << " : " << x << endl; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << " : " << x << endl; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while (0) {}
#define dbg0(x, n) while (0) {}
#define dbg1(x, n) while (0) {}
#endif

///////////////////////////////////

const int MAX = 10 * 1000 + 41;

int n;

int cnt[MAX];

ll calc(vi &per) {
	fi(0, sz(per) - 1) {
		ll dist = i + per[i] - 1;
		cnt[per[i]] = sqrt((double)dist);
	}
	ll res = 0;
	fi(1, n) {
		res += cnt[i];
	}
	return res;
}

void printans(vi &ans) {
	int tmp = calc(ans);
	printf("%d\n", tmp + sz(ans));
	fi(1, n) {
		fj(1, cnt[i]) {
			printf("%d ", i);
		}
	}
	fdi(n - 1, 0) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

void solve () {
	vi per;
	int c = 1;
	fi(1, 200) {
		int c2 = c + i;
		fdj(c2 - 1, c) {
			per.pb(j);
		}
		c = c2;
	}
	dbg(sz(per));
	vi per2;
	for (int z : per) {
		if (z <= n) per2.pb(z);
	}
	printans(per2);
}


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	solve();
	return 0;
}