#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
/////////////////////

int const N = 5e3 + 41;
int const MOD = 1e9 + 7;

int n;
char s[N];
int f[N];

void add(int  &a, int b){
	a += b;
	if(a >= MOD) a -= MOD;
}

int mul(int a, int b){
	return a * 1LL * b % MOD;
}

void init(){
	f[0] = 1;
	fi(1, N){
		f[i] = mul(f[i-1], i);
	}
}

int dp[N][N], ds[N][N];

void reverse(){
	fi(0, n) if(s[i] == '<') s[i] = '>';
	else s[i] = '<';
	fi(0, (n+1)/2){
		swap(s[i], s[n-1-i]);
	}
}

void calcdp(int d[N][N]){
	d[0][0] = 1;
	fi(0, n){
		fj(0, n){
			int c = d[i][j];
			if(s[i] == '<'){
				int v1 = mul(c, j);
				add(d[i+1][j], v1);
				if(j > 1){
					int w = mul(j, j-1);
					int v2 = mul(w, c);
					add(d[i+1][j-1], v2);
				}
			}else{
				add(d[i+1][j+1], c);
				int v1 = mul(c, j);
				add(d[i+1][j], v1);
			}
		}
	}
}

int ans[N];
int d1[3] = {0, 1, 0};
int d2[3] = {0, 0, 1};

void solve(){
	n = strlen(s);
	calcdp(dp);
	reverse();
	calcdp(ds);
	reverse();
	fi(0, n){
		int id = i;
		int rid = n-1-i;
		fj(0, n){
			fo(0, 3){
				int c1 = j + d1[o];
				int c2 = j + d2[o];
				int mn;
				if(c1 == c2) mn = 2;
				else mn = 1;
				int w = mul(dp[id][c1], ds[rid][c2]);
				int p = mul(f[c1], f[c2]);
				int res = mul(w, p);
				res = mul(res, mn);
				add(ans[i], res);
			}
		}
	}
}

int main(){
//#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
//#endif

	scanf("%s", s);

	init();
	solve();

	if(n == 1) ans[0] = 1;
	fi(0, n){
		printf("%d ",ans[i]);
	}

	return 0;
}