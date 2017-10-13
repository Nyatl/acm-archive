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

struct point {
        int x, y;
        int num;
        ld alp;
        point() {}
        point(int x, int y, int num) : x(x), y(y), num(num) {}
        bool operator<(point a) const {
                if (x != a.x) {
                        return x < a.x;
                }
                if (y != a.y) {
                        return y < a.y;
                }
                return num < a.num;
        }
};

vector<point> ps;

vector<point> ch;

vector<int> chnum;

vector<char> w;

vector<point> ans;

bool comp(const point & a, const point & b) {
        return a.alp < b.alp;
}

bool area(const point & a, const point & b, const point & c) {
        return (b.x - a.x) * 1LL * (c.y - a.y) - (c.x - a.x) * 1LL * (b.y - a.y) > 0;
}

void buildch() {
        ch.push_back(ps[0]);
        chnum.push_back(0);
        for (int i = 1; i < sz(ps); ++i) {
                while (sz(ch) > 1 && area(ps[i], ch[sz(ch) - 1], ch[sz(ch) - 2])) {
                        ch.pop_back();
                        chnum.pop_back();
                }
                ch.push_back(ps[i]);
                chnum.push_back(i);
        }
}

void pushAns(const point & a, const point & b, const point & c) {
        ans.push_back({ a.num + 1 , b.num + 1 , c.num + 1 });
}

void rebuildch() {
        int l = chnum.back();
        fi(l + 1, sz(ps)) {
                if (w[i]) {
                        continue;
                }
                while (sz(ch) > 1 && area(ps[i], ch[sz(ch) - 1], ch[sz(ch) - 2])) {
                        ch.pop_back();
                        chnum.pop_back();
                }
                ch.push_back(ps[i]);
                chnum.push_back(i);
        }
}

void solve() {
        int n;
        scanf("%d", &n);
        w.assign(n, 0);
        fi(0, n) {
                int x, y;
                scanf("%d%d", &x, &y);
                ps.push_back({ x, y, i });
        }
        fi(1, n) {
                if (ps[i] < ps[0]) {
                        swap(ps[i], ps[0]);
                }
        }
        fi(1, n) {
                ps[i].alp = atan2(ps[i].y - ps[0].y, ps[i].x - ps[0].x);
        }
        sort(ps.begin() + 1, ps.end(), comp);
        buildch();
        fi(0, n - 3) {
                point toDel = ch.back();
                w[chnum.back()] = true;
                ch.pop_back();
                chnum.pop_back();
                int l = sz(ch);
                rebuildch();
                fj(l, sz(ch)) {
                        pushAns(toDel, ch[j], ch[j - 1]);
                }
                pushAns(toDel, ch[0], ch.back());
        }
        pushAns(ch[0], ch[1], ch[2]);
        printf("%d\n", sz(ans));
        fi(0, sz(ans)) {
                printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].num);
        }
}

int main() {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

        solve();

        return 0;
}
