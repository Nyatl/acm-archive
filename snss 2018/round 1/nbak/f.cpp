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

int a, b, c, ab, bc, ca, abc;

int getResFor2(int x, int y, int xy) {
	if (xy > min(x, y)) return rand();
	if (x < 0 || y < 0 || xy < 0) return rand();
	return x + y - xy;
}

int getRes() {
	return a + b + c - ab - bc - ca + abc;
}

int check() {
	if (ab > min(a, b)) return 0;
	if (bc > min(b, c)) return 0;
	if (ca > min(c, a)) return 0;
	if (abc > min(min(ab, bc), ca)) return 0;
	if (abc > min(a, min(b, c))) return 0;
	if (getRes() < max(a, max(b, c))) return 0;
	int ans = getRes();
	int ans1 = getResFor2(getResFor2(a, b, ab), c, getResFor2(ca, bc, abc));
	int ans2 = getResFor2(getResFor2(b, c, bc), a, getResFor2(ab, ca, abc));
	int ans3 = getResFor2(getResFor2(c, a, ca), b, getResFor2(bc, ab, abc));
	if (ans != ans1) return 0;
	if (ans != ans2) return 0;
	if (ans != ans3) return 0;
	return 1;
}



void solve() {
	scanf("%d", &n);
	int ans = 0;
	fi(1, n) {
		scanf("%d %d %d %d %d %d %d", &a, &b, &c, &ab, &bc, &ca, &abc);
		if (check()) {
			ans = max(ans, getRes());
		}
	}
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tests;
	scanf("%d", &tests);
	while (tests--) {
		solve();
	}
	return 0;
}