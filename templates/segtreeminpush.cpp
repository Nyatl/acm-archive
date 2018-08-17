int st[4 * MAX];
int upd[4 * MAX];

void push(int x) {
	st[x] += upd[x];
	if (2 * x < 4 * MAX) upd[2 * x] += upd[x];
	if (2 * x + 1 < 4 * MAX) upd[2 * x + 1] += upd[x];
	upd[x] = 0;
}

void build(int tl = 1, int tr = n, int x = 1) {
	if (tl == tr) {
		st[x] = a[tl];
		return;
	}
	int h = (tl + tr) / 2;
	build(tl, h, 2 * x);
	build(h + 1, tr, 2 * x + 1);
	st[x] = min(st[2 * x], st[2 * x + 1]); 
}

int get_min(int l, int r, int tl = 1, int tr = n, int x = 1) {
	push(x);
	if (l == tl && r == tr) {
		return st[x];
	}
	push(2 * x);
	push(2 * x + 1);
	int h = (tl + tr) / 2;
	if (r <= h) {
		return get_min(l, r, tl, h, 2 * x);
	} else if (l >= h + 1) {
		return get_min(l, r, h + 1, tr, 2 * x + 1);
	} else {
		return min(get_min(l, h, tl, h, 2 * x), get_min(h + 1, r, h + 1, tr, 2 * x + 1)); 
	}
}

void update(int l, int r, int v, int tl = 1, int tr = n, int x = 1) {
	push(x);
	if (l == tl && r == tr) {
		upd[x] += v;
		push(2 * x);
		push(2 * x + 1);
		return;
	}
	push(2 * x);
	push(2 * x + 1);
	int h = (tl + tr) / 2;
	if (r <= h) {
		update(l, r, v, tl, h, 2 * x);
	} else if (l >= h + 1) {
		update(l, r, v, h + 1, tr, 2 * x + 1);
	} else {
		update(l, h, v, tl, h, 2 * x);
		update(h + 1, r, v, h + 1, tr, 2 * x + 1); 
	}
	st[x] = min(st[2 * x], st[2 * x + 1]);
}