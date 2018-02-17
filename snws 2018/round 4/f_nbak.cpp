#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <string.h>
using namespace std;

#define sz(a) (int)(a).size()

#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fj(a,b) for(int j = (a); j <= (b); ++j)
#define fdi(a,b) for(int i = (a); i >= (b); --i)

#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef long long ll;

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << " : " << x << endl;
#else
#define dbg(x) while(0){}
#endif

#define MAX 1005

int n;

char mapa[MAX][MAX];

void solve() {
	scanf("%d", &n);
	int cntdot = (n - 1) / 2;
	fi(1, (n + 1) / 2) {
		fj(0, n - 1) {
			if (j < cntdot) {
				mapa[i][j] = '.';
			} else if(j < n - cntdot) {
				mapa[i][j] = 'S';
			}
		}
		cntdot--;
	}
	
	fi(1, n) {
		printf("%s\n", mapa[i]);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();
	return 0;
}