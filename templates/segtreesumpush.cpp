int st[4 * MAX];
int upd[4 * MAX];

void push(int x, int tl, int tr) {
	st[x] += upd[x] * (tr - tl + 1);
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
	st[x] = st[2 * x] + st[2 * x + 1]; 
}

int get_sum(int l, int r, int tl = 1, int tr = n, int x = 1) {
    push(x, tl, tr);
    if (l == tl && r == tr) {
        return t[x];
    }
    int h = (tl + tr) / 2;
    push(2 * x, tl, h);
    push(2 * x + 1, h + 1, tr);
    if (r <= h) {
        return get_sum(l, r, tl, h, 2 * x);
    } else if (l >= h + 1) {
        return get_sum(l, r, h + 1, tr, 2 * x + 1);
    } else {
        return get_sum(l, h, tl, h, 2 * x) + get_sum(h + 1, r, h + 1, tr, 2 * x + 1);
    }
}

void update(int l, int r, int v, int tl = 1, int tr = n, int x = 1) {
    if (l == tl && r == tr) {
        upd[x] += v;
        return;
    }
    int h = (tl + tr) / 2;
    if (r <= h) {
        update(l, r, v, tl, h, 2 * x);
    } else if (l >= h + 1) {
        update(l, r, v, h + 1, tr, 2 * x + 1);
    } else {
        update(l, h, v, tl, h, 2 * x);
        update(h + 1, r, v, h + 1, tr, 2 * x + 1);
    }
    push(x, tl, tr);
    push(2 * x, tl, h);
    push(2 * x + 1, h + 1, tr);
    t[x] = t[2 * x] + t[2 * x + 1];
}
