#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define sz(a) (int)(a).size()

#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fdi(a,b) for(int i = (a); i >= (b); --i)

#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef long long ll;

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << " : " << x << endl;
#else
#define dbg(x) while(0){}
#endif

#define MAXN 100005

int n, m;

int a[MAXN];

void solve() {
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	int mina = 1000000005;
	int maxa = 0;
	fi(1, n) {
		mina = min(mina, a[i]);
		maxa = max(maxa, a[i]);
	}
	int ans = 0;
	if (mina < m) {
		ans += (m - mina);
	}
	if (maxa > m) {
		ans += (maxa - m);
	}
	printf("%d", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	solve();
	
	return 0;
}