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

const int N = 200005;

int a[N];

void solve() {
	int n;
	scanf("%d", &n);
	fi(0, n) {
		scanf("%d",&a[i]);
	}
	int fp = 0, sp = 0;
	int cntp = 1;
	int pr = 0;
	int cp = 0;
	fi(0, n) {
		if (a[i] == pr) {
			cntp++;
		} else {
			cntp = 1;
		}
		if (cntp >= 3) {
			cntp = 2;
			cp = i - 1;
		}
		if (sp - fp < i - cp) {
			sp = i;
			fp = cp;
		}
		pr = a[i];
	}

	printf("%d %d\n", fp + 1, sp + 1);
}

#define FILENAME "agro"

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