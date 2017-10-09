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

int const INF = 1e9 + 41;
int const T = 1e7;
int const MAX = 4e5 + 41;
vector<int> pr;
bool l[T];

const int M = 3e6;
const int D = 10;
string s;
vector<int> bs;
int nxt[M][10];

string toStr(int i) {
	string ret;
	while (i) {
		ret.push_back(i % 10);
		i /= 10;
	}
	reverse(all(ret));
	return ret;
}

void sieve() {
	fi(2, INF) {
		if (!l[i]) {
			l[i] = 1;
			pr.pb(i);
			if (sz(pr) == MAX) break;
			for (int j = i + i; j < T; j += i) {
				l[j] = 1;
			}
		}
	}
}

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	int len = bs[n];
	int szans = len - k;
	string ans;
	int curS = 0;
	for (int i = 0; i < szans; ++i) {
		int maxI = curS + k;
		int nxtS;
		char nxtCh;
		fdj(D, 0) {
			if (nxt[curS][j] <= maxI) {
				nxtS = nxt[curS][j];
				nxtCh = '0' + j;
				break;
			}
		}
		ans.push_back(nxtCh);
		k -= (nxtS - curS);
		curS = nxtS + 1;
	}
	printf("%s\n", ans.c_str());
}

void precalc() {
	fi(0, MAX) {
		bs.push_back(sz(s));
		s += toStr(pr[i]);
	}
	fdi(sz(s), 0) {
		fj(0, D) {
			if (s[i] == j) {
				nxt[i][j] = i;
			} else {
				nxt[i][j] = nxt[i + 1][j];
			}
		}
	}
}

#define FILENAME "primeseq"

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif
	sieve();
	precalc();
	int test;
	scanf("%d", &test);
	fo(1, test + 1) {
		solve();
	}	

	return 0;
}