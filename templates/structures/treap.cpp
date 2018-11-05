//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381055

mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());

int getrandint(int l, int r) {
	ll res = generator();
	return (int) (res % (r - l + 1) + l);
}

set<int> tnums;

int getpriority() {
	while (1) {
		int x = getrandint(0, (1 << 30));
		if (!tnums.count(x)) { 
			tnums.insert(x);
			return x;
		}
	}	
}

struct Treap {
	Treap *l, *r;
	int p, k, q;
	Treap () {
		l = r = NULL;
	};
	Treap (int k) {
		p = getpriority();
		this->k = k;
		l = r = NULL;
		q = 1;
	};
};

Treap *root;

void update(Treap *t) {
	if (!t) return;
	t->q = 1;
	if (t->l) t->q += t->l->q;
	if (t->r) t->q += t->r->q;
}

void merge(Treap *& t, Treap *l, Treap *r) {
	if (!l || !r) {
		t = (l ? l : r);	
	} else {
		if (l->p > r->p) {
			t = l;
			merge(t->r, l->r, r);			
		} else {
			t = r;
			merge(t->l, l, r->l);
		}
		update(t);
	}
}

void split(Treap *t, Treap *& l, Treap *& r, int k) {	
	if (!t) {
		l = r = NULL;
	} else {		
		if (t->k < k) {
		  l = t;
		  split(t->r, l->r, r, k);		  
		} else {
			r = t;
		  split(t->l, l, r->l, k);		 
		}
		update(l);
		update(r);
	}
}

void insert(int k) {
	Treap *ver = new Treap(k);
	Treap *l = NULL, *r = NULL;
	split(root, l, r, k);
	merge(root, l, ver);
	merge(root, root, r);
}

int getless(int k) {
	Treap *l = NULL, *r = NULL;	
	split(root, l, r, k);	
	int res = (l ? l->q : 0);
	merge(root, l, r);
	return res;
}
