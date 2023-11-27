#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int N;
int ans;

int calc(int a, int b, int c, int d) {
	auto e = vi{ a,b,c,d };
	sort(e.begin(), e.end());

	if (e[0] == e[1] &&
		e[1] == e[2] &&
		e[2] == e[3]) {
		return 50000 + e[0] * 5000;
	}

	if ((e[0] == e[1] && e[1] == e[2]) ||
		(e[1] == e[2] && e[2] == e[3])) {
		return 10000 + e[1] * 1000;
	}

	if (e[0] == e[1] && e[2] == e[3]) {
		return 2000 + e[0] * 500 + e[2] * 500;
	}

	if (e[0] == e[1]) {
		return 1000 + e[0] * 100;
	}

	if (e[1] == e[2]) {
		return 1000 + e[1] * 100;
	}

	if (e[2] == e[3]) {
		return 1000 + e[2] * 100;
	}

	return e[3] * 100;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> N;
	ans = 0;
	while (0 < (N--)) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		ans = max(ans, calc(a, b, c, d));
	}

	cout << ans;

	return 0;
}