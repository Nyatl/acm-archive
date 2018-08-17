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
#define dbg0(x) while(0){}
#define dbg1(x) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "addictive"

#define MAX 20

int n, m, k;
int a[MAX];
char matr[MAX][MAX];

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%d %d %d", &m, &n, &k);
	fi(1, k) {
		scanf("%d", &a[i]);
	}
	int x = 1;
	int y = m;
	int c = 1;
	int q = a[c];
	int dx = 1;
	while (c <= k) {
		matr[y][x] = '0' + c;
		x += dx;
		if (x < 1 || x > n) {
			dx = -dx;
			x += dx;
			y--;
		}
		q--;
		if (q == 0) {
			c++;
			q = a[c];
		}
	}
	fj(1, m) {
		fi(1, n) {
			printf("%c", matr[j][i]);
		}
		printf("\n");
	}
	return 0;
}