//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381494

int tin[MAX];
int fup[MAX];
int cnt;
int bridge[MAX];

void dfs(int x, int p = -1) {
	cnt++;
	fup[x] = tin[x] = cnt;
	for (auto z : e[x]) {
		int y = z.first;
		int ind = z.second;
		if (y == p) continue;
		if (tin[y] == 0) {
			dfs(y, x);
			if (fup[y] > tin[x]) {
				bridge[ind] = 1;
			}
			fup[x] = min(fup[x], fup[y]);
		} else {
			fup[x] = min(fup[x], tin[y]);
		}
	}	
}

void findbridges() {
	fill_n(&ans[1], m, 0);
	fill_n(&tin[1], n, 0);
	fill_n(&fup[1], n, 0);
	cnt = 0;

	fi(1, n) {
		if (tin[i]) continue;		
		dfs(i);
	}
}
