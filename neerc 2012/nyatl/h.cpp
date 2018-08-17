#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back

template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> &p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> &v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 0; ABC < n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 1; ABC <= n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "hyperdrome"

#define MAX 300100

int n;
char str[MAX];

ll num(char x) {
	if (x >= 'a' && x <= 'z') return x - 'a';
	return x - 'A' + 26;
}

unordered_map<ll, ll> q;

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", str + 1);
	ll cur = 0;
	ll ans = 0;
	q[0] = 1;
	fi(1, n) {
		cur ^= 1LL << num(str[i]);
		if (q.count(cur)) {
			ans += q[cur];
		}
		fj(0, 51) {
			if (q.count(cur ^ (1LL << j))) {
				ans += q[cur ^ (1LL << j)];
			}
		}
		q[cur]++;
	}
	printf("%lld\n", ans);
	return 0;
}