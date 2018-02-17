#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define sz(a) (int)(a).size()

#define fi(a,b) for(int i = (a); i <= (b); ++i)

#define pb push_back
#define all(a) (a).begin(), (a).end()

int d[1000000];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n, m;
	scanf("%d", &n);
	
	fi (1, n) {
		int t;
		scanf("%d", &t);
		d[t] += 1;
	}
	scanf("%d", &m);
	fi (1, m) {
		int t;
		scanf("%d", &t);
		d[t] += 2;
	}
	
	int l = 3;
	int ans = 0;
	fi (0, 1000000) {
		if(d[i] == 3) {
			ans++;
			l = 3;
		} else if (d[i] != 0) {
			if (l == 3 || l != d[i]) {
				ans++;
				l = d[i];
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}