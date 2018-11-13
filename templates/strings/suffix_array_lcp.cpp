//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381643
//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381654

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

int lcp[MAX][LOG];
int deg[MAX];

int getmin(int l, int r) {
	int d = deg[r - l + 1];
	return min(lcp[l][d], lcp[r - (1 << d) + 1][d]);
}

int getlcp(int x, int y, int lx, int rx, int ly, int ry) {
	int px = invp[startpos[x - 1] + lx - 1];
	int py = invp[startpos[y - 1] + ly - 1];	
	if (px == py) return min(rx - lx + 1, ry - ly + 1);
	if (px > py) swap(px, py);
	int res = getmin(px + 1, py);
	res	= min(res, min(rx - lx + 1, ry - ly + 1));
	return res;
}

void build_lcp() {
	fi(0, LOG - 1) {
		deg[(1 << i)] = i;
	}
	fi(1, N) {
		if (!deg[i]) deg[i] = deg[i - 1];
	}

	fo(0, LOG - 1) {
		fi(0, N - 1) {
			lcp[i][o] = 0;
		}
	}

	int cur = 0;
	fi(0, N - 1) {
		cur--;
		cur = max(cur, 0);
		int x = invp[i];
		if (x == 0) {
			lcp[x][0] = 0;
			continue;
		}
		int a = i;
		int b = p[x - 1];
		while (a + cur < N && b + cur < N && s[a + cur] == s[b + cur]) {
			cur++;
		}
		lcp[x][0] = cur;
	}

	fo(1, LOG - 1) {
		for (int i = 0; i + (1 << o) - 1 < N; i++) {
			lcp[i][o] = min(lcp[i][o - 1], lcp[i + (1 << (o - 1))][o - 1]);
		}
	}
}

int norm(int x) {
	x %= N;
	if (x < 0) x += N;
	return x;
}

void suffix_array(vector<string> vs) {
	N = 0;	
	s[N++] = '#';
	fi(0, sz(vs) - 1) {
		startpos[i] = N;
		fo(0, sz(vs[i]) - 1) {
			s[N] = vs[i][o];
			N++;
		}
		s[N++] = '#';		
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

	build_lcp();

	q = max(q, 255);
	fill_n(&pref[0], q + 1, 0);
	fill_n(&cnt[0], q + 1, 0);		
}