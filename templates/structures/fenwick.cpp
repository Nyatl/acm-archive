//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381051

ll F[MAX];

void init() {
	fill_n(&F[0], n + 1, 0LL);
}

void upd(int x, ll v) {
	while (x <= n) {
		F[x] += v;
		x |= (x + 1);
	}
}

ll getsum(int x) {
	ll res = 0;
	while (x > 0) {
		res += F[x];
		x = (x & (x + 1)) - 1;
	}
	return res;
}

ll getsum(int l, int r) {
	return getsum(r) - getsum(l - 1);
}

void setval(int x, ll v) {
	upd(x, v - getsum(x, x));
}

void build() {
	fi(1, n) {
		setval(i, a[i]);
	}
}
