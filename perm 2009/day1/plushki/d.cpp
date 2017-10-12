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

int const N = 3e5 + 41;

ll f[N];
int n, a[N];
int t[N];
vector<int> tt[4];
ll ans;
int T;

bool cmp(int a, int b) {
        return a > b;
}

void calceven() {
        int lp = 0, ln = sz(tt[1]);
        int rp = 0, rn = sz(tt[2]);
        int t = 0;
        ll v = 0;
        while ((lp + 1 < ln || rp < rn) && t + 2 < N) {
                t += 2;
                if (rp == rn || (lp + 1 < ln && (tt[1][lp] + tt[1][lp + 1] > tt[2][rp]))) {
                        v += tt[1][lp] + tt[1][lp + 1];
                        lp += 2;
                } else {
                        v += tt[2][rp];
                        rp += 1;
                }
                f[t] = v;
        }
}

void calcodd() {
        if (sz(tt[1]) == 0) return;
        int lp = 1, ln = sz(tt[1]);
        int rp = 0, rn = sz(tt[2]);
        int t = 1;
        ll v = tt[1][0];
        f[1] = tt[1][0];
        while ((lp + 1 < ln || rp < rn) && t + 2 < N) {
                t += 2;
                if (rp == rn || (lp + 1 < ln && (tt[1][lp] + tt[1][lp + 1] > tt[2][rp]))) {
                        v += tt[1][lp] + tt[1][lp + 1];
                        lp += 2;
                } else {
                        v += tt[2][rp];
                        rp += 1;
                }
                f[t] = v;
        }
}

void solve() {
        fi(0, n) {
                tt[t[i]].pb(a[i]);
        }
        fi(0, 4) sort(tt[i].begin(), tt[i].end(), cmp);
        calceven();
        calcodd();
        fi(1, N) f[i] = max(f[i], f[i - 1]);
        ll sum = 0;
        ans = f[T];
        fi(0, sz(tt[3])) {
                sum += tt[3][i];
                int cur = (i + 1) * 3;
                int rem = T - cur;
                if (rem >= 0) {
                        ans = max(ans, sum + f[rem]);
                }
        }
}

#define FILENAME "lecture"

int main() {
#ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#else
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
#endif

        scanf("%d %d", &n, &T);
        fi(0, n) scanf("%d %d", &t[i], &a[i]);

        solve();

        printf("%lld\n", ans);

        return 0;
}