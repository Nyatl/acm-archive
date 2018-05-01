#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;


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

const int MAX = 100 + 5;

const ll INF = 1000000000LL * 1000000LL;
ll sum = 0;
ll mmax[MAX];
ll mcur[MAX];

pii rec[MAX];

int n;

int check0() {
	fi(1, n) {
		if (mmax[i] < mcur[i]) {
			return i;
		}
	}
	return -1;
}

int check00() {
	fi(1, n) {
		if (mcur[i] > INF) return i;
		if (mcur[i] < 0) return i;
	}
	ll cursum = 0;
	fi(1, n) {
		cursum += mcur[i];
	}
	dbg(cursum);
	dbg(sum);
	if (cursum > sum) {
		return n + 1;
	}
	return -1;
}

bool check(ll g) {
	dbg(g);
	mcur[1] = g;
	fi(2, n) {
		mcur[i] = 0;
	}
	fi(1, 200) {
		int pos = check0();
		if (pos == -1) {
			return true;
		}
		if (rec[pos].first == pos) return false;
		if (rec[pos].second == pos) return false;
		ll cnt = mcur[pos] - mmax[pos];
		mcur[pos] = mmax[pos];
		mcur[rec[pos].first] += cnt;
		mcur[rec[pos].second] += cnt;
		dbg1(mcur, n);
		if (check00() > 0) {
			return false;
		}
	}
	return false;
}

void solve() {
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d%d", &rec[i].first, &rec[i].second);
	}

	fi(1, n) {
		scanf("%lld", &mmax[i]);
		sum += mmax[i];
	}
	ll l = mmax[1];
	ll r = sum + 1;
	while (r - l > 1) {
		ll h = (r + l) / 2;
		if (check(h)) {
			l = h;
		} else {
			r = h;
		}
	}
	printf("%lld", l);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int nT;
	scanf("%d", &nT);
	fi(1, nT) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}
	return 0;
}