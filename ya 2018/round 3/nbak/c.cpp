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

const int MAX = 200000 + 5;

ll n, h;
ll x[MAX];
ll y[MAX];

vl v1o, v1e, v2o, v2e;

ll ans;

ll calc(vl & v1, vl & v2) {
	if (sz(v1) == 0 || sz(v2) == 0) {
		return 0;
	}
	ll res = 0;
	fi (0, sz(v1) - 1) {
		auto it1 = lower_bound(all(v2), v1[i] + 1);
		auto it2 = lower_bound(all(v2), v1[i] - (h - 1) - (h - 1) - 1);
		res += (it1 - it2);
	}
	return res;
}

void solve() {
	scanf("%lld%lld", &n, &h);
	fi(1, n) {
		scanf("%lld%lld", &x[i], &y[i]);
	}
	ans = 2 * n * (h);
	fi(1, n) {
		ll s = x[i] + y[i];
		if (s % 2) {
			v1o.pb(s);
		} else {
			v1e.pb(s);
		}
	}
	fi(1, n) {
		ll s = x[i] - y[i];
		if (s % 2) {
			v2o.pb(s);
		} else {
			v2e.pb(s);
		}
	}
	sort(all(v1o));
	sort(all(v1e));
	sort(all(v2o));
	sort(all(v2e));
	dbg(v1o);
	dbg(v1e);
	dbg(v2o);
	dbg(v2e);
	ans -= n;
	ans -= calc(v1o, v2o);
	ans -= calc(v1e, v2e);
	printf("%lld", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}