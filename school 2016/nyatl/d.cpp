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
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()

typedef long long ll;

#define MAX 500100

int n, m;

char *matr[MAX];

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int *nxt[4][MAX];
int *ans[MAX];

int *create() {
	int *a = new int[n + 10];
	memset(a, 0, 4 * (n + 10));
	return a;
}

void init() {
	fi(1, n) {
		int lasty = 0;
		fj(1, m) {
			if (matr[j][i] != matr[j - 1][i]) {
				lasty = j - 1;
			}
			nxt[1][j][i] = lasty;
		}
	}

	fi(1, n) {
		int lasty = m + 1;
		fdj(m, 1) {
			if (matr[j][i] != matr[j + 1][i]) {
				lasty = j + 1;
			}
			nxt[3][j][i] = lasty;
		}
	}

	fj(1, m) {
		int lastx = 0;
		fi(1, n) {
			if (matr[j][i] != matr[j][i - 1]) {
				lastx = i - 1;
			}
			nxt[0][j][i] = lastx;
		}
	}

	fj(1, m) {
		int lastx = n + 1;
		fdi(n, 1) {
			if (matr[j][i] != matr[j][i + 1]) {
				lastx = i + 1;
			}
			nxt[2][j][i] = lastx;
		}
	}
}

pair<int, int> get_next(int x, int y, int dir) {
	if (dir == 0 || dir == 2) {
		x = nxt[dir][y][x];
	} else {
		y = nxt[dir][y][x];
	}
	return mp(x, y);
}

bool inside(int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= m;
}

struct Cell {
	int x, y;
	char c;
};

void add(int x, int y, int dir, vector<Cell> &v) {
	vector<Cell> res;
	fi(1, 3) {
		if (!inside(x, y)) break;
		Cell t;
		t.x = x;
		t.y = y;
		t.c = matr[t.y][t.x];
		v.pb(t);
		pair<int, int> next = get_next(x, y, dir);
		x = next.first;
		y = next.second;
	}
}

#define INF 1000000000

int dst(Cell a, Cell b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
	int k;
	int x, y;
	scanf("%d", &k);
	fi(1, k) {
		scanf("%d %d", &y, &x);
		vector <Cell> h;
		vector <Cell> v;
		fj(0, 3) {
			int x2 = x + dx[j];
			int y2 = y + dy[j];
			if (j == 0 || j == 2) {
				add(x2, y2, j, h);
			} else {
				add(x2, y2, j, v);
			}
		}
		int ans = INF;
		Cell ans1;
		Cell ans2;
		fi(0, sz(h) - 1) {
			fj(0, sz(v) - 1) {
				if (h[i].c == v[j].c) continue;
				int d = dst(h[i], v[j]);
				if (d < ans) {
					ans = d;
					ans1 = h[i];
					ans2 = v[j];
				}
			}
		}
		if (ans == INF) {
			printf("-1\n");
		} else {
			printf("%d %d %d %d\n", ans1.y, ans1.x, ans2.y, ans2.x);
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &m, &n);
	matr[0] = new char[n + 10];
	matr[m + 1] = new char[n + 10];
	memset(matr[0], 0, n + 10);
	memset(matr[m + 1], 0, n + 10);
	fj(1, m) {
		matr[j] = new char[n + 10];
		memset(matr[j], 0, n + 10);
		scanf("%s", matr[j] + 1);
	}

	fo(0, 3) {
		fj(1, m) {
			nxt[o][j] = create();
		}
	}

	fj(1, m) {
		ans[j] = create();
	}

	init();
	solve();
	
	return 0;
}
