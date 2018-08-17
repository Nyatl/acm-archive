#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define sz(x) (int)x.size()
#define mp(a, b) make_pair(a, b)
#define pb push_back

template<typename T>
ostream& operator<<(const ostream& os, const vector<T> &v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl;
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
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "pwgen"

int n;
int a, b, c;

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%d", &n);
	scanf("%d %d %d", &a, &b, &c);
	int sym = 'a';
	int num = 0;
	while (a || b) {
		if (a) {
			printf("%c", sym - ('a' - 'A'));
			a--;
		} else {
			printf("%c", sym);
			b--;
		}
		if (sym == 'z') {
			sym = 'a';
		} else {
			sym++;
		}
		n--;
	}
	while (n) {
		printf("%d", num);
		num = (num + 1) % 10;
		n--;
	}
	printf("\n");
	return 0;
}