#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
/////////////////////

int const N = 1e5 + 41;
#define FILENAME "roads"

vector<int> e[N];
map<pii,int> h;
int n, m;

int getid(int l, int id){
	if(h.find(mp(l, id)) != h.end()) return h[mp(l, id)];
	int v = sz(h);
	h[mp(l, id)] = v;
	return v;
}

int cnte, from[N], to[N], cap[N], flow[N];

void push(int from, int to, int cap = 1){
	::from[cnte] = from;
	::to[cnte] = to;
	::cap[cnte] = cap;
	e[from].pb(cnte);
	++cnte;

	::from[cnte] = to;
	::to[cnte] = from;
	::cap[cnte] = 0;
	e[to].pb(cnte);
	++cnte;
}

char ans[55];
int a, b, c;
int fir[N], sec[N];
int S, T;
int by[N];
int w[N];

void clear(){
	fi(0, N) w[i] = 0;
}

void dfs(int u){
	w[u] = 1;
	fi(0, sz(e[u])){
		int id = e[u][i];
		if(cap[id] > flow[id]){
			int to = ::to[id];
			if(!w[to]){
				by[to] = id;
				dfs(to);
			}
		}
	}
}

int findflow(){
	clear();
	dfs(S);
	int ret = w[T];
	if(ret){
		int v = T;
		while(v != S){
			int id = by[v];
			flow[id] += 1;
			flow[(id ^ 1)] -= 1;
			v = from[id];
		}
	}
	return ret;
}

void buildnet(){
	S = getid(0, 0);
	T = getid(3, 0);
	fi(0, n){
		int cap = 1;
		if(i == c) cap = 2;
		int id1 = getid(1, i);
		int id2 = getid(2, i);
		push(id1, id2, cap);
	}
	fi(0, m){
		if(fir[i] == sec[i]) continue;
		int id1 = getid(2, fir[i]);
		int id2 = getid(1, sec[i]);
		push(id1, id2);
	}

	fi(0, m){
		if(fir[i] == sec[i]) continue;
		int id1 = getid(2, sec[i]);
		int id2 = getid(1, fir[i]);
		push(id1, id2);
	}
	push(S, getid(1, a));
	push(S, getid(1, b));
	push(getid(2, c), T, 2);
}

void solve(){
	buildnet();
	int f = 0;
	while(true){
		if(findflow()) ++f;
		else break;
		if(f == 2) break;
	}
	if(f != 2){
		sprintf(ans, "No\n");
	}else{
		sprintf(ans, "Yes\n");
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
#endif

	scanf("%d",&n);
	scanf("%d",&m);
	fi(0, m){
		scanf("%d %d",&fir[i],&sec[i]);
		--fir[i];
		--sec[i];
	}
	scanf("%d %d %d",&a,&b,&c);
	--a;--b;--c;

	solve();
	printf("%s\n",ans);

	return 0;
}