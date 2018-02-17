#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<deque>
#include<functional>
#include<ctime>
#include<cassert>
#include<cstring>
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
typedef double ld;
typedef vector<int> vi;

template<class T> bool uin(T &a, T b){ return (a > b ? a = b, true : false); }
template<class T> bool uax(T &a, T b){ return (a < b ? a = b, true : false); }

/////////////////////////////////
int const N = 1e3 + 41;

char ans[N][N];
int n;

void solve(){
	int t;
	fi(0, n){
		if(n - i * 2 <= 0) break;
		t = i;
		fj(0, i){
			ans[i][j] = '.';
		}
		fj(0, n - i * 2){
			ans[i][j+i] = 'S';
		}
	}
	fdi(t+1, 0){
		printf("%s\n",ans[i]);
	}
}

int main(){
#ifdef LOCAL_DEFINE
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	scanf("%d",&n);
	solve();		

	
#ifdef LOCAL_DEFINE
	fprintf(stderr, "ELAPSED TIME: %.3lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}