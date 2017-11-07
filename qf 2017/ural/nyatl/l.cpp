#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <set>
#include <assert.h>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define fi(a,b) for(int i=a; i<=b; i++)
#define fj(a,b) for(int j=a; j<=b; j++)
#define fo(a,b) for(int o=a; o<=b; o++)
#define fdi(a,b) for(int i=a; i>=b; i--)
#define fdj(a,b) for(int j=a; j>=b; j--)
#define fdo(a,b) for(int o=a; o>=b; o--)
#define sz(x) (int)x.size()
#define clr(x) memset(x, 0, sizeof(x))
#define copy(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair

template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	fi(0, sz(v) - 1) {
		cerr << v[i] << " ";
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) cerr << #x << ": " << x << endl;
#else
#define dbg(x) while(0){}
#endif

typedef long long ll;

#define FILENAME "little"

ll n;

void solve2(ll x) {
	while (x > 1 && x % 2 == 0) {
		x /= 2;
	}
	if (x == 1) {
		printf("-1\n");
		exit(0);
	}
}

set<vector<ll> > ans;

int q;
ll cur[100];
ll y;

void fun(ll x) {
	if (y == 1) {
		vector<ll> v;
		fi(1, q) {
			v.pb(cur[i]);
		}
		ans.insert(v);
		return;
	}
	if (y % x == 0) {
		y /= x;
		q++;
		cur[q] = x;
		fun(x);
		cur[q] = 0;
		y *= x;
		q--;
	}
	if (q > 0 && x == cur[1] && y % (x + 1) == 0) {
		q++;
		y /= x + 1;
		cur[q] = x + 1;
		fun(x + 1);
		y *= x + 1;
		cur[q] = 0;
		q--;
	}
}

void solve() {
	ll s = (ll) sqrt((double) n);
	ll a = max(2LL, s - 4);
	ll b = s + 4;
	y = n;
	for (ll i = a; i <= b; i++) {
		fun(i);
	}
	b = min(n, 1000100LL);
	fi(2, b) {
		fun(i);
	}
	fun(y);
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	scanf("%lld", &n);
	solve2(n);

	solve();

	printf("%d\n", sz(ans));
	for (set<vector<ll> >::iterator it = ans.begin(); it != ans.end(); it++) {	
		vector<ll> v = *it;
		printf("%d ", sz(v));
		fi(0, sz(v) - 1) {
			printf("%lld ", v[i]);
		}
		printf("\n");
	}
	
	return 0;
}


