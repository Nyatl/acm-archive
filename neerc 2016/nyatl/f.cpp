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
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long ll;

#define FILENAME "foreign"

#define MAX 1000100

int n;
char str[MAX];
int a[MAX];

double d[MAX];

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	scanf("%s", str + 1);
	n = strlen(str + 1);
	fi(1, n) {
		a[i] = (str[i] == 'W');
	}
	reverse(a + 1, a + n + 1);

	double all_p = 0;

	double C = 0, W = 0;

	fi(1, n) {
		if (a[i] == 0) { // C
			d[i] = (all_p + W) / i;
			C += i;
		} else { // W
			d[i] = (all_p + C) / i;
			W += i;
		}
		
		all_p += d[i];
	}

	printf("%.12lf\n", d[n]);

	return 0;
}
