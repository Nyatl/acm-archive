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

const int MAXN = 1000005;

vector<short> a;
vector<short> b;
vector<short> c;

const short MOD = 31;

vector<short> bm[32];

short k;

char buff[MAXN];

short toNum(char ch) {
	if (ch >= '0' && ch <= '9') {
		return (ch - '0');
	}
	return (ch - 'A' + 10);
}

char toCh(short i) {
	if (i >= 0 && i <= 9) {
		return (i + '0');
	}
	return (i + 'A' - 10);
}

void calcMul(short a) {
	if (a == 0) {
		return;
	}
	bm[a] = b;
	if (a == 1) {
		return;
	}
	fi(0, sz(bm[a])) {
		bm[a][i] *= a;
	}
	short o = 0;
	fdi(sz(bm[a]), 0) {
		bm[a][i] += o;
		o = bm[a][i] / MOD;
		bm[a][i] %= MOD;
	}
	if (o) {
		bm[a].insert(bm[a].begin(), o);
	}
}

void calcMul() {
	fi(0, MOD) {
		calcMul(i);
	}
}

bool leq(int indf, int inds, short m) {
	if (inds - indf + 1 < sz(bm[m])) {
		return false;
	}
	if (inds - indf + 1 > sz(bm[m])) {
		return true;
	}

	fi(0, sz(bm[m])) {
		if (bm[m][i] > a[indf + i]) {
			return false;
		}
		if (bm[m][i] < a[indf + i]) {
			return true;
		}
	}

	return true;
}

short getD(int indf, int inds) {
	if (indf > inds) {
		return 0;
	}
	fdi(MOD, 1) {
		if (leq(indf, inds, i)) {
			return i;
		}
	}
	return 0;
}

void recalcPrevP(int & p) {
	while (p < sz(a) && a[p] == 0) {
		++p;
	}
}

void redu(int p, short m) {
	if (m == 0) {
		return;
	}
	p -= sz(bm[m]) - 1;
	int p1 = p;
	fi(0, sz(bm[m])) {
		a[p + i] -= bm[m][i];
		++p1;
	}
	fdi(p1, p) {
		if (a[i] < 0) {
			a[i] += MOD;
			a[i - 1]--;
		}
	}
}

void solve() {
	scanf(" %s", buff);
	{
		int i = 0;
		while (buff[i] != '\0') {
			a.push_back(toNum(buff[i]));
			++i;
		}
	}
	scanf(" %s", buff);
	{
		int i = 0;
		while (buff[i] != '\0') {
			b.push_back(toNum(buff[i]));
			++i;
		}
	}
	scanf("%d", &k);
	bool isNull = (a[0] == 0);
	calcMul();
	int prevP = 0;
	fi(prevP, sz(a)) {
		short d = getD(prevP, i);
		if (d) {
			c.push_back(d);
			redu(i, d);
			recalcPrevP(prevP);
		} else {
			if (sz(c)) {
				c.push_back(0);
			}
		}
	}
	fi(sz(c), k) {
		putchar('0');
	}
	fi(sz(c) - k, sz(c)) {
		if (i >= 0) {
			putchar(toCh(c[i]));
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}