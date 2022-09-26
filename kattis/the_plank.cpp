#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

// UTILITY (MIGHT NOT BE USED)
void printStr(const string& s) {
	for (lu i = 0; i < s.size(); i++)
		cout << s[i];
	cout << '\n';
}

int dfs(int n, int sum) {
	if (sum == n)
		return 1;

	if (sum > n)
		return 0;

	return dfs(n, sum + 1) + dfs(n, sum + 2) + dfs(n, sum + 3);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cnt = 0, sum = 0;

	cin >> n;

	cnt += dfs(n, sum + 1) + dfs(n, sum + 2) + dfs(n, sum + 3);

	cout << cnt << '\n';

    return 0;
}
