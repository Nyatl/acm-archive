#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstring>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define pb push_back
////////////////////

int const N = 1e4 + 41;

int n, m;
vector<int> e[N], et[N];
int color, col[N], order[N];
int w[N];
int cnt;
int ans;

void clear(){
	memset(w, 0, sizeof(w));
}

void dfs(int x){
	w[x] = 1;
	fi(0, sz(e[x])){
		int y = e[x][i];
		if(!w[y]) dfs(y);
	}
	order[cnt++] = x;
}

vector<int> ec[N];
int csz[N], f[N];

void dfst(int x, int color){
	col[x] = color;
	++csz[color];
	w[x] = 1;
	fi(0, sz(et[x])){
		int y = et[x][i];
		if(w[y]) continue;
		dfst(y, color);
	}
}

void mark(int x){
	w[x] = 1;
	f[x] = 1;
	fi(0, sz(ec[x])){
		int y = ec[x][i];
		if(!w[y]) mark(y);
	}
}

int rec(int x){
	if(w[x]) return f[x];
	w[x] = 1;
	int res = 0;

	fi(0, sz(ec[x])){
		int y = ec[x][i];
		res = max(res, rec(y));
	}

	f[x] = res;
	return res;
}

void solve(){
	clear();
	fi(0, n) if(!w[i]) dfs(i);
	clear();
	fdi(n, 0) if(!w[order[i]]){
		dfst(order[i], color);
		++color;
	}

	fi(0, n){
		int x = col[i];
		fj(0, sz(e[i])){
			int y = col[e[i][j]];
			ec[y].pb(x);
		}
	}

	fi(0, color){
		clear();
		mark(i);
		fj(0, color){
			if(rec(j)){
				ans += csz[j] * csz[i];
			}
		}
	}
}


int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d %d",&n,&m);
	fi(0, m){
		int x, y;
		scanf("%d %d",&x,&y);
		--x;--y;
		e[x].pb(y);
		et[y].pb(x);
	}

	solve();

	printf("%d\n",ans);

	return 0;
}