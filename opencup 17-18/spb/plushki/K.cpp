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

int MAXL = 28;

map<string, pair<char, int> > mapa[29];

map<string, string> ds[29];

vector<string> words;

char t[50];

void solve(){
	int n;
	scanf("%d", &n);
	fi(0, n) {
		scanf(" %s", &t);
		words.push_back(string(t));
	}
	int m;
	scanf("%d", &m);
	string emp = "";
	mapa[0][emp] = mp('.', 0);
	ds[0][emp] = ".";
    
	fi(0, m) {
		scanf(" %s", &t);
		string s(t);
		string s1 = s;
		sort(all(s1));
		ds[sz(s1)][s1] = s;
		mapa[sz(s1)][s1] = mp('.', sz(s1));
	}
	fi(0, MAXL) {
		for (auto it = mapa[i].begin(); it != mapa[i].end(); ++it) {
			string s = it -> first;
			int cnt = it-> second.second;
			for (char c = 'a'; c <= 'z'; ++c) {
				string s1 = s;
                s1.push_back(c);
				sort(all(s1));
				if (mapa[i + 1].find(s1) != mapa[i + 1].end()) {
					if (mapa[i + 1][s1].second > cnt) {
						mapa[i + 1][s1] = mp(c, cnt);
					}
				}
			}
		}
	}
	fi(0, n) {
		string word = words[i];
		string wso = word;
        sort(all(wso));
        printf("%d\n", sz(wso) - mapa[sz(wso)][wso].second + 1);
        printf("%s", word.c_str());
		while(mapa[sz(wso)][wso].first != '.') {
            string wso1;
            char c = mapa[sz(wso)][wso].first;
            bool wd = false;
			fj(0, sz(wso)) {
				if(c == wso[j] && !wd) {
				    wd = true;
				} else {
				    wso1.pb(wso[j]);
				}
			}
            wso = wso1;
            printf(" -> %s", ds[sz(wso)][wso].c_str());
		}
        printf("\n");
	}
}

#define FILENAME "word-chains"

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