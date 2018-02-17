#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define fi(a,b) for(int i = (a); i < (b); ++i)

const ll MOD = 1000000007;

void solve() {
	int n;
	scanf("%d", &n);
	ull q = 1;
	ll qmod = 1;
	fi(0, n) {
		qmod *= 2;
		qmod %= MOD;
		if (q < (1ull << 62)) {
			q *= 2;
		}
		ull qneed;
		scanf("%llu", &qneed);
		if(qneed > q) {
			printf("-1\n");
			return;
		}
		q -= qneed;
		qmod -= qneed;
		qmod %= MOD;
		qmod = (qmod + MOD) % MOD;
		
	}
	printf("%lld\n", qmod);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}