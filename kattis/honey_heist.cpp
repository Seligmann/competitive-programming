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

void bfs(vector<int>& steps, queue<int>& q, vector<bool>& visited, vector<int>& distance, int n, int b, vector<vector<int>>& adj) {
	bool found = false;

	while (!q.empty()) {

		int s = q.front();
		q.pop();

		if (steps[s] == 0) // cannot search further
			continue; 

		// cout << "adj nodes to " << s << ": ";
		// for (auto u: adj[s])
		// 	cout << u << ',';
		// cout << " | steps remaining: " << steps[s] << endl;

		// go through nodes in next layer
		for (auto u: adj[s]) {
			if (visited[u] || u == -1 || u == 0) 
				continue;

			steps[u] = steps[s] - 1;
			visited[u] = true;
			distance[u] = distance[s] + 1;


			if (u == b) {
				cout << n - steps[u] << '\n';
				found = true;
				break;
			}

			if (steps[u] > 0) 
				q.push(u);
		}
		if (found) 
			break;

	}

	if (!found) 
		cout << "No\n";
}

int main () {
	int r, n, a, b, x;
	int matrix[20][20][20] = {{{-1}}};
	map<vector<int>, int> posToId;
	queue<int> q;
	set<int> hardened;
	vector<vector<int>> adj(20*20*20); 

	cin >> r >> n >> a >> b >> x;

	while (x--) {
		int tmp;
		cin >> tmp;
		hardened.insert(tmp);
	}

	int xStart = 0, xLim = r, yStart = r - 1, yLim = 0, ID = 1, z = -(r - 1);
	int cells = pow(r,3) - pow(r-1, 3);
	vector<int> steps(cells, -1);
	vector<bool> visited(cells);
	vector<int> distance(cells);

	// create hex matrix 
	while (z != r) {
		for (int x = xStart, y = yStart; x < xLim, y >= yLim; x++, y--) {
			if (hardened.count(ID))
				matrix[x][y][z] = -1;
			else {
				matrix[x][y][z] = ID;
				posToId[{x,y,z}] = ID;
			}

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

	// create adj list
	for (auto it = posToId.begin(); it != posToId.end(); it++) {
		int x = it->first[0];
		int y = it->first[1];
		int z = it->first[2];

		if (posToId.count({x,y-1,z+1}) && posToId[{x,y-1,z+1}] != 0 && posToId[{x,y-1,z+1}] != -1)
			adj[it->second].push_back(posToId[{x,y-1,z+1}]);
		if (posToId.count({x,y+1,z-1}) && posToId[{x,y+1,z-1}] != 0 && posToId[{x,y+1,z-1}] != -1)
			adj[it->second].push_back(posToId[{x,y+1,z-1}]);

		if (posToId.count({x+1,y,z-1}) && posToId[{x+1,y,z-1}] != 0 && posToId[{x+1,y,z-1}] != -1)
			adj[it->second].push_back(posToId[{x+1,y,z-1}]);
		if (posToId.count({x-1,y,z+1}) && posToId[{x-1,y,z+1}] != 0 && posToId[{x-1,y,z+1}] != -1)
			adj[it->second].push_back(posToId[{x-1,y,z+1}]);

		if (posToId.count({x+1,y-1,z}) && posToId[{x+1,y-1,z}] != 0 && posToId[{x+1,y-1,z}] != -1)
			adj[it->second].push_back(posToId[{x+1,y-1,z}]);
		if (posToId.count({x-1,y+1,z}) && posToId[{x-1,y+1,z}] != 0 && posToId[{x-1,y+1,z}] != -1)
			adj[it->second].push_back(posToId[{x-1,y+1,z}]);
	}

	// bfs
	visited[a] = true;
	distance[a] = 0;
	q.push(a);
	steps[a] = n;

	bfs(steps, q, visited, distance, n, b, adj);
	// free(matrix);
}
