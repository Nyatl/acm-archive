#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cassert>
#include<cstdio>
#include<cstdlib>

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


bool f;
vector<pii> a;
int n;


void solve(){
	sort(a.begin(), a.end());
	if (a[2].first == a[1].first + a[0].first) {
		printf("0");
		exit(0);
	}
	int r = a[1].first - a[0].first;
	int fh = (a[2].first + r) / 2;
	int sh = (a[2].first - r) / 2;
	printf("%d\n", a[2].second);
	printf("%d %d", fh, sh);
}


int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	fi(0, 3){
		int v;
		scanf("%d",&v);
		a.pb(mp(v, i + 1));
	}

	solve();

	return 0;
}