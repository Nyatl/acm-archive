//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381782

int ext_gcd(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = ext_gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

void shift_solution(int &x, int &y, int a, int b, int cnt) {
	x += cnt * b;
	y -= cnt * a;
}

bool find_any_solution (int a, int b, int c, int &x0, int &y0, int &g) {
	g = ext_gcd(abs(a), abs(b), x0, y0);
	if (c % g != 0) {
		return false;
	}
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 *= -1;
	if (b < 0) y0 *= -1;
	return true;
}