#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define sz(a) ((int)(a).size())
#define fi(a,b) for(int i = (a); i < (b); ++i)

ll n, k;
ll p2[64], v[64];
ll ans;

void addFictive(int q) {
	assert(q > 0);
	fi (0, 64) {
		if(v[i] == 0) {
			v[i] = 1;
			q--;
			if (q == 0) {
				return;
			}
		}
	}
}

void tryReduce() {
	fi (0, 64) {
		if(v[i]) {
			while (v[i] == 1) {
				v[i] = 0;
				i++;
			}
			v[i] = 1;
			return;
		}
	}
	assert(false);
}

void solve() {
	p2[0] = 1;
	fi (1, 64) {
		p2[i] = 2 * p2[i - 1];
	}
	scanf("%lld%lld", &n, &k);
	n++;
	ll kn = 0;
	fi (0, 64) {
		if ((1LL<<i)&n) {
			v[i] = 1;
			kn++;
		}
	}
	ans = n;
	while (kn != k) {
		if(kn < k) {
			addFictive(k - kn);
		} else {
			tryReduce();
		}
		kn = 0;
		ans = 0;
		fi (0, 63) {
			if (v[i]) {
				ans |= p2[i];
				kn++;
			}
		}
		//cerr << ans << endl;
		//cerr << kn << endl;
	}
	printf("%lld\n", ans);
	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}