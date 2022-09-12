#include <bits/stdc++.h>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359;

using namespace std;

// UTILITY (MIGHT NOT BE USED)
void printStr(const string& s) {
	for (int i = 0; i < s.size(); i++)
		cout << s[i];
	cout << '\n';
}

int rec(int x, int y, int z,  int n, map<vector<int>,map<int, int>>& visited) {
	vector<int> curr = {x,y,z};
	if (visited.count(curr) && visited[curr].count(n)) { // we know a solution for this node + step count already
		return visited[curr][n];
	}

	int m = max(abs(x), abs(y));
	m = max(m, abs(z));

	if (m > n)  {
		return 0;
	}

	if (n == 0 && x == 0 && y == 0 && z == 0) {
		return 1;
	} else if (n == 0) 
		return 0;

	visited[curr][n] += rec(x - 1, y, z + 1, n-1, visited) + rec(x, y-1, z+1, n-1, visited) + rec(x+1, y-1, z, n-1, visited) + rec(x+1, y, z-1, n-1, visited) + rec(x, y+1, z-1, n-1, visited) + rec(x-1, y+1, z, n-1, visited);

	return visited[curr][n];
}

int main () {
	int N;
	cin >> N;

	map<vector<int>, map<int, int>> visited;

	while (N--) {
		int n;
		cin >> n;

		int x = 0, y = 0, z = 0;

		cout << rec(x, y, z, n, visited) << '\n';
	}

    return 0;
}
