#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <assert.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()

typedef long long ll;

#define MAX 100100

int n;
ll T, m;

ll t[MAX];
ll v[MAX];

ll sum(ll a, ll b) {
	a = max(a, 0LL);
	b = max(b, 0LL);
	if (a > b) {
		swap(a, b);
	}
	return (a + b) * (b - a + 1) / 2;
}

ll l[MAX], r[MAX];
ll L, R;

void solve() {

	l[0] = sum(v[1] - (t[1] - 1), v[1]) - v[1];
	r[0] = sum(v[1] + (t[1] - 1), v[1]) - v[1];
	l[n] = sum(v[n] - (m - t[n]), v[n]);
	r[n] = sum(v[n] + (m - t[n]), v[n]);

	fi(1, n - 1) {
		ll len = t[i + 1] - t[i];
		ll rem = len - abs(v[i + 1] - v[i]);
		ll a = min(v[i], v[i + 1]);
		ll b = max(v[i], v[i + 1]);
		if (rem < 0) {
			printf("No\n");
			return;
		}
		if (rem == 0) {
			l[i] = sum(a, b);
			r[i] = sum(a, b);
		} else if (rem == 1) {
			l[i] = a + sum(a, b);
			r[i] = b + sum(a, b);
		} else if (rem % 2 == 0) {
			l[i] = sum(a, a - rem / 2) + sum(a - (rem / 2 - 1), b);
			r[i] = sum(b, b + rem / 2) + sum(b + (rem / 2 - 1), a);
		} else {
			l[i] = sum(a, a - rem / 2) + sum(a - rem / 2, b);
			r[i] = sum(b, b + rem / 2) + sum(b + rem / 2, a);
		}
		l[i] -= v[i + 1];
		r[i] -= v[i + 1];
	}
	fi(0, n) {
		L += l[i];
		R += r[i];
	}
	if (L <= T && T <= R) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%lld %lld %d", &T, &m, &n);
	fi(1, n) {
		scanf("%lld %lld", &t[i], &v[i]);
	}
	solve();
	return 0;
}