#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <bitset>

using namespace std;

#define MAX 5020
#define MOD 1000000007

int n;
char str[MAX];
char rev[MAX];

int d1[MAX][MAX], d2[MAX][MAX];

int add(int a, int b) {
	return (a + b) % MOD;
}

int mult(int a, int b) {
	return (int)(((long long)a * b) % MOD);
}

int mult(int a, int b, int c, int d) {
	return mult(mult(a, b), mult(c, d));
}

int fac[MAX];

int fun(int x, int q, char *s, int d[MAX][MAX]) {
	if (x == 0) return q == 0;
	if (q == 0 || q > n) return 0;
	if (d[x][q] != -1) return d[x][q];
	int res = 0;
	if (s[x] == '<') {
		res = add(res, mult(fun(x - 1, q, s, d), q));
		res = add(res, mult(fun(x - 1, q + 1, s, d), mult(q, q + 1)));
	} else if (s[x] == '>') {
		res = add(res, mult(fun(x - 1, q, s, d), q));
		res = add(res, fun(x - 1, q - 1, s, d));
	}
	return d[x][q] = res;
}

void print(int x, int q) {
	fprintf(stderr, "%d\n", fun(x, q, str, d1));
}

void solve() {
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 0; j <= n; j++) {
			ans = add(ans, mult(fun(i - 1, j, str, d1), fun(n - i, j, rev, d2), fac[j], fac[j]));
			ans = add(ans, mult(fun(i - 1, j, str, d1), fun(n - i, j, rev, d2), fac[j], fac[j]));			
			ans = add(ans, mult(fun(i - 1, j + 1, str, d1), fun(n - i, j, rev, d2), fac[j + 1], fac[j]));
			ans = add(ans, mult(fun(i - 1, j, str, d1), fun(n - i, j + 1, rev, d2), fac[j], fac[j + 1]));
		}
		printf("%d ", ans);
	}
	printf("\n");
}

void init() {
	fac[0] = 1;
	for (int i = 1; i <= 5000; i++) {
		fac[i] = mult(fac[i - 1], i);
	}
}

int main() {
	scanf("%s", str + 1);
	strcpy(rev + 1, str + 1);
	
	n = strlen(str + 1);

	if (n == 1) {
		printf("1\n");
		return 0;
	}
	
	reverse(rev + 1, rev + n + 1);
	for (int i = 1; i <= n; i++) {
		if (rev[i] == '<') rev[i] = '>';
		else rev[i] = '<';
	}

	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));

	init();	
	solve();
}