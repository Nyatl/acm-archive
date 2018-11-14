//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381702

int n;
char s[MAX];
int z[MAX];

void zfunction() {
	int l = -1, r = -1;
	fi(2, n) {
		z[i] = 0;
		if (r >= i) {
			z[i] = min(z[i - l + 1], r - i + 1);
		}
		while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 >= r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}