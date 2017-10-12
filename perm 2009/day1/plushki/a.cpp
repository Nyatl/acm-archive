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

int const N = 2e6 + 41;

string a, b;

ll ans[N];

void solve() {
        cin >> a;
        cin >> b;
        reverse(all(a));
        reverse(all(b));
        fi(0, sz(a)) {
                ans[i] += a[i] - '0';
        }
        fi(0, sz(b)) {
                ans[i] += b[i] - '0';
        }
        int l = 0;
        fi(0, N - 10) {
                if (ans[i]) {
                        l = i;
                        ll e = ans[i + 2];
                        ll d = ans[i] / 4;
                        ll f = min(e, d);
                        ans[i] -= f * 4;
                        ans[i + 2] -= f;
                        d = ans[i] / 4;
                        ans[i] %= 4;
                        ans[i + 2] += d * 3;
                        ans[i + 4] += d;
                }
        }
        if (l >= N - 20) {
                cout << 0 << endl;
                return;
        }
        string s;
        fi(0, l + 1) {
                s.push_back(ans[i] + '0');
        }
        while (sz(s) > 1 && s.back() == '0') {
                s.pop_back();
        }
        reverse(all(s));
        cout << s << endl;
}

#define FILENAME "aplusb"

int main() {
#ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#else
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
#endif

        solve();

        return 0;
}