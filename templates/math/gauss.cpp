//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381698
int a[MAX][MAX];
int n, m;
int ans[MAX];
int who[MAX];

bool gauss() {
	fill_n(&who[1], n, -1);
	int r = 1;
	for (int col = 1; col <= m; col++) {
		int p = -1;
		fi(r, n) {
			if (a[i][col]) {
				p = i;
				break;
			}
		}
		if (p == -1) {
			continue;
		}
		who[r] = col;
		fi(1, m + 1) {
			swap(a[r][i], a[p][i]);
		}
		fi(1, n) {
			if (i == r) continue;
			int c = dev(a[i][col], a[r][col]);
			fj(1, m + 1) {
				a[i][j] = sub(a[i][j], mul(a[r][j], c));
			}
		}
		r++;
	}
	fill_n(&ans[1], m, 0);
	fi(1, n) {
		if (!a[i][m + 1]) continue;
		if (who[i] == -1) return false;
		int c = dev(a[i][m + 1], a[i][who[i]]);
		ans[who[i]] = c;
	}
	return true;
}



