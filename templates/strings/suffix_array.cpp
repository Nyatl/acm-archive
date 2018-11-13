//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381605

char s[MAX];
int p0[MAX];
int p[MAX];
int cl[MAX];
int cl0[MAX];
int cnt[MAX];
int pref[MAX];

int startpos[MAX];
int invp[MAX];
int N;

int norm(int x) {
	x %= N;
	if (x < 0) x += N;
	return x;
}

void suffix_array(vector<string> vs) {
	N = 0;	
	fi(0, sz(vs) - 1) {
		startpos[i] = N;
		fo(0, sz(vs[i]) - 1) {
			s[N] = vs[i][o];
			N++;
		}
		s[N] = '#';
		N++;
	}	
	
	fi(0, N - 1) {
		cl[i] = s[i];
		cnt[cl[i]]++;		
	}

	int q = 255;
	fi(0, q) {
		pref[i] = cnt[i];
		if (i) { 
			pref[i] += pref[i - 1];
		}
	}	
	fi(0, N - 1) {
		p[--pref[cl[i]]] = i;
	}

	int len = 1;

	while (len < N) {
		fill_n(&cnt[0], q + 1, 0);
		fill_n(&pref[0], q + 1, 0);		
	  
	  	fi(0, N - 1) {
	  		cnt[cl[i]]++;
	  	}	  
	  	fi(0, q) {
			pref[i] = cnt[i];
			if (i) { 
				pref[i] += pref[i - 1];
			}	
		}
		
		fdi(N - 1, 0) {
			int x = norm(p[i] - len);
			p0[--pref[cl[x]]] = x;
		}
				
		fi(0, N - 1) {
			p[i] = p0[i];
		}

		int q0 = 0;
		cl0[p[0]] = q0;
		fi(1, N - 1) {
			int a = cl[p[i - 1]];
			int b = cl[norm(p[i - 1] + len)];
			int a2 = cl[p[i]];
			int b2 = cl[norm(p[i] + len)];
			if (a != a2 || b != b2) {
				q0++;
			}
			cl0[p[i]] = q0;
		}

		fi(0, N - 1) {
			cl[i] = cl0[i];
		}				
		q = q0;
		len *= 2;
	}

	fi(0, N - 1) {
		invp[p[i]] = i;
	}

	q = max(q, 255);
	fill_n(&pref[0], q + 1, 0);
	fill_n(&cnt[0], q + 1, 0);		
}
