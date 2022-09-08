#include <bits/stdc++.h>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359;

using namespace std;

void printStr(string& s) {
	for (int i = 0; i < s.size(); i++)
		cout << s[i];
	cout << '\n';
}

// void rec(map<int, set<int>>& groups, int a, int b) {

	// groups[a].insert(b);
	// groups[b].insert(a);

	// for (auto it = groups[a].begin(); it != groups[a].end(); it++)
	// 	rec(groups, b, *it);

	
// }

int main () {
	int n, q;
	cin >> n >> q;

	map<int, set<int>> groups;

	for (int i = 1; i <= n; i++)
		groups[i].insert(i);

	while (q--) {
		char c;
		// set<int> seen;

		cin >> c;

		if (c == 't') {			// for (auto it = groups[a].begin(); it != groups[a].end(); it++) {
			int a, b;
			cin >> a >> b;

			// groups[a].insert(b);
			// groups[b].insert(a);

			// seen.insert(a);
			// seen.insert(b);

			for (auto it = groups[a].begin(); it != groups[a].end(); it++) {
				for (auto itj = groups[b].begin(); itj!=groups[b].end();itj++) {
					groups[*it].insert(*itj);
					groups[*itj].insert(*it);
				}
			}
			// rec(groups, a, b);

			// for (auto it = groups[a].begin(); it != groups[a].begin(); it++) {
			// 	groups[b].insert(*it);
			// }

			// for (auto it = groups[b].begin(); it != groups[b].begin(); it++) {
			// 	groups[a].insert(*it);
			// }
		} else {
			int a;
			cin >> a;

			cout << groups[a].size() << '\n';
		}
	}

    return 0;
}
