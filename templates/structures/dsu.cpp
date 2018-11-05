//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381045

struct Node {
	int c;
	Node *p;
	Node(int c): c(c) {
		p = this;
	}
}

Node *node[MAX];

Node *find(Node *x) {
	if (x->p == x) return x;
	return x->p = find(x->p);
}

void unite(Node *x, Node *y) {
	find(x)->p = find(y);
}

void unite(int a, int b) {
	unite(node[a], node[b]);
}

int get_color(int x) {
	return find(node[x])->c;
}
