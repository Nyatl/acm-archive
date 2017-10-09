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

ll n;
ll k, m;

ll query(ll x) {
	ll res;
	while (x < 1) x += n - m;
	while (x > n - m) x -= n - m;
	printf("? %lld\n", x);
	fflush(stdout);
	scanf("%lld", &res);
	if (res == k) {
		printf("! %lld\n", x);
		fflush(stdout);
		exit(0);
	}
	return res;
}

ll N(ll x) {
	while (x < 1) x += n;
	while (x > n) x -= n;
	return x;
}

ll dst(ll a, ll b) {
	if (a < b) return b - a;
	return a + n - b;
}

int main() {
	scanf("%lld %lld", &k, &m);
	n = 1000000000000000000LL;
	ll x = query(1);
	ll l = 0;
	ll r = m;
	fi(1, 9) {
		ll h = (l + r) / 2;
		ll y = N(1 + k - x - h);
		ll res = query(y);
		if (dst(k, res) < 1000) {
			l = h + 1;
		} else {
			r = h - 1;
		}
	}
	printf("! -1\n");
	fflush(stdout);
	return 0;
}
