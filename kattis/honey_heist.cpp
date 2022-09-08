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

struct Node {

}

int main () {
	int N, D;

	cin >> N >> D;

	int pa = D / 8;
	int pb = 1 - pa;
	vector<int> intv = {0, 1};

	while (N--) {

	}

	// I think this problem is a min path finding problem with two exceptions: 
	// 1) the length of the min path must be <= number of moves available to the ant
	// 2) there are nodes in the graph that you cannot travel to
	//  - The way that you take care of this is by pre-generating the matrix, and if the current ID == ID of a hardened cell, do not add that part to the tree


    return 0;
}
