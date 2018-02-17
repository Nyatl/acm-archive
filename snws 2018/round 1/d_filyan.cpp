#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
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
typedef vector<int> vi;
typedef long double ld;
///////////////////////////

int const N = 1e5 + 41;

int a[3];
int ans[N];
int n;

void solve(){
	n = a[0] + a[1] + a[2];
	int q = 0;
	int p = 1;
	while(q < n){
		int mx = -1;
		int id = -1;
		fi(0, 3){
			if(a[i] > 0){
				if(mx < abs(p - i)){
					mx = abs(p - i);
					id = i;
				}else if(mx == abs(p - i) && a[id] < a[i]){
					mx = abs(p - i);
					id = i;
				}
			}
		}
		p = id;
		--a[p];
		ans[q++] = p;
	}
}

int main(){
//#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
//#endif

	fi(0, 3) scanf("%d",&a[i]);
	
	solve();

	fi(0, n) printf("%d ",ans[i]+1);

	return 0;
}