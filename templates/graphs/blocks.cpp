//NOT TESTED!!!
//THIS CODE IS THE SOLUTION FOR templates_blocks, templates_blocks hasn't checker now!!!
vpii e[MAX];

int ans[MAX];

int tin[MAX];
int fup[MAX];
int cnt;

void dfs(int x, int p = -1) {
	cnt++;
	fup[x] = tin[x] = cnt;
	int q = 0;
	bool flag = false;
	for (auto z : e[x]) {
		int y = z.first;		
		if (y == p) continue;
		if (tin[y] == 0) {
			q++;
			dfs(y, x);
			if (fup[y] >= tin[x]) {
				flag = 1;
			}
			fup[x] = min(fup[x], fup[y]);
		} else {
			fup[x] = min(fup[x], tin[y]);
		}
	}	
	if (p == -1) {
	  if (flag && q > 1) {
	  	ans[x] = 1;
	  }
	} else {
		ans[x] = flag;
	}
}

void cutvertices() {
	fill_n(&ans[1], n, 0);
	fill_n(&tin[1], n, 0);
	fill_n(&fup[1], n, 0);
	cnt = 0;

	fi(1, n) {
		if (tin[i]) continue;		
		dfs(i);
	}
}

int u[MAX];
int color[MAX];
int col;

void dfs2(int x, int curcolor, int p = -1) {
	u[x] = 1;
	for (auto z : e[x]) {
		int y = z.first;
		int id = z.second;
		if (y == p) continue;
		if (u[y]) {
			if (tin[y] < tin[x]) {
				color[id] = curcolor;
			}
		} else {
			int newcolor = curcolor;
			if (fup[y] >= tin[x]) {
				newcolor = ++col;				
			}
			color[id] = newcolor;
			dfs2(y, newcolor, x);
		}
	}
}

vector<vpii> block;

bool cmp(const vpii &a, const vpii &b) {
	return sz(a) > sz(b);
}

void findblocks() {
	cutvertices();	
	col = 0;
	fill_n(&u[1], n, 0);
	fi(1, n) {
		if (!u[i]) {
			col++;
			dfs2(i, col);
		}
	}	
	block.clear();
	block.resize(col);
	fi(1, n) {
		for (auto z : e[i]) {
			if (i < z.first) {
				block[color[z.second] - 1].pb(mp(i, z.first));
			}
		}
	}
	sort(block.begin(), block.end(), cmp);
	while (sz(block) && sz(block.back()) == 0) {
		block.pop_back();
	}
}

