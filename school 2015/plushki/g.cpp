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

int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char dir[4] = { 'U', 'R', 'D', 'L' };

int cntq = 0;

struct P {
	int y, x;
	P() {};
	P(int y, int x) : y(y), x(x) {};
	bool operator==(const P & a) const {
		if (y != a.y) return false;
		if (x != a.x) return false;
		return true;
	};
};

P p0, p1;

bool canmove(P p) {
	if (p == p0 || p == p1) return false;
	if (p.x < 1 || p.x > n) return false;
	if (p.y < 1 || p.y > n) return false;
	return true;
}

int query(int id, int d) {
	++cntq;
	assert(cntq <= 6 * n);
#ifdef _DEBUG
#else
	cout << "0 " << id + 1 << " " << dir[d] << endl;
#endif
	//printf("0 %d %c\n", id, dir[d]);
	//fflush(stdout);
#ifdef _DEBUG
	if (id == 0) {
		int ny = p0.y + dy[d];
		int nx = p0.x + dx[d];
		return canmove(P(ny, nx));
	} else {
		int ny = p1.y + dy[d];
		int nx = p1.x + dx[d];
		return canmove(P(ny, nx));
	}
#else
	int ret;
	cin >> ret;
	//scanf(" %1d", &ret);
	return ret;
#endif
}

vector<int> d0, d1;
pair<P, P> ans, ansp;

void movetop() {
	while (query(0, 0)) {
		d0.pb(0);
#ifdef _DEBUG
		p0.y += 1;
#endif
	}
	while (query(1, 0)) {
		d1.pb(0);
#ifdef _DEBUG
		p1.y += 1;
#endif
	}
	while (query(0, 0)) {
		d0.pb(0);
#ifdef _DEBUG
		p0.y += 1;
#endif
	}
}

void moveright() {
	while (query(0, 1)) {
		d0.pb(1);
#ifdef _DEBUG
		p0.x += 1;
#endif
	}
	while (query(1, 1)) {
		d1.pb(1);
#ifdef _DEBUG
		p1.x += 1;
#endif
	}
}

int revdir(int d) {
	return (d ^ 2);
}

pair<P, P> restore(P f0, P f1) {
	fdi(sz(d0), 0) {
		int dir = revdir(d0[i]);
		int nx = f0.x + dx[dir];
		int ny = f0.y + dy[dir];
		f0.x = nx;
		f0.y = ny;
	}
	fdi(sz(d1), 0) {
		int dir = revdir(d1[i]);
		int nx = f1.x + dx[dir];
		int ny = f1.y + dy[dir];
		f1.x = nx;
		f1.y = ny;
	}
	return mp(f0, f1);
}

void solve2() {
	int fd0 = query(0, 1);
	if (fd0) {
		d0.pb(1);
#ifdef _DEBUG
		p0.x += 1;
#endif
	}
	int fd1 = query(1, 3);
	if (fd1) {
		d1.pb(3);
#ifdef _DEBUG
		p1.x -= 1;
#endif
	}
	int fd2 = query(0, 0);
	if (fd2) {
		d0.pb(0);
#ifdef _DEBUG
		p0.y += 1;
#endif
	}
	P f0, f1;
	f0.x = 2;
	f1.x = 1;

	if (fd2) {
		f0.y = 2;
		f1.y = 2;
	} else {
		f0.y = 2;
		f1.y = 1;
	}
	ans = restore(f0, f1);
}

void solve() {
	movetop();
#ifdef _DEBUG
	bool fl1 = canmove(P(p0.y + 1, p0.x));
	bool fl2 = canmove(P(p1.y + 1, p1.x));
	assert(!fl1 && !fl2);
#endif
	int fd0 = query(0, 2);
	if (fd0) {
		query(0, 0);
	}
	int fd1 = query(1, 2);
	if (fd1) {
		d1.pb(2);
		p1.y -= 1;
	}
	if (!fd1 && !fd0) {
		solve2();
		return;
	}
	moveright();
	P f0, f1;
	if (!fd1) {
		f0 = P(n - 1, n);
		f1 = P(n, n);
	} else {
		if (fd0) {
			f0 = P(n, n);
			f1 = P(n - 1, n);
		} else {
			f0 = P(n, n);
			f1 = P(n - 2, n);
		}
	}

	ans = restore(f0, f1);
}

void answer() {
	cout << "1 " << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << endl;
	//printf("1 %d %d %d %d\n", ans.first.x, ans.first.y, ans.second.x, ans.second.y);
	//fflush(stdout);
}

int main() {
#ifdef _DEBUG
	for (n = 2; n <= 50; ++n) {
		cout << n << endl;
		for (int c0 = 1; c0 <= n; ++c0) {
			for (int r0 = 1; r0 <= n; ++r0) {
				for (int c1 = 1; c1 <= n; ++c1) {
					for (int r1 = 1; r1 <= n; ++r1) {
						if (r0 == r1 && c0 == c1) continue;
						ansp = mp(P(r0, c0), P(r1, c1));
						d0.clear();
						d1.clear();
						p0 = P(r0, c0);
						p1 = P(r1, c1);
						cntq = 0;
						ans = mp(P(-1, -1), P(-1, -1));
						solve();
						if (!(ansp == ans)) {
							cout << endl;
							cout << "1 " << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << endl;
							cout << "1 " << ansp.first.x << " " << ansp.first.y << " " << ansp.second.x << " " << ansp.second.y << endl;
							cout << endl;
						}
						assert(ansp == ans);
					}
				}
			}
		}
	}
	return 0;
#endif
	scanf("%d", &n);
#ifdef _DEBUG
	int r0, c0, r1, c1;
	scanf("%d %d %d %d", &c0, &r0, &c1, &r1);
	p0 = P(r0, c0);
	p1 = P(r1, c1);
	ansp = mp(p0, p1);
#endif
	solve();

	answer();
#ifdef _DEBUG
	assert(ansp == ans);
	printf("cntq = %d\n", cntq);
#endif

	return 0;
}