#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<deque>
#include<algorithm>
#include<ctime>
#include<memory>
#include<memory.h>

using namespace std;

#define sz(a) int((a).size())

#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fk(a, b) for(int k = (a); k < (b); ++k)

#define all(a) (a).begin(),(a).end()
#define _(a, b) memset(a, b, sizeof(a))

string s;
int n;

void read() {
	cin >> s;
	n = sz(s);
}

void solve() {
	reverse(s.begin(), s.end());
	long long wC = 0, cC = 0;
	double ans = 0;
	double sumAns = 0;
	fi(1, n + 1){
		ans = sumAns / i;
		if (s[i - 1] == 'W'){
			wC += i;
			ans += cC * 1.0 / i;
		}
		else{
			cC += i;
			ans += wC * 1.0 / i;
		}
		sumAns += ans;
	}

	printf("%.9lf\n", ans);
}

#define FILENAME "foreign"

void prepare() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
}

int main() {
	prepare();
	read();
	solve();
	return 0;
}