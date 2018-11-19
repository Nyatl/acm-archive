//tested: https://bacs.cs.istu.ru/submit_view.php?id=1382202

const int ROOT_PW = (1 << 20);

int MODS[3] = {985661441, 976224257, 975175681};
int ROOTS[3] = {717, 315, 1335};
int IROOTS[3] = {92105044, 951431260, 590949158}; 

int inv(int x, int MOD) {
	return bp(x, MOD - 2, MOD);
}

void fft (vi & a, int root, int iroot, int root_pw, int mod, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? iroot : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = inv(n, mod);
		fi(0, n - 1) {
			a[i] = int (a[i] * 1ll * nrev % mod);
		}
	}
}

void multiply (const vi & a, const vi & b, vi & res, int root, int iroot, int root_pw, int mod) {
	vi fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fi(0, sz(fa) - 1) {
		fa[i] %= mod;
	}
	fi(0, sz(fb) - 1) {
		fb[i] %= mod;
	}
 
	fft (fa, root, iroot, root_pw, mod, false),  fft (fb, root, iroot, root_pw, mod, false);
	fi(0, (int) n - 1) {
		fa[i] = mul(fa[i], fb[i], mod);
	}
	fft (fa, root, iroot, root_pw, mod, true);
 
	res.resize (n);
	fi(0, (int) n - 1) {
		res[i] = fa[i];
	}
}

int crt(const vi &mods, const vi &rems, int MOD) {
	int k = (rems[1] - rems[0]) % mods[1];
	if (k < 0) k += mods[1];
	k = mul(k, inv(mods[0], mods[1]), mods[1]);
	ll x = (ll) k * mods[0] + rems[0];

	k = (int) ( (rems[2] - x) % mods[2]);
	if (k < 0) k += mods[2];
	k = mul(k, inv(mul(mods[0], mods[1], mods[2]), mods[2]), mods[2]);

	int res = 0;
	res = add(res, (int) (x % MOD), MOD);

	int tmp = mul(mods[0], mods[1], MOD);
	tmp = mul(tmp, k, MOD);
	res = add(res, tmp, MOD);

	return res;
}

vi multiply(const vi &a, const vi &b, int MOD) {	
	vector<vi> resp;
	fi(0, 2) {	
		vi c;
		multiply(a, b, c, ROOTS[i], IROOTS[i], ROOT_PW, MODS[i]);
		resp.pb(c);
	}
	vi res;
	fi(0, sz(resp[0]) - 1) {
		vi rems;
		vi mods;
		fo(0, 2) {
			rems.pb(resp[o][i]);
			mods.pb(MODS[o]);
		}
		int g = crt(mods, rems, MOD);
		res.pb(g);
	}
	return res;
}