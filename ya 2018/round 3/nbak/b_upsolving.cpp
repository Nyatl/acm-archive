#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#ifndef LOCAL
typedef __int128 lll;
#else
typedef long long lll;
#endif


template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	for (T z : v) s << z << " ";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, deque<T> v) {
	for (T z : v) s << z << " ";
	return s;
}


template<typename T1, typename T2>
ostream& operator<<(ostream& s, pair<T1, T2> v) {
	s << v.first << " " << v.second;
	return s;
}

#define sz(a) (int)((a).size())
#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fj(a,b) for(int j = (a); j <= (b); ++j)
#define fo(a,b) for(int o = (a); o <= (b); ++o)
#define fdi(a,b) for(int i = (a); i >= (b); --i)
#define fdj(a,b) for(int j = (a); j >= (b); --j)
#define fdo(a,b) for(int o = (a); o >= (b); --o)
#define all(a) (a).begin(),(a).end()

#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << '\t' << #x << ":" << x << endl
#define dbg0(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=0; ABC<n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=1; ABC<=n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while(false) {}
#define dbg0(x, n) while(false) {}
#define dbg1(x, n) while(false) {}
#endif 

const int MAX = 100000 + 5;

const double EPS = 1e-9;

int n;
ll a[MAX];

pair<ll, double> calc(ll x, double m) {
	dbg(x);
	if (x == 0) {
		if (m > -EPS) {
			return {-1, -1};
		} else {
			return {0, m};
		}
	}
	double xl = log2(x);
	dbg(xl);
	if (m < xl + EPS) {
		dbg(1);
		return {0, xl};
	}
	ll ret = 0;
	ret = ceil(m - xl);
	xl += ret;
	dbg(2);
	return {ret, xl};
}

void solve() {
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
	ll ans = 0;
	double cur = -1e18;
	fi(1, n) {
		auto p = calc(a[i], cur);
		if (p.first == -1) {
			printf("-1\n");
			return;
		}
		dbg(p);
		ans += p.first;
		cur = p.second;
	}
	
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}