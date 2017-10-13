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

int s[50005];

int n;

bool check() {
        fi(1, n + 1) {
                if (s[i] > 9) {
                        return false;
                }
                fj(i, n + 1) {
                        if (j + i > n + 1) {
                                break;
                        }
                        if (s[i] == s[j]) {
                                if (s[i + j] == s[i]) {
                                        return false;
                                }
                        }
                }
        }
        return true;
}

void solve() {
        string a = "0";
        fi(1, 10) {
                a = a + string(sz(a) + 1, '0' + i) + a;
        }
        fi(0, sz(a)) {
                s[i + 1] = a[i] - '0';
        }
        cin >> n;
        //assert(check());
        fi(1, n + 1) {
                printf("%d", s[i]);
        }
}

bool check(vector<int> & a) {
        fi(0, sz(a)) {
                int k = i + 1;
                fj(0, sz(a)) {
                        int l = j + 1;
                        if (a[i] != a[j]) {
                                continue;
                        }
                        int s = l + k;
                        if (s % 14 == 0) {
                                continue;
                        }
                        if (a[s % 14 - 1] == a[i]) {
                                return false;
                        }
                }
        }
        return true;
}

int main() {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

        /*fi(0, 177147) {
                vector<int> a;
                a.push_back(0);
                a.push_back(1);
                int o = i;
                fi(0, 11) {
                        a.push_back(o % 3);
                        o /= 3;
                }
                if (check(a)) {
                        fi(0, sz(a)) {
                                cout << a[i];
                        }
                        cout << endl;
                }
        }*/

        solve();

        return 0;
}