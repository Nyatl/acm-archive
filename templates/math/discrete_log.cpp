//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381874
int calc(int a, int b, int MOD) {
	int SQRT = (int) sqrt((double) MOD);
	int q = (MOD + SQRT - 1) / SQRT;
	unordered_map<int, int> mem;

	int p0 = bp(a, SQRT, MOD);
	int p = 1;
	fi(1, q) {		
		p = mul(p, p0, MOD);
		if (!mem.count(p)) mem[p] = i * SQRT;		
	}
	
	int res = -1;

	int cur = b;
	fi(0, SQRT) {		
		if (mem.count(cur)) {			
			if (mem[cur] - i >= 0 && mem[cur] - i < MOD) {
				res = mem[cur] - i;
			}
		}		
		cur = mul(cur, a, MOD);
	}

	return res;
}