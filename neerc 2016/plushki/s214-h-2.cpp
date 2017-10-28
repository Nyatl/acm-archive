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

using namespace std;

#define sz(a) int((a).size())

#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fk(a, b) for(int k = (a); k < (b); ++k)

#define all(a) (a).begin(),(a).end()
#define _(a, b) memset(a, b, sizeof(a))

int const N = 1e5 + 41;
int const SHIFT = (1 << 15);
int const MAXVAL = (1 << 15) - 1 + SHIFT;

int cnt[N];
char s[N];
int getVal(int v){
	return v - SHIFT;
}
int readValue(){
	int val;
	scanf(" = %d ", &val);
	return val + SHIFT;
}

bool readX(){
	return(scanf(" %[x] ", &s) == 1);
}

bool readAnd(){
	return (scanf(" %[&] ", &s) == 1);
}

void push(pair<int, int> p){
	fi(p.first, p.second + 1){
		++cnt[i];
	}
}

bool readRange(){
	pair<int, int> ret = make_pair(0, MAXVAL);
	char type = getchar();
	int val = readValue();
	if (type == '>'){
		ret.first = val;
	}
	else{
		ret.second = val;
	}
	if (readAnd()){
		readX();
		type = getchar();
		val = readValue();
		if (type == '>'){
			ret.first = val;
		}
		else{
			ret.second = val;
		}
	}
	//printf("%d %d\n", getVal(ret.first), getVal(ret.second));
	push(ret);
	return (scanf(" %[|] ", &s) > 0);
}

void read() {
	while (readX()){
		if (!readRange()){
			break;
		}
	}
}

bool flag1;

void print(pair<int, int> p){
	bool flag = false;
	if (flag1) {
		printf(" ||\n");
	}
	if (p.first != 0){
		printf("x >= %d", getVal(p.first));
		flag = true;
	}
	if (p.second != MAXVAL){
		if (flag){
			printf(" && ");
		}
		printf("x <= %d", getVal(p.second));
	}
	flag1 = true;
}

void solve() {
	int curCnt = 0;
	int lastL = 0, lastR = MAXVAL;
	fi(0, MAXVAL){
		if (cnt[i] > 0){
			++curCnt;
		}
	}
	if (curCnt == 0){
		printf("false\n");
		exit(0);
	}
	if (curCnt == MAXVAL){
		printf("true\n");
		exit(0);
	}
	int pos = 0;
	int le = MAXVAL, ri = 0;
	while (pos <= MAXVAL){
		if (cnt[pos] > 0){
			le = min(le, pos);
			ri = max(ri, pos);
			if (cnt[pos + 1] == 0) {
				print(make_pair(le, ri));
				le = MAXVAL;
				ri = 0;
			}
		}
		++pos;
	}

}

#define FILENAME "hard"

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