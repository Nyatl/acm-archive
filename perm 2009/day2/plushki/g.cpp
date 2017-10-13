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

int const N = 6e5 + 41;

int p1, p2;
pii a[N];
int n, k;
int p[N];

void solve() {
        sort(a+1, a + k + 1);
        fi(1, k + 1) {
                if (p[a[i].first]) {
                        p1 = p[a[i].first];
                        p2 = a[i].second;
                        break;
                }
                for (int j = a[i].first; j < N; j += a[i].first) {
                        p[j] = a[i].second;
                }
        }
}

int main() {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        scanf("%d %d", &n, &k);
        fi(1, k + 1) {
                int v;
                scanf("%d", &v);
                a[i] = mp(v, i);
        }

        solve();

        printf("%d %d\n", p1, p2);

        return 0;
}