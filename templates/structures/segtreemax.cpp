//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381032

int st[4 * MAX];

void build(int tl = 1, int tr = n, int x = 1) {
	if (tl == tr) {
		st[x] = a[tl];
		return;
	}
	int h = (tl + tr) / 2;
	build(tl, h, 2 * x);
	build(h + 1, tr, 2 * x + 1);
	st[x] = max(st[2 * x], st[2 * x + 1]); 
}

int get_max(int l, int r, int tl = 1, int tr = n, int x = 1) {
	if (l == tl && r == tr) {
		return st[x];
	}
	int h = (tl + tr) / 2;
	if (r <= h) {
		return get_max(l, r, tl, h, 2 * x);
	} else if (l >= h + 1) {
		return get_max(l, r, h + 1, tr, 2 * x + 1);
	} else {
		return max(get_max(l, h, tl, h, 2 * x), get_max(h + 1, r, h + 1, tr, 2 * x + 1)); 
	}
}

void update(int p, int v, int tl = 1, int tr = n, int x = 1) {
	if (tl == tr) {
		st[x] = v;
		return;
	}
	int h = (tl + tr) / 2;
	if (p <= h) {
		update(p, v, tl, h, 2 * x);
	} else {
		update(p, v, h + 1, tr, 2 * x + 1);
	}
	st[x] = max(st[2 * x], st[2 * x + 1]);
}
