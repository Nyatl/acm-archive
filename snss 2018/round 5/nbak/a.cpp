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

const int MAX = 5005;

struct Clock {
	int h, m;
	Clock() {}
	Clock(int h, int m) : h(h), m(m) {}
};

int d[MAX][2];
int pref[MAX][2];
int n;

Clock a[MAX];
Clock clck[2];

int cost(const Clock &c1, const Clock &c2) {
	int res = 0;
	res += min(abs(c1.m - c2.m), 60 - abs(c1.m - c2.m));
	res += min(abs(c1.h - c2.h), 24 - abs(c1.h - c2.h));
	return res;
}

int rec(int x, int c) {
	if (x == 0) return 0;
	if (d[x][c] != -1) {
		return d[x][c];
	}
	if (x == 1) return cost(a[x], clck[c]);
	int res = 100000000;
	fi(1, x - 1) {
		int recres = rec(i, !c);
		int prefres = pref[x - 1][!c] - pref[i][!c];
		int calcres;
		if (i == 1) {
			calcres = cost(a[x], clck[c]);
		} else {
			calcres = cost(a[x], a[i - 1]);
		}
		res = min(res, recres + prefres + calcres);
	}
	return d[x][c] = res;
}

void solve() {
	memset(d, -1, sizeof(d));
	fi(0, 1) {
		int h, m;
		scanf("%2d:%2d", &h, &m);
		clck[i] = Clock(h, m);
	}
	scanf("%d", &n);
	fi(1, n) {
		int h, m;
		scanf("%2d:%2d", &h, &m);
		a[i] = Clock(h, m);
	}
	fj(0, 1) {
		fi(1, n) {
			Clock prev;
			if (i == 1) {
				prev = clck[j];
			} else {
				prev = a[i - 1];
			}
			pref[i][j] = pref[i - 1][j] + cost(a[i], prev);
		}
	}
	int ans = 1000000000;
	fdi(n, 0) {
		int localans = min(rec(i, 0) + pref[n][0] - pref[i][0], rec(i, 1) + pref[n][1] - pref[i][1]);
		ans = min(ans, localans);
		dbg(mp(i, localans));
	}
	printf("%d\n", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}