#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES

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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////////////////////

const int N = 200005;

const ld R = 6371.;

const ld M_PI = acos((ld)(-1));

ld getD(ld betta, ld alpha) {
	return abs((betta - alpha) * R);
}

ld getBetta(ld h) {
	return (h / (2 * M_PI * R));
}

ld getW(ld gamma) {
	ld nz = cos(gamma) * R;
	ld w = sqrt(abs(R * R - nz * nz)) * 2 * M_PI;
	return w;
}

void solve() {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	ld alpha;

	alpha = acos(z / R);

	//cerr << alpha << endl;
	/*{
		ld gamma = M_PI / 2;
		cerr << fixed << setprecision(15) << getW(gamma) << endl;
		cerr << getD(0, gamma) << endl;
	}*/
	ld l = max(alpha, M_PI / 2);
	ld r = M_PI;
	fi(0, 200) {
		ld m = (r + l) / 2;
		ld d = getD(m, alpha);
		ld w = getW(m);
		//if (d < 1.) {//todo
		//	l = m;
		//	continue;
		//}
		if (d > w) {
			r = m;
		} else {
			l = m;
		}
	}
	printf("%.15Lf\n", getW(r));
	//printf("%.15lf\n", getD(alpha, r));
}

#define FILENAME "dreamrun"

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