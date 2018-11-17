//tested: https://bacs.cs.istu.ru/submit_view.php?id=1382016

int phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res -= res / i;
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n != 1) {
		res -= res / n;
	}
	return res;
}

int add(int a, int b, int MOD) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b, int MOD) {
	return (ll) a * b % MOD;
}

int bp(int x, int d, int MOD) {
	int res = 1;
	while (d) {
		if (d & 1) res = mul(res, x, MOD);
		x = mul(x, x, MOD);
		d >>= 1;
	}
	return res;
}

int inv(ll x, int MOD) {
	int x2 = (int) (x % MOD);
	return bp(x2, phi(MOD) - 1, MOD);
}

ll crt() {
	ll rem = r[1];
	ll mod = m[1];
	fi(2, n) {
		int rr = (int) ((r[i] - rem) % m[i]);
		if (rr < 0) rr += m[i];
		int resp = inv(mod, m[i]);
		ll k = ((ll) rr * resp) % m[i];
		rem = rem + mod * k;
		mod *= m[i];
	}
	return rem;
}