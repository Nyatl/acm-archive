pair<ll, ll> findfract(double x0) {
	double x = x0;

	vector<ll> a, p, q;
	a.pb((ll) x);	

	x = x - a[0];
	p.pb(1);
	q.pb(0);
	p.pb(a[0]);
	q.pb(1);

	for (int i = 2; true; i++) {
		double current = (double) p[i - 1] / q[i - 1];
		if (eq(current, x0)) {
			return mp(p[i - 1], q[i - 1]);
		}
		a.pb((ll) (1 / x));
		x = 1 / x - a.back();
		p.pb(a[i - 1] * p[i - 1] + p[i - 2]);
		q.pb(a[i - 1] * q[i - 1] + q[i - 2]);		
	}

	assert(false);
	return mp(-1, -1);
}