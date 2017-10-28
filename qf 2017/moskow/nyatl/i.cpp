#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bitset>

using namespace std;

int n, k;

bitset<1501> a[1500];

void solve() {
	for (int i = 0; i < k; i++) {
		for (int j = i; j < n; j++) {
			if (a[j].test(i)) {
				swap(a[i], a[j]);
				for (int o = i + 1; o < n; o++) {
					if (a[o].test(i)) {
						a[o] ^= a[i];
					}
				}
				break;
			}
		}
	}
	for (int i = k; i < n; i++) {
		if (a[i].test(k)) {
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int tmp;
			scanf("%d", &tmp);
			a[i].set(j, tmp & 1);
		}
		a[i].set(k, 1);
	}
	solve();
}