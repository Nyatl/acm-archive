#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include <queue>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define fdj(a,b) for(int j=a-1;j>=b;--j)
#define fdo(a,b) for(int o=a-1;o>=b;--o)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
///////////////////

char a[505][505];

void solve(){
	
}

pii d[2] = {make_pair(0, 1), make_pair(0, -1)};
int n, m;

void bfs(){
	queue<pii> q;
	fi(0, m){
		if(a[0][i] != '#') {
			q.push(mp(0, i));
		}
	}
	while(q.size()){
		pii t = q.front();
		q.pop();
		if(a[t.first][t.second] != '.') {
			continue;
		}
		a[t.first][t.second] = '*';
		if(t.first + 1 < n && a[t.first + 1][t.second] == '.'){
			q.push(mp(t.first + 1, t.second));
		} else {
			fi(0, 2){
				pii to = t;
				to.first += d[i].first;
				to.second += d[i].second;
				if(to.first < n && to.second < m && to.second >= 0 && a[to.first][to.second] == '.'){
					q.push(to);
				}
			}
		}
	}
}

#define FILENAME "mole"

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);
#endif

	solve();
	scanf("%d%d", &n, &m);
	fi(0, n){
		fj(0, m){
			scanf(" %c", &a[i][j]);
		}
	}
	bfs();
	bool ind = 0;
	fi(0, n){
		fj(0, m){
			if(!ind &&  a[i][j] == '.'){
				a[i][j] = 'X';
				ind = 1;
			}
			if(a[i][j] == '*') {
				a[i][j] = '.';
			}
		}
	}
	if (!ind) {
		printf("No");
		return 0;
	}
	printf("Yes\n");
	fi(0, n){
		fj(0, m){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}