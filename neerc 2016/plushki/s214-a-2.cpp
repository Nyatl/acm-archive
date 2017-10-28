#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<deque>
#include<algorithm>
#include<ctime>
#include<memory>
#include<memory.h>
#include<cassert>
using namespace std;

#define sz(a) int((a).size())

#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fk(a, b) for(int k = (a); k < (b); ++k)

#define all(a) (a).begin(),(a).end()
#define _(a, b) memset(a, b, sizeof(a))

vector<string> st;
int const N = 141;
char s[N], del[N];
string str;


bool isLow(char c){
	return (c >= 'a' && c <= 'z');
}

bool isCap(char c){
	return (c >= 'A' && c <= 'Z');
}

bool isCorrect(string &s){
	if (sz(s) < 2){
		return false;
	}
	if (!isCap(s[0])){
		return false;
	}
	fi(1, sz(s)){
		if (!isLow(s[i])){
			return false;
		}
	}
	return true;
}

string getS(vector<string> &vs){
	string ret = "";
	fi(0, sz(vs)){
		ret += vs[i][0];
		assert(isCap(vs[i][0]));
	}
	ret += " ";
	ret += "(";
	fi(0, sz(vs)){
		if (i != 0) {
			ret += " ";
		}
		ret += vs[i];
	}
	ret += ")";
	return ret;
}

void print(vector<string> &vs){
	string cur;
	if (sz(vs) == 0){
		return;
	}
	if (sz(vs) == 1){
		cur = vs[0];
	}
	else{
		cur = getS(vs);
	}
	cout << cur;
	vs.clear();
}

void clear(){
	s[0] = '\0';
	del[0] = '\0';
}

void read() {
	while (getline(cin, str)){
		int pos = 0;
		while (sz(str) > pos){
			clear();
			sscanf(str.substr(pos).c_str(), "%[a-zA-Z]", s);
			pos += (strlen(s));
			sscanf(str.substr(pos).c_str(), "%[^a-zA-Z]", del);
			pos += (strlen(del));
			if (!isCorrect(string(s))){
				if (sz(st) > 0) {
					print(st);
					cout << " ";
				}
				else {
					print(st);
				}
				cout << string(s);
				cout << string(del);
			}
			else if (string(del) != string(" ")){
				st.push_back(s);
				print(st);
				cout << string(del);
			}
			else{
				st.push_back(s);
			}
		}
		print(st);
		cout << endl;
	}
}

void solve() {

}

#define FILENAME "abbreviation"

void prepare() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
}

int main() {
	prepare();
	read();
	solve();
	return 0;
}