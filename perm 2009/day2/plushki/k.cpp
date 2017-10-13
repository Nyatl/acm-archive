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

int const N = 13;
int ans[N][N];

int h, w;
int m[N][N];
int dx1[6] = { 0, 1, 2, 0, 1, 2 };
int dy1[6] = { 0, 0, 0, 1, 1, 1 };

int dx2[6] = { 0, 0, 0, 1, 1, 1 };
int dy2[6] = { 0, 1, 2, 0, 1, 2 };

int havefree() {
        fi(0, h) fj(0, w) if (m[i][j] == 0) return true;
        return false;
}

bool can[N][N];

bool inbound(int y, int x) {
        if (y < 0 || y >= h) return false;
        if (x < 0 || x >= w) return false;
        return true;
}

bool canplace1(int y, int x) {
        fi(0, 6) {
                int ny = y + dy1[i];
                int nx = x + dx1[i];
                if (!inbound(ny, nx)) return false;
                if (m[ny][nx]) return false;
        }
        return true;
}

bool canplace2(int y, int x) {
        fi(0, 6) {
                int ny = y + dy2[i];
                int nx = x + dx2[i];
                if (!inbound(ny, nx)) return false;
                if (m[ny][nx]) return false;
        }
        return true;
}

bool canall() {
        fi(0, h) fj(0, w) can[i][j] = 0;
        fi(0, h) fj(0, w) {
                if (canplace1(i, j)) {
                        fo(0, 6) {
                                int ny = i + dy1[o];
                                int nx = j + dx1[o];
                                ++can[ny][nx];
                        }
                }
                if (canplace2(i, j)) {
                        fo(0, 6) {
                                int ny = i + dy2[o];
                                int nx = j + dx2[o];
                                ++can[ny][nx];
                        }
                }
        }
        fi(0, h) fj(0, w) {
                if (m[i][j] == 0 && can[i][j] == 0) return false;
        }
        return true;
}

void place1(int y, int x, int c) {
        fi(0, 6) {
                int ny = y + dy1[i];
                int nx = x + dx1[i];
                m[ny][nx] = c;
        }
}

void place2(int y, int x, int c) {
        fi(0, 6) {
                int ny = y + dy2[i];
                int nx = x + dx2[i];
                m[ny][nx] = c;
        }
}

int calc(int h, int w) {
        if (!havefree()) return true;
        if (!canall()) return false;
        fi(0, h) fj(0, w) {
                if (!m[i][j]) {
                        if (canplace1(i, j)) {
                                place1(i, j, 1);
                                if (calc(h, w)) return 1;
                                place1(i, j, 0);
                        }
                        if (canplace2(i, j)) {
                                place2(i, j, 1);
                                if (calc(h, w)) return 1;
                                place2(i, j, 0);
                        }
                }
        }
        return 0;
}

void clear(int h, int w) {
        fi(0, h) fj(0, w) {
                m[i][j] = 0;
        }
}

void solve() {
        fi(1, N) {
                fj(i, N) {
                        if (i % 2 == 1 && j % 2 == 1) {
                                ans[i][j] = 0;
                        } else {
                                ::h = i;
                                ::w = j;
                                clear(h, w);
                                ans[i][j] = calc(i, j);
                                if (ans[i][j]) {
                                        cerr << i << " " << j << " " << ans[i][j] << endl;
                                }
                        }
                }
        }
        fi(1, N) {
                fj(i, N) {
                        printf("%d %d %d\n", i, j, ans[i][j]);
                }
        }
}

int main() {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        int nT;
        scanf("%d", &nT);
        while (nT--) {
                scanf("%d%d", &h, &w);
                if (h < 2 || w < 2) {
                        printf("No\n");
                } else {
                        if ((h * 1LL * w) % 6) {
                                printf("No\n");
                        } else {
                                printf("Yes\n");
                        }
                }
        }
        //solve();

        return 0;
}