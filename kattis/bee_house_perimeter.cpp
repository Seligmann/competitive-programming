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

void bfs(map<int, vector<int>>& idToXyz,set<vector<int>>& targetIdXyz, int r, set<int>& targetIds, int& count, queue<int>& q, set<int>& visited, vector<vector<int>>& adj) {
	while (!q.empty()) {
		// while (targetIdXyz.count(q.front()))
		// 	q.pop();

		int s = q.front();
		q.pop();

		// cout << "root " << s << " with adj: ";
		// for (auto u: adj[s])
		// 	cout << u << ',';
		// cout << '\n';

		// go through targetIds in next layer
		for (auto u: adj[s]) {
			if (targetIds.count(u)) { 
				// cout << "counted u: " << u << '\n';;
				count++;
			}

			if (visited.count(u)) 
				continue;

		
			if (!targetIds.count(u)) {
				visited.insert(u);
				q.push(u);
			}
		}

	}

}

int main () {
	int r, k, count = 0, start = INT_MAX;
	cin >> r >> k;
	set<int> visited;
	set<int> targetIds;
	set<vector<int>> targetIdXyz;
	map<int, vector<int>> idToXyz;

	while (k--) {
		int tmp;
		cin >> tmp;
		targetIds.insert(tmp);
		start = min(start, tmp);
	}

	int matrix[r + 1][r + 1][r + 1] = {{{0}}};
	map<vector<int>, int> posToId;
	vector<vector<int>> adj(pow(r + 1, 3)); 


	// iterate through smaller matrix to get positions of cells
	int xStart = 0, xLim = r, yStart = r - 1, yLim = 0, ID = 1, z = -(r - 1);

	while (z != r) {
		for (int x = xStart, y = yStart; x < xLim && y >= yLim; x++, y--) {
			// matrix[x][y][z] = ID;
			// posToId[{x,y,z}] = ID;
			cout << x << ',' << y << ',' << z << " | ID: " << ID << '\n';

			if (targetIds.count(ID))
				targetIdXyz.insert({x, y, z});

			ID++;
		}
		// cout << '\n';

		if (z < 0) {
			yLim--;
			xStart--;
		} else {
			yStart--;
			xLim--;
		}

		z++;
	}

	// for (auto it = targetIdXyz.begin(); it != targetIdXyz.end(); it++) {
	// 	for (auto x : *it)
	// 		cout << x << ',';
	// 	cout << '\n';
	// }

	// make actual matrix with r + 1 size
	xStart = 0, xLim = r + 1, yStart = r, yLim = 0, ID = 1, z = -r;
	while (z != r + 1) {
		for (int x = xStart, y = yStart; x < xLim && y >= yLim; x++, y--) {
			matrix[x][y][z] = ID;
			posToId[{x,y,z}] = ID;

			// if (targetIds.count(ID))
			// 	idToXyz[ID] = {x,y,z};

			// cout << " ( " << x << ',' << y << ',' << z << " ID: " << ID <<  ") ";

			// cout << ID << ' ';

			ID++;
		}
		// cout << '\n';

		if (z < 0) {
			yLim--;
			xStart--;
		} else {
			yStart--;
			xLim--;
		}

		z++;
	}

	targetIds.clear();
	// cout << "target positions: ";
	for (auto it = targetIdXyz.begin(); it != targetIdXyz.end(); it++) {
		// cout << posToId[*it] << ',';
		targetIds.insert(posToId[*it]);
	}
	cout << '\n';

	// create adj list
	for (auto it = posToId.begin(); it != posToId.end(); it++) {
		int x = it->first[0];
		int y = it->first[1];
		int z = it->first[2];

		if (posToId.count({x,y-1,z+1}))
			adj[it->second].push_back(posToId[{x,y-1,z+1}]);
		if (posToId.count({x,y+1,z-1}))
			adj[it->second].push_back(posToId[{x,y+1,z-1}]);

		if (posToId.count({x+1,y,z-1}))
			adj[it->second].push_back(posToId[{x+1,y,z-1}]);
		if (posToId.count({x-1,y,z+1}))
			adj[it->second].push_back(posToId[{x-1,y,z+1}]);

		if (posToId.count({x+1,y-1,z}))
			adj[it->second].push_back(posToId[{x+1,y-1,z}]);
		if (posToId.count({x-1,y+1,z}))
			adj[it->second].push_back(posToId[{x-1,y+1,z}]);


	}

	// bfs
	queue<int> q;
	visited.insert(1);
	q.push(1);
	bfs(idToXyz, targetIdXyz, r, targetIds, count, q, visited, adj);	
	cout << count << '\n';
}
