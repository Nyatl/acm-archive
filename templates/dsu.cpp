struct Node {
	int c;
	Node *p;
	Node(int c): c(c) {}
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
