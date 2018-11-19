typedef complex<double> base;

int rev[MAX];
base wlen_pw[MAX];
 
void fft(base a[], int n, bool invert) {
	for (int i = 0; i < n; i++) {
		if (i < rev[i]) {
			swap (a[i], a[rev[i]]);
		}
	}
 
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * acos(-1.) / len * (invert ? -1 : +1);
		int len2 = len >> 1;
 
		base wlen(cos(ang), sin(ang));
		wlen_pw[0] = base(1, 0);
		
		for (int i = 1; i < len2; i++) {
			wlen_pw[i] = wlen_pw[i - 1] * wlen;
		}
 
		for (int i = 0; i < n; i += len) {
			base t;
			base *pu = a+i;
			base *pv = a+i+len2; 
			base *pu_end = a+i+len2;
			base *pw = wlen_pw;
			for (; pu != pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu += t;
			}
		}
	}
 
	if (invert) {
		for (int i=0; i<n; i++) {
			a[i] /= n;
		}
	}
}
 
void calc_rev(int n, int log_n) {
	for (int i = 0; i < n; i++) {
		rev[i] = 0;
		for (int j = 0; j < log_n; j++) {
			if (i & (1 << j)) {
				rev[i] |= 1 << (log_n - 1 - j);
			}
		}
	}
}

void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
	calc_rev();
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	size_t n = 1;
	while (n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	fa.resize(n);
	fb.resize(n);
 
	fft(fa, false);
	fft(fb, false);
	
	for (size_t i = 0; i < n; i++) {
		fa[i] *= fb[i];
	}
	fft(fa, true);
 
	res.resize (n);
	for (size_t i = 0; i < n; i++) {
		res[i] = int (fa[i].real() + 0.5);
	}
}
