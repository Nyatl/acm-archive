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

int n;
unordered_map<int, ll> d;

int getI2(int l, int r, int x, int y) {
	while (r > l) {
		int h = (r + l) / 2;
		if (x / h > y) {
			l = h + 1;
		} else {
			r = h;
		}
	}
	return l;
}

int cntb;

ll rec(int x) {
	if (d.count(x)) {
		return d[x];
	}
	ll res = 0;
	int i = 2;
	while (i <= x) {
		int y = x / i;
		int i2 = min(i + i / y, x);
		int cnt = 0;
		while (x / i2 != y) {
			i2--;
			cnt++;
		}
		if (cnt > cntb) {
			cntb = cnt;
			dbg(cntb);
			dbg(vi({x, y, i, i2, i2 + cnt}));
		}
		res += (i2 - i + 1) * rec(y);
		i = i2 + 1;
	}
	return d[x] = res;
}


void solve() {
	scanf("%d", &n);
	d[1] = 1;
	rec(n);
	dbg(sz(d));
	printf("%lld\n", d[n]);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}