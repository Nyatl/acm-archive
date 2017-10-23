#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <tuple>
#include <map>
#include <ctime>
#include <memory>
#include <memory.h>
#include <iomanip>
#include <functional>
#include <cassert>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define sz(a) ((int)((a).size()))
#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fo(a, b) for(int o = (a); o < (b); ++o)
#define fdi(a, b) for(int i = (int)(a) - 1; i >= (b); --i)
#define fdo(a, b) for(int o = (int)(a) - 1; o >= (b); --o)
#define fdj(a, b) for(int j = (int)(a) - 1; i >= (b); --j)
#define all(a) (a).begin(),(a).end()
#define _(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////////////////////

struct problem {
	int att;
	int tim;
	bool ok;
	problem() {}
	problem(int att, int tim, bool ok) : att(att), tim(tim), ok(ok) {}
	problem getOk() {
		if (ok) {
			return *this;
		}
		return problem(att + 1, tim, true);
	}
	bool canAchieve(const problem & p) {
		if (ok == true && p.ok == true) {
			return (tim == p.tim && att == p.att);
		}
		if (ok == true && p.ok == false) {
			return false;
		}
		if (ok == false && p.ok == false) {
			if (tim == p.tim && att == p.att) {
				return true;
			}
			if (att < p.att) {
				if (tim < p.tim) {
					if (p.tim < 240) {
						return false;
					}
					return true;
				}
				return false;
			}
			return false;
		}
		if (ok == false && p.ok == true) {
			if (p.att <= att) {
				return false;
			}
			if (p.tim < 240) {
				return false;
			}
			return true;
		}
		return false;
	}
	int getAllTim() const {
		return tim + (att - 1) * 20;
	}
};

struct team {
	vector<problem> problems;
	string name;
	team() {}
	team(vector<problem> problems, string name) : problems(problems), name(name) {}
	bool canAchieve(const team & t) {
		assert(name == t.name);
		fi(0, sz(problems)) {
			if (!problems[i].canAchieve(t.problems[i])) {
				return false;
			}
		}
		return true;
	}
	team getAllOk() {
		team ret;
		ret.name = name;
		fi(0, sz(problems)) {
			ret.problems.push_back(problems[i].getOk());
		}
		return ret;
	}
	bool operator<(const team& a) const {
		int cntOk = 0;
		int allTim = 0;
		int lastTim = 0;
		int cntOkA = 0;
		int allTimA = 0;
		int lastTimA = 0;
		fi(0, sz(problems)) {
			cntOk += problems[i].ok;
			if (problems[i].ok) {
				allTim += problems[i].getAllTim();
				lastTim = max(lastTim, problems[i].tim);
			}
		}
		fi(0, sz(a.problems)) {
			cntOkA += a.problems[i].ok;
			if (a.problems[i].ok) {
				allTimA += a.problems[i].getAllTim();
				lastTimA = max(lastTimA, a.problems[i].tim);
			}
		}
		if (cntOk != cntOkA) {
			return cntOk > cntOkA;
		}
		if (allTim != allTimA) {
			return allTim < allTimA;
		}
		if (lastTim != lastTimA) {
			return lastTim < lastTimA;
		}
		return name < a.name;
	}
};

vector<team> teamsBefore, teamsAfter;

void bad() {
	printf("Fake");
	exit(0);
}

void solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	fi(0, m) {
		char buff[12];
		scanf(" %s", buff);
		vector<problem> problems;
		fi(0, n) {
			int att, tim;
			char ok;
			scanf(" %c%d%d", &ok, &att, &tim);
			problems.push_back(problem(att, tim, ok == '+'));
		}
		teamsBefore.push_back(team(problems, string(buff)));
	}
	fi(0, k) {
		char buff[12];
		scanf(" %s", buff);
		vector<problem> problems;
		fi(0, n) {
			int att, tim;
			char ok;
			scanf(" %c%d%d", &ok, &att, &tim);
			problems.push_back(problem(att, tim, ok == '+'));
		}
		teamsAfter.push_back(team(problems, string(buff)));
	}
	fi(0, k) {
		fj(0, m) {
			if (teamsBefore[j].name == teamsAfter[i].name) {
				if (!teamsBefore[j].canAchieve(teamsAfter[i])) {
					bad();
				}
				break;
			}
		}
	}
	fi(1, k) {
		if (teamsAfter[i] < teamsAfter[i - 1]) {
			bad();
		}
	}
	team fst = teamsAfter[0];
	team lst = teamsAfter.back();
	fi(0, m) {
		bool ou = true;
		fj(0, k) {
			if (teamsBefore[i].name == teamsAfter[j].name) {
				ou = false;
				break;
			}
		}
		if (ou) {
			bool ok = false;
			if ((lst < teamsBefore[i])) {
				ok = true;
			}
			if ((teamsBefore[i].getAllOk() < fst)) {
				ok = true;
			}
			if (!ok) {
				bad();
			}
		}
	}
	printf("Leaked");
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}