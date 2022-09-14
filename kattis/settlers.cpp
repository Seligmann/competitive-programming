#include <bits/stdc++.h>

using namespace std;

int main () {
	map<int,int> ans;
	int c, mx = INT_MIN;
	set<int> tiles;

	cin >> c;

	while (c--) {
		int n;

		cin >> n;
		mx = max(mx, n);

		tiles.insert(n);
	}

	// Get length of hex matrix
	int r = 1;
	while (pow(r,3) - pow(r-1, 3) < mx)
		r++;

	int m[r * 2][r * 2][r * 2] = {{{0}}};
	map<vector<int>, vector<int>> adj; 
	vector<int> resCounts(6);
	map<vector<int>, int> xyzToRes;
	int x = r - 1, y = r - 1, z = r - 1, pos = 1;
	auto compare = [](const vector<int>& v1, const vector<int>& v2) {return v1[1] > v2[1];};

	// init first 3 nodes
	m[x][y][z] = 1;
	xyzToRes[{x,y,z}] = 1;
	resCounts[1]++;
	ans[1] = 1;
	x++;
	z--;
	pos++;

	m[x][y][z] = 2;
	xyzToRes[{x,y,z}] = 2;
	resCounts[2]++;
	ans[2] = 2;
	x--;
	y++;
	pos++;

	m[x][y][z] = 3;
	xyzToRes[{x,y,z,}] = 3;
	resCounts[3]++;
	ans[3] = 3;
	x--;
	z++;
	pos++;

	while (pos <= mx) {
		vector<int> resAvail = {1,2,3,4,5};
		priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> sortedRes(compare);

		// update adj list and then check surrounding resources used
		if (xyzToRes.count({x + 1, y, z - 1})) adj[{x,y,z}].push_back(xyzToRes[{x + 1, y, z - 1}]);
		if (xyzToRes.count({x - 1, y, z + 1})) adj[{x,y,z}].push_back(xyzToRes[{x - 1, y, z + 1}]);
		if (xyzToRes.count({x, y + 1, z - 1})) adj[{x,y,z}].push_back(xyzToRes[{x, y + 1, z - 1}]);
		if (xyzToRes.count({x, y - 1, z + 1})) adj[{x,y,z}].push_back(xyzToRes[{x, y - 1, z + 1}]);
		if (xyzToRes.count({x - 1, y + 1, z})) adj[{x,y,z}].push_back(xyzToRes[{x - 1, y + 1, z}]);
		if (xyzToRes.count({x + 1, y - 1, z})) adj[{x,y,z}].push_back(xyzToRes[{x + 1, y - 1, z}]);

		for (auto res: adj[{x,y,z}]) {
			auto it = find(resAvail.begin(), resAvail.end(), res);
			if (it != resAvail.end())
				resAvail.erase(it);
		}

		int res;

		// multiple tiles possible based on surrounding tiles
		if (resAvail.size() > 1) {
			// sort resources and their freqs
			for (int i = 1; i < resCounts.size(); i++) {
				if (find(resAvail.begin(), resAvail.end(), i) == resAvail.end()) 
					continue;	

				sortedRes.push({i, resCounts[i]});
			}

			// check if there are multiple choices based on freq
			res = sortedRes.top()[0];
			int freq = sortedRes.top()[1];
			sortedRes.pop();

			while (!sortedRes.empty() && freq == sortedRes.top()[1]) {
				res = min(res, sortedRes.top()[0]);
				sortedRes.pop();
			}
		} else if (resAvail.size() == 1) {
			res = resAvail[0];
		} else {
			break;
		}

		m[x][y][z] = res;
		xyzToRes[{x,y,z}] = res;
		resCounts[res]++;
		ans[pos] = res;

		// cout << x << ',' << y << ',' << z

		if (x < r * 2 && z > 0 && (m[x + 1][y][z - 1] == 0 && m[x][y + 1][z - 1] > 0 && m[x - 1][y + 1][z] > 0)) {
			// up right
			x++;
			z--;
		} else if (y < r * 2 - 1 && z > 0 && m[x][y + 1][z - 1] == 0 && m[x - 1][y + 1][z] > 0 && m[x - 1][y][z + 1] > 0) {
			y++;
			z--;
		} else if (x > 0 && y < r * 2 - 1 && m[x - 1][y + 1][z] == 0 && m[x - 1][y][z + 1] > 0 && m[x][y - 1][z + 1] > 0) {
			x--;
			y++;
		} else if (x < r * 2 - 1 && y > 0 && m[x + 1][y - 1][z] == 0 && m[x + 1][y][z - 1] > 0 && m[x][y + 1][z - 1] > 0) {
			x++;
			y--;
		} else if (x > 0 && z < r * 2 - 1 && m[x - 1][y][z + 1] == 0 && m[x + 1][y - 1][z] > 0 && m[x][y - 1][z + 1] > 0) {
			x--;
			z++;
		} else if (y > 0 && z < r * 2 - 1 && m[x][y - 1][z + 1] == 0 && m[x + 1][y][z - 1] > 0 && m[x + 1][y - 1][z] > 0) {
			y--;
			z++;
		} else {
			break;
		}


		pos++;
	}

	for (auto it = tiles.begin(); it != tiles.end(); it++) {
		cout << ans[*it] << '\n';
	}

	return 0;
}