#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <tuple>
#include <map>
#include <ctime>
#include <memory>
#include <memory.h>
#include <iomanip>
#include <functional>
#include <cassert>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define sz(a) ((int)((a).size()))
#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fo(a, b) for(int o = (a); o < (b); ++o)
#define fdi(a, b) for(int i = (int)(a) - 1; i >= (b); --i)
#define fdo(a, b) for(int o = (int)(a) - 1; o >= (b); --o)
#define fdj(a, b) for(int j = (int)(a) - 1; i >= (b); --j)
#define all(a) (a).begin(),(a).end()
#define _(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////////////////////
const ll INF = 1000000000;

void solve() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if (k >= n) {
		printf("1");
		return;
	}
	ll glAns = INF;
	for (int i = k - 1; i >= max(1LL, k - 1000); --i) {
		ll ans = 0;
		ll a = i;
		while (a < n - 1) {
			a = a + min(a, (n - a) / 2);
			++ans;
		}
		if (glAns > ans) {
			glAns = ans;
		}
	}
	printf("%lld\n", glAns + 1);
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}