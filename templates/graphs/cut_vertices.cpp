//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381656

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
