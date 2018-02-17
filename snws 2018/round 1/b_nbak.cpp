#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define fi(a,b) for(int i = (a); i < (b); ++i)

void solve() {
	int n;
	scanf("%d", &n);
	vector<double> v(n);
	fi(0, n) {
		scanf("%lf", &v[i]);
	}
	double start = -1;
	double ans = 1000;
	int afterStart = 0;
	fi(0, n) {
		if(start < 0) {
			if(v[i] >= 30. && v[i] <= 30.2) {
				start = v[i];
			}
		} else {
			afterStart++;
			if(afterStart >= 3) {
				ans = min(ans, v[i] - 30.);
			}
		}
	}

	if(ans > 100) {
		printf("0\n");
		return;
	}
	printf("%.9lf\n", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}