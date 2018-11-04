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

ll n, m, t;

ll calcmax() {
	return t / n * m + min(t % n, m);
}

ll calcmin() {
	return t / n * m + max(t % n + m - n, 0LL);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t0;
	scanf("%lld %lld %lld", &n, &m, &t0);
	t = t0 / 5;
	ll max1 = calcmax() * 5;
	ll min1 = calcmin() * 5;
	t = t0 / 5 + 1;
	ll max2 = calcmax() * 5;
	ll min2 = calcmin() * 5;
	ll ans2;
	if (max1 == max2) {
		ans2 = max1;
	} else {
		ans2 = max1 + t0 % 5;
	}
	ll ans1;
	if (min1 == min2) {
		ans1 = min1;
	} else {
		ans1 = min1 + t0 % 5;
	}
	
	printf("%lld %lld\n", ans1, ans2);

	return 0;
}