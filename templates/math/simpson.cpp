//tested: https://bacs.cs.istu.ru/submit_view.php?id=1382030

double simpson(double a, double b) {
	double res = 0;
	while (a + STEP <= b) {
		res += f(a) + 4 * f((a + a + STEP) * 0.5) + f(a + STEP);
		a += STEP;
	}
	res *= (STEP / 6);
	return res;
}