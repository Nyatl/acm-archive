#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cassert>
#include<ctime>
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
//////////////////////

int const INF = 1e9 + 41;
int const M = 1e8;
int const N = 5e5 + 41;
int const K = 26;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n, m, q;
vector<string> vs;
int qr[N], qc[N];
int ans[N];
bool tr;

typedef vector<int> vi;
typedef vector<vector<int> > vii;

vii dist[4][2];
vii vc[4][2];

vii ma;
vii emp;
string s;
int fx[N], fy[N], sx[N], sy[N];

void build(){

	fi(0, n) ma.pb(vector<int>(m));
	fi(0, n) emp.pb(vector<int>(m, INF));

	fi(0, n) fj(0, m){
		ma[i][j] = vs[i][j]-'a';
	}

	for(int d=0;d<4;++d){
		fi(0, 2){
			dist[d][i] = emp;
			vc[d][i] = emp;
		}
	}
}

bool check(int y, int x){
	return (y >= 0 && y < n && x >= 0 && x < m);
}

void remin(int &a, int b){
	a = min(a, b);
}

void buildtop(){
	int dir = 0;
	fj(0, m){
		fi(0, n){
			int x = j;
			int y = i;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(check(ny, nx)){
				int c = ma[ny][nx];
				fo(0, 2){
					if(dist[dir][o][y][x] > dist[dir][o][ny][nx] + 1){
						dist[dir][o][y][x] = dist[dir][o][ny][nx] + 1;
						vc[dir][o][y][x] = vc[dir][o][ny][nx];
					}
				}
				if(vc[dir][1][y][x] != c && vc[dir][0][y][x] != c){
					vc[dir][1][y][x] = c;
					dist[dir][1][y][x] = 1;
				}else{
					if(vc[dir][1][y][x] == c){
						dist[dir][1][y][x] = 1;
					}else{
						dist[dir][0][y][x] = 1;
					}
				}
				if(dist[dir][0][y][x] > dist[dir][1][y][x]){
					swap(dist[dir][0][y][x], dist[dir][1][y][x]);
					swap(vc[dir][0][y][x], vc[dir][1][y][x]);
				}
			}
		}
	}
}

void buildbot(){
	int dir = 2;
	fj(0, m){
		fdi(n, 0){
			int x = j;
			int y = i;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(check(ny, nx)){
				int c = ma[ny][nx];
				fo(0, 2){
					if(dist[dir][o][y][x] > dist[dir][o][ny][nx] + 1){
						dist[dir][o][y][x] = dist[dir][o][ny][nx] + 1;
						vc[dir][o][y][x] = vc[dir][o][ny][nx];
					}
				}
				if(vc[dir][1][y][x] != c && vc[dir][0][y][x] != c){
					vc[dir][1][y][x] = c;
					dist[dir][1][y][x] = 1;
				}else{
					if(vc[dir][1][y][x] == c){
						dist[dir][1][y][x] = 1;
					}else{
						dist[dir][0][y][x] = 1;
					}
				}
				if(dist[dir][0][y][x] > dist[dir][1][y][x]){
					swap(dist[dir][0][y][x], dist[dir][1][y][x]);
					swap(vc[dir][0][y][x], vc[dir][1][y][x]);
				}
			}
		}
	}
}

void buildlef(){
	int dir = 3;
	fi(0, n){
		fj(0, m){
			int x = j;
			int y = i;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(check(ny, nx)){
				int c = ma[ny][nx];
				fo(0, 2){
					if(dist[dir][o][y][x] > dist[dir][o][ny][nx] + 1){
						dist[dir][o][y][x] = dist[dir][o][ny][nx] + 1;
						vc[dir][o][y][x] = vc[dir][o][ny][nx];
					}
				}
				if(vc[dir][1][y][x] != c && vc[dir][0][y][x] != c){
					vc[dir][1][y][x] = c;
					dist[dir][1][y][x] = 1;
				}else{
					if(vc[dir][1][y][x] == c){
						dist[dir][1][y][x] = 1;
					}else{
						dist[dir][0][y][x] = 1;
					}
				}
				if(dist[dir][0][y][x] > dist[dir][1][y][x]){
					swap(dist[dir][0][y][x], dist[dir][1][y][x]);
					swap(vc[dir][0][y][x], vc[dir][1][y][x]);
				}
			}
		}
	}
}

void buildrig(){
	int dir = 1;
	fi(0, n){
		fdj(m, 0){
			int x = j;
			int y = i;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(check(ny, nx)){
				int c = ma[ny][nx];
				fo(0, 2){
					if(dist[dir][o][y][x] > dist[dir][o][ny][nx] + 1){
						dist[dir][o][y][x] = dist[dir][o][ny][nx] + 1;
						vc[dir][o][y][x] = vc[dir][o][ny][nx];
					}
				}
				if(vc[dir][1][y][x] != c && vc[dir][0][y][x] != c){
					vc[dir][1][y][x] = c;
					dist[dir][1][y][x] = 1;
				}else{
					if(vc[dir][1][y][x] == c){
						dist[dir][1][y][x] = 1;
					}else{
						dist[dir][0][y][x] = 1;
					}
				}
				if(dist[dir][0][y][x] > dist[dir][1][y][x]){
					swap(dist[dir][0][y][x], dist[dir][1][y][x]);
					swap(vc[dir][0][y][x], vc[dir][1][y][x]);
				}
			}
		}
	}
}

void precalc(){
	buildtop();
	buildbot();
	buildlef();
	buildrig();
}

int getx(int y, int x, int dir, int len){
	return x + dx[dir] * len;
}

int gety(int y, int x, int dir, int len){
	return y + dy[dir] * len;
}

void query(int r, int c, int id){
	int ret = ans[id];
	for(int c1=0;c1<2;++c1){
		for(int c2=0;c2<2;++c2){
			for(int d1=0;d1<4;++d1){
				for(int d2=0;d2<4;++d2){
					if(d1 == d2) continue;
					if((d1 ^ 2) == d2) continue;
					int vc1 = vc[d1][c1][r][c];
					int vc2 = vc[d2][c2][r][c];
					if(vc1 == vc2 || vc1 == INF || vc2 == INF) continue;
					int cur = dist[d1][c1][r][c] + dist[d2][c2][r][c];
					if(cur < ret){
						ret = cur;
						fx[id] = getx(r, c, d1, dist[d1][c1][r][c]);
						fy[id] = gety(r, c, d1, dist[d1][c1][r][c]);
						sx[id] = getx(r, c, d2, dist[d2][c2][r][c]);
						sy[id] = gety(r, c, d2, dist[d2][c2][r][c]);
					}
				}
			}
		}
	}
	ans[id] = ret;
}

void solve(){
	build();
#ifdef _DEBUG
	fi(0, n){
		fj(0, m){
			printf("%d",ma[i][j]);
		}
		printf("\n");
	}
#endif
	precalc();

	fi(0, q){
		ans[i] = M;
		query(qr[i], qc[i], i);
	}

	fi(0, q) if(ans[i] >= M) ans[i] = -1;
}

vector<string> tvs;

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	//unsigned int st = clock();
	scanf("%d %d",&n,&m);

	fi(0, n){
		cin >> s;
		tvs.pb(s);
	}
	if(n > m) swap(n, m), tr = true;
	if(tr){
		fi(0, n){
			string es;
			es.resize(m);
			vs.pb(es);
			fj(0, m){
				vs[i][j] = tvs[j][i];
			}
		}
	}else{
		vs = tvs;
	}

	scanf("%d",&q);
	fi(0, q){
		scanf("%d %d",&qr[i],&qc[i]);
		--qr[i];--qc[i];
		if(tr) swap(qr[i], qc[i]);
	}

	solve();

	fi(0, q){
		if(ans[i] == -1){
			printf("-1\n");
		}else{
			if(tr) swap(fy[i], fx[i]), swap(sy[i], sx[i]);
			printf("%d %d %d %d\n",fy[i] + 1,fx[i] + 1,sy[i] + 1,sx[i] + 1);
		}
	}

	//fo(0, 4){
	//	printf("dir = %d\n",o);
	//	fi(0, n){
	//		fj(0, m){
	//			printf("d1 = %d v1 = %d d2 = %d v2 = %d\n",dist[o][0][i][j],vc[o][0][i][j],dist[o][1][i][j],vc[o][1][i][j]);
	//		}
	//		printf("\n");
	//	}
	//}

	//unsigned int en = clock();
	//fprintf(stderr,"TIME = %.3lf\n",(en-st) * 1.0 / CLOCKS_PER_SEC);
	return 0;
}