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

const int MAXN = 505;

int n, m;

int mapag[MAXN][MAXN];
int mapav[MAXN][MAXN];

int getMapaV(int x, int y) {
	if (x >= n) {
		x -= n;
	}
	if (y >= m) {
		y -= m;
	}
	return mapav[x][y];
}

int getMapaG(int x, int y) {
	if (x >= n) {
		x -= n;
	}
	if (y >= m) {
		y -= m;
	}
	return mapag[x][y];
}

void changeMapaV(int x, int y, int w) {
	if (x >= n) {
		x -= n;
	}
	if (y >= m) {
		y -= m;
	}
	mapav[x][y] += w;
}

void changeMapaG(int x, int y, int w) {
	if (x >= n) {
		x -= n;
	}
	if (y >= m) {
		y -= m;
	}
	mapag[x][y] += w;
}

void wind(int x, int y, int w) {
	changeMapaG(x, y, -w);
	changeMapaG(x + 1, y, w);
	changeMapaV(x, y + 1, -w);
	changeMapaV(x, y, w);
}

bool change() {
	bool ret = false;
	fi(0, n) {
		fj(0, m) {
			int l = getMapaV(i, j);
			int r = getMapaV(i, j + 1);
			int t = getMapaG(i, j);
			int b = getMapaG(i + 1, j);
			if (l || t) {
				ret = true;
				int change = max(abs(l), abs(t));
				int changeZn;
				//todo
				int maxi = 0;
				if (abs(l) > maxi) {
					changeZn = (l > 0) ? -1 : 1;
				}
				if (abs(t) > maxi) {
					changeZn = (t > 0) ? 1 : -1;
				}
				wind(i, j, change * changeZn);
			}
		}
	}
	return ret;
}

void solve() {
	scanf("%d%d", &n, &m);
	fi(0, n) {
		fj(0, m) {
			scanf("%d", &mapag[i][j]);
			scanf("%d", &mapav[i][j]);
		}
	}
	fi(0, n) {
		ll sumV = 0;
		fj(0, m) {
			sumV += mapav[i][j];
		}
		if (sumV) {
			printf("No");
			return;
		}
	}
	fi(0, m) {
		ll sumG = 0;
		fj(0, n) {
			sumG += mapag[j][i];
		}
		if (sumG) {
			printf("No");
			return;
		}
	}
	/*fi(0, 10000) {
		if (!change()) {
			printf("Yes");
			return;
		}
	}*/
	printf("Yes");
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}