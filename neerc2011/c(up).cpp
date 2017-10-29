#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
///////////////////

int const N = 2e3 + 41;
int const M = 41;
int const K = 259;
int const INF = 1e9 + 41;

int m, n, k, smin, smax;

char matr[M][N];
char l[K][M][M];
char st[M], en[M];
int shst[M];

void read(){
	scanf("%d %d %d %d %d\n",&m,&n,&k,&smin,&smax);
	fi(0, m){
		scanf("%[^\n]",matr[i]);
		getchar();
	}
#ifdef _DEBUG
	fi(0, m){
		printf("%s\n",matr[i]);
	}
#endif
	scanf("%[^\n]",st);
	getchar();
	int l = strlen(st);
	fi(0, l) scanf("%d",&shst[i]);
	getchar();
	scanf("%[^\n]",en);
	l = strlen(en);
	getchar();
#ifdef _DEBUG
	printf("%s\n%s\n",st,en);
	fi(0, strlen(st)) printf("%d ",shst[i]);
	printf("\n");
#endif
}

void draw(int id, int x){
	fi(0, m){
		fj(0, k){
			l[id][i][j] = matr[i][x+j];
		}
	}
}

void drawletters(){
	int p = 0;
	int n = strlen(matr[0]);
	while(p < n){
		draw(matr[0][p], p+2);
#ifdef _DEBUG
		fi(0, m){
			printf("%s\n",l[matr[0][p]][i]);
		}
		printf("\n");
#endif
		p += k + 3;
	}
	fi(0, m) fj(0, k) l[' '][i][j] = '.';
}

char stmatr[M][N], enmatr[M][N];

void place(int id, int x, char matr[M][N]){
	fi(0, m) fj(0, k){
		matr[i][x+j] = l[id][i][j];
	}
}

void drawstmatr(){
	fi(0, m) fj(0, n) stmatr[i][j] = '.';
	int len = strlen(st);
	int x = 0;
	fi(0, len){
		x += shst[i];
		place(st[i], x, stmatr);
		x += k;
	}
#ifdef _DEBUG
	fi(0, m){
		printf("%s\n",stmatr[i]);
	}
#endif
}

int pref[N];

int getcol(int id){
	int res = 0;
	fi(0, m) res += (stmatr[i][id] == '*' ? 1 : 0);
	return res;
}

void buildpref(){
	fi(0, n){
		pref[i] = getcol(i);
		if(i) pref[i] += pref[i-1];
	}
}

int getcost(int id, int x){
	if(x + k - 1 >= n) return INF;
	int res = 0;
	fi(0, m) fj(0, k){
		if(l[id][i][j] != stmatr[i][x+j]) ++res;
	}
	return res;
}

int getpref(int x){
	if(x < 0) return 0;
	return pref[x];
}

int getsum(int l, int r){
	if(l > r) return 0;
	int res = pref[r];
	if(l > 0) res -= pref[l-1];
	return res;
}

int d[M][N];
int w[M][N];
int bestsh[M][N];
vector<int> answer;

int rec(int p, int x){
	if(x < 0) return INF;
	if(p == 0){
		if(w[p][x]) return d[p][x];
		w[p][x] = 1;
		d[p][x] = getcost(en[p], x) + getpref(x-1);
		bestsh[p][x] = x;
		return d[p][x];
	}
	
	if(w[p][x]) return d[p][x];
	w[p][x] = 1;
	int res = INF;
	int costplace = getcost(en[p], x);
	fi(smin, smax+1){
		int befx = x - i - k;
		int costbet = getsum(befx+k, x-1);
		int costbef = rec(p-1, befx);
		int nres = costbet + costbef + costplace;
		if(res > nres){
			res = nres;
			bestsh[p][x] = i;
		}
	}

	return d[p][x] = res;
}

void solve(){
	drawletters();
	drawstmatr();
	buildpref();
	int ans = INF;
	int ansx = -1;
	fi(0, n){
		int suf = getsum(i+k, n-1);
		int pans = rec(strlen(en)-1, i) + suf;
		if(ans > pans){
			ans = pans;
			ansx = i;
		}
	}
#ifdef _DEBUG
	printf("%d\n",ans);
#endif
	int p = strlen(en)-1;
	int x = ansx;
	while(p >= 0){
		answer.pb(bestsh[p][x]);
		int nx = x - bestsh[p][x] - k;
		x = nx;
		p = p - 1;
	}
	reverse(answer.begin(), answer.end());
#ifdef _DEBUG
	fi(0, m) fj(0, n) enmatr[i][j] = '.';
	int len = strlen(en);
	x = 0;
	fi(0, len){
		x += answer[i];
		place(en[i], x, enmatr);
		x += k;
	}
	fi(0, m){
		printf("%s\n",enmatr[i]);
	}
	int rans = 0;
	fi(0, m) fj(0, n) if(enmatr[i][j] != stmatr[i][j]) ++rans;
	printf("real answer: %d\n",rans);
#endif
}

#define FILENAME "caption"
int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
#endif

	read();
	solve();

	fi(0, sz(answer)){
		printf("%d ",answer[i]);
	}

	return 0;
}