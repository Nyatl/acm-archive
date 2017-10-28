#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <assert.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long ll;

#define FILENAME "abbreviation"

vector<string> s;

char t[500];

bool is_cap(string &s) {
	if (SIZE(s) <= 1) return false;
	if (!(s[0] >= 'A' && s[0] <= 'Z')) return false;
	fi(1, SIZE(s) - 1) {
		if (!(s[i] >= 'a' && s[i] <= 'z')) return false;
	}
	return true;
}

vector<string> w;
int state;

void print() {
	if (SIZE(w) <= 2) {
		fi(0, SIZE(w) - 1) {
			printf("%s", w[i].c_str());
		}
		w.clear();
		return;
	}
	fi(0, SIZE(w) - 1) {
		if (w[i] != " ") {
			printf("%c", w[i][0]);
		}
	}
	printf(" (");
	fi(0, SIZE(w) - 1) {
		printf("%s", w[i].c_str());
	}
	printf(")");
	w.clear();
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	while (!feof(stdin)) {
		if (scanf("%[a-zA-Z]", t) != 1) {
			scanf("%[^a-zA-Z]", t);
		}
		s.push_back(t);
	}

	fi(0, SIZE(s) - 1) {
		if (state == 0) {
			if (is_cap(s[i])) {
				w.pb(s[i]);
				state = 1;
			} else {
				printf("%s", s[i].c_str());
			}
		} else if (state == 1) {
			if (s[i] == " ") {
				w.pb(" ");
				state = 2;
			} else {
				print();
				printf("%s", s[i].c_str());
				state = 0;
			}
		} else if (state == 2) {
			if (is_cap(s[i])) {
				w.pb(s[i]);
				state = 1;
			} else {
				int f = 0;
				if (w[SIZE(w) - 1] == " ") {
					f = 1;
					w.pop_back();
				}
				print();
				if (f) {
					printf(" ");
				}
				printf("%s", s[i].c_str());
				state = 0;
			}
		}
	}

	if (SIZE(w) > 0) {
		int f = 0;
		if (w[SIZE(w) - 1] == " ") {
			f = 1;
			w.pop_back();
		}
		print();
		if (f) {
			printf(" ");
		}
	}

	return 0;
}
