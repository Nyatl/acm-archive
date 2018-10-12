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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <memory.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi(a, b) for(int i=a; i<b; i++)
#define fj(a, b) for(int j=a; j<b; j++)
#define fo(a, b) for(int o=a; o<b; o++)
#define fdi(a, b) for(int i=a-1; i>=b; i--)
#define fdj(a, b) for(int j=a-1; j>=b; j--)
#define fdo(a, b) for(int o=a-1; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()

typedef long long ll;

char __buffer[100000];

int err_limit = 1000;

void err(const char *format, ... ) {
	if (err_limit-- <= 0) return;	
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "%s", __buffer);
}

class { 
public: 
}; 
