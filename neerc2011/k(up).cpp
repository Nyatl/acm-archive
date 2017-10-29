#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
///////////////////

int const N = 1e5 + 41;

vector<pii> ans;
int n;
vector<int> e[N];
int d[N], dmax[N], par[N];

void dfs(int x, int p){
	par[x] = p;
	if(sz(e[x]) == 1){
		d[x] = 1;
		dmax[x] = x;
	}else{
		dmax[x] = -1;
	}
	fi(0, sz(e[x])){
		int y = e[x][i];
		if(y == p) continue;
		dfs(y, x);
		d[x] += d[y];
		if(dmax[x] == - 1 || d[dmax[x]] < d[y]) dmax[x] = y;
	}
}

vector<vector<int>> a;

void go(int x, int p, vector<int> &v){
	if(sz(e[x]) == 1) v.pb(x);
	fi(0, sz(e[x])){
		int y = e[x][i];
		if(y == p) continue;
		go(y, x, v);
	}
}

void merge(pii x, pii y){
	int fir = a[x.second].back();
	a[x.second].pop_back();
	int sec = a[y.second].back();
	a[y.second].pop_back();
	ans.pb(mp(fir, sec));
}

void solve(){
	if(n == 2){
		printf("1\n");
		printf("1 2\n");
		exit(0);
	}

	int root = 0;
	fi(0, n) if(sz(e[i]) > sz(e[root])) root = i;
	dfs(root, -1);

	int all = d[root];
	int r = root;

	while(true){
		if(d[dmax[root]] * 2 <= all){
			fi(0, sz(e[root])){
				int y = e[root][i];
				a.pb(vector<int>());
				go(y, root, a.back());
			}
			break;
		}
		root = dmax[root];
	}

	set<pii> t;
	fi(0, sz(a)){
		t.insert(mp(sz(a[i]), i));
	}

	while(sz(t) > 1){
		set<pii> :: iterator it = t.end();
		--it;
		pii x, y;
		x = (*it);
		--it;
		y = (*it);
		t.erase(x);
		t.erase(y);

		merge(x, y);

		--x.first;
		--y.first;
		if(x.first) t.insert(x);
		if(y.first) t.insert(y);
	}
	if(sz(t) == 1){
		set<pii> :: iterator it = t.end();
		--it;
		pii x, y;
		x = (*it);
		ans.pb(mp(a[x.second].back(), r));
	}
}

#define FILENAME "kingdom"
int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
#endif

	scanf("%d",&n);
	fi(0, n-1){
		int u, v;
		scanf("%d %d",&u,&v);
		--u;--v;
		e[u].pb(v);
		e[v].pb(u);
	}

	solve();

	printf("%d\n",sz(ans));
	fi(0, sz(ans)){
		printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	}

	return 0;
}