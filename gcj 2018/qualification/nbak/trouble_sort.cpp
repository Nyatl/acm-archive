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

void troubleSort(vi & L) {
	bool done = false;
	while (!done) {
		done = true;
		fi(0, sz(L) - 2 - 1) {
			if (L[i] > L[i + 2]) {
				done = false;
				swap(L[i], L[i + 2]);
			}
		}
	}
}

int check(vi & L) {
	fi(1, sz(L) - 1) {
		if (L[i - 1] > L[i]) {
			return i - 1;
		}
	}
	return -1;
}

void solve() {
	int n;
	vi L;
	scanf("%d", &n);
	fi(1, n) {
		int t;
		scanf("%d", &t);
		L.pb(t);
	}
	troubleSort(L);
	int res = check(L);
	if (res == -1) {
		printf("OK");
	} else {
		printf("%d", res);
	}
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