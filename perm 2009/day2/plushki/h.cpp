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

int const N = 1e5 + 41;

int w[N];
char s[N];
int k;
int p1, p2;

void solve() {
        int n = strlen(s);
        fi(0, n) {
                if (s[i] == '1') {
                        int p = i + 1 + k;
                        while (p < n && !w[p]) {
                                if (w[p] != 0) {
                                        break;
                                }
                                w[p] = i + 1;
                                if (s[p] == '1') {
                                        p1 = i + 1;
                                        p2 = p + 1;
                                        return;
                                }
                                p += k;
                        }
                }
        }
        fi(0, n - 1) {
                if (s[i] == '1' && s[i + 1] == '1') {
                        p1 = i + 1;
                        p2 = i + 2;
                        return;
                }
        }
}

int main() {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

        scanf("%d", &k);
        scanf("%s", &s);

        solve();

        printf("%d %d\n", p1, p2);

        return 0;
}