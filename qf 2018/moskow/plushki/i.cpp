#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define fi(a, b) for (int i = a; i <= b; i++)
#define fj(a, b) for (int j = a; j <= b; j++)
#define fo(a, b) for (int o = a; o <= b; o++)
#define fdi(a, b) for (int i = a; i >= b; i--)
#define fdj(a, b) for (int j = a; j >= b; j--)
#define fdo(a, b) for (int o = a; o >= b; o--)
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#ifdef LOCAL
#else
#endif

///////////////////////////////////  

const int MAX = 300005;

int n, m;

int a[MAX];

ll g[MAX];

ll sum;

ll calc(int x) {
	ll res = 0;
	for (int i = x; i <= n; i += x) {
		res += a[i];
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	fi(1, n) {
		sum += a[i];
	}
	fi(1, n) {
		g[i] = calc(i);
	}
	fi(1, m) {
		int x;
		double y;
		scanf("%d %lf", &x, &y);
		double ans = sum - g[x] * (1 - y);
		printf("%.9lf\n", ans);
	}

	return 0;
}