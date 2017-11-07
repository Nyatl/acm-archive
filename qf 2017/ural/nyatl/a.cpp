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

#define FILENAME "auxiliary"

int n;
int ans;

int sum(int x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int cnt(int x) {
	if (x >= 10) return cnt(x / 10) + cnt(x % 10);
	if (x == 0) return 6;
	if (x == 1) return 2;
	if (x == 2) return 5;
	if (x == 3) return 5;
	if (x == 4) return 4;
	if (x == 5) return 5;
	if (x == 6) return 6;
	if (x == 7) return 3;
	if (x == 8) return 7;
	if (x == 9) return 6;
	assert(0);
	return -1;
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);	
	scanf("%d", &n);
	while (n >= 10) {
		n -= 3;
		ans += 7;
	}
	dbg(ans);
	int b = 0;
	fi(0, 10000) {
		if (cnt(i) == n) {
			dbg(cnt(i));
			dbg(sum(i));
			b = max(b, sum(i));
		}
	}
	dbg(b);
	ans += b;
	printf("%d\n", ans);
	return 0;
}


