#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
//////////////////////

int const N = 2e5 + 41;

vector<int> ans;
int n, m, p[N];
vector<int> e[N];
int w[N];
int s[N];

struct Event{
	int v, p, s;
	Event(){};
	Event(int v, int p, int s) : v(v), p(p), s(s) {};
};

vector<Event> h;

void dfs(int u){
	w[u] = 1;
	fi(0, sz(e[u])){
		int to = e[u][i];
		if(!w[to]) dfs(to);
	}
}

int find(int u){
	if(p[u] == u) return p[u];
	return find(p[u]);
}

void uni(int a, int b){
	h.pb(Event(a, p[a], s[a]));
	h.pb(Event(b, p[b], s[b]));
	a = find(a);
	b = find(b);
	h.pb(Event(a, p[a], s[a]));
	h.pb(Event(b, p[b], s[b]));
	if(s[a] > s[b]) swap(a, b);
	if(a != b){
		s[b] += s[a];
		p[a] = b;
	}
}

void pushline(int l, int r, int tl, int tr){
	fi(l, r+1){
		fj(0, sz(e[i])){
			int to = e[i][j];
			if(tl <= to && to <= tr) continue;
			uni(i, to);
		}
	}
}

void pop(){
	Event cur = h.back();
	h.pop_back();
	p[cur.v] = cur.p;
	s[cur.v] = cur.s;
}

void pop(int s){
	while(sz(h) > s) pop();
}

void rec(int l, int r){
	if(l > r) return;
	int sb = sz(h);
	if(l == r){
		if(find(0) != find(n-1) && l != 0 && l != n - 1){
			ans.pb(l);
		}
		pop(sb);
		return;
	}
	int m = (l+r)/2;

	pushline(l, m, m+1, r);
	rec(m+1, r);
	pop(sb);

	pushline(m+1, r, l, m);
	rec(l, m);
	pop(sb);
}

void solve(){
	fi(0, n) p[i] = i, s[i] = 1;
	dfs(0);
	if(!w[n-1]) return;
	rec(0, n-1);
}

#define FILENAME "travel"

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
#endif

	scanf("%d %d",&n,&m);
	fi(0, m){
		int u, v;
		scanf("%d %d",&u,&v);
		--u;--v;
		e[u].pb(v);
		e[v].pb(u);
	}

	solve();

	printf("%d\n",sz(ans));
#ifdef _DEBUG
	fi(0, sz(ans)) printf("%d\n",ans[i]);
#endif

	return 0;
}