//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381705

int n, m;
vi e[MAX];
vi et[MAX];

int cnt;
int order[MAX];
int comp[MAX];
int u[MAX];
int col;

void dfs(int x) {
	u[x] = 1;
	for (int y : e[x]) {
		if (u[y]) continue;
		dfs(y);
	}
	order[cnt] = x;
	cnt--;
}

void dfs2(int x) {
	comp[x] = col;
	u[x] = 1;
	for (auto y : et[x]) {
		if (u[y]) continue;
		dfs2(y);
	}
}

void scc() {
	col = 0;
	fill_n(&u[1], n, 0);
	cnt = n;
	fi(1, n) {
		if (!u[i]) {
			dfs(i);
		}
	}
	fill_n(&u[1], n, 0);
	fi(1, n) {
		if (!u[order[i]]) {
			col++;
			dfs2(order[i]);
		}
	}
}
