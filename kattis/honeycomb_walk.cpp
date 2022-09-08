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
	int n;

	cin >> n;

	while (n--) {
		int steps;
		cin >> steps;

		// I think this problem can be easily done w/ recursion, but I'm not confident i know how ot generate a hex matrix. When you go down a path in your recursion, you will keep track of 
		// how many steps you have remaining, and mark the current node that you traveled to with a value that represents the difference between your remaining steps and your max steps, which
		// is the distance from the root node to your current node. So, every time you arrive upon a node that has a value already in it, if your remaining steps are greater than or equal
		// to the node's value, continue. If curr steps remaining < curr node value, return. Keep in mind that you cannot return home unless ... i'm not sure


	}

    return 0;
}
