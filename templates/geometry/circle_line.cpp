//tested: https://bacs.cs.istu.ru/submit_view.php?id=1382037

int intersect(double a, double b, double c, double r, double &x1, double &y1, double &x2, double &y2) {
	bool flag = false;
	int res = 0;

	if (b == 0) {
		swap(a, b);
		flag = true;
	}
	ld A = 1 + sqr(a / b);
	ld B = 2 * a * c / sqr(b);
	ld C = sqr(c / b) - sqr(r);
		
	ld D = B * B - 4 * A * C;

	if (D < 0) {
		res = 0;
	} else if (D < EPS) {
		res = 1;
		x1 = (-B + sqrt(D)) / (2 * A);
		y1 = (-a * x1 - c) / b;		
	} else {
		x1 = (-B - sqrt(D)) / (2 * A);
		y1 = (-a * x1 - c) / b;
		x2 = (-B + sqrt(D)) / (2 * A);
		y2 = (-a * x2 - c) / b;
		res = 2;
	}
	if (flag) {
		swap(x1, y1);
		swap(x2, y2);
	}
	return res;
}
