#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

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

#define all(a) a.begin(),a.end()
///////////////////

const int N = 1000005;

int c[N];

void solve(){
	string a, b;
    string ans;
    cin >> a;
    cin >> b;
    reverse(all(a));
    reverse(all(b));
	fi(0, sz(a)) {
	    c[i] += (a[i] - '0');
	}
    fi(0, sz(b)) {
	    c[i] += (b[i] - '0');
	}
	fi(0, N - 20) {
		
		int d = c[i] / 2;
        int e = min(min(d, c[i + 1] / 2), c[i + 2]);
		c[i] -= 2 * e;
		c[i + 1] -= 2 * e;
		c[i + 2] -= e;
		d = c[i] / 2;
		c[i] -= d * 2;
        c[i + 2] += d;
        c[i + 3] += d;
	}
	fi(0, N - 10) {
	    ans.push_back(c[i] + '0');
	}
	while(sz(ans) > 1 && ans.back() == '0') {
	    ans.pop_back();
	}
    reverse(all(ans));
    cout << ans;
}

#define FILENAME "base-i-1"

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);
#endif

	solve();


	return 0;
}