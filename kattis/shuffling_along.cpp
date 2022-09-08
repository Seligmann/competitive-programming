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

int main () {
	int n, count = 0;
	string s, curr, start;

	cin >> n >> s;

	if (n == 1)
		return 0;

	char c = 'a';
	for (int i = 0; i < n; i++) {
		curr.push_back(c);
		c = (char) (c + 1);
	}

	start = curr;

	// even && out -> just iter over each string and interleaf them
	// odd && out -> first half will have one more card than 2nd half
	// even && in -> just iter over each string and interleaf them
	// odd && in -> second half will have onemore card than 1st half

	if (n % 2 == 0) {
		if (s == "out") {
			do {
				string l = curr.substr(0, n / 2);
				string r = curr.substr(n / 2, n);
				curr.clear();

				for (int i = 0; i < n/2; i++) {
					curr.push_back(l[i]);
					curr.push_back(r[i]);
				}

				count++;

				// printStr(curr);
			} while (start != curr); // O(logn)?
		} else {
			do {
				string l = curr.substr(0, n / 2);
				string r = curr.substr(n / 2, n);
				curr.clear();

				for (int i = 0; i < n/2; i++) {
					curr.push_back(r[i]);
					curr.push_back(l[i]);
				}

				count++;
			} while (start != curr);
		}
	} else {
		if (s == "out") {
			do {
				string l = curr.substr(0, n/2 + 1);
				string r = curr.substr(n/2 + 1, n);
				curr.clear();

				// 0 0 0 0 0

				for (int i = 0; i < n/2; i++) {
					curr.push_back(l[i]);
					curr.push_back(r[i]);
				}
				curr.push_back(l[n/2]);

				count++;
			} while (start != curr);
		} else {
			do {
				string l = curr.substr(0, n/2);
				string r = curr.substr(n/2, n);
				curr.clear();

				for (int i = 0; i < n/2; i++) {
					curr.push_back(r[i]);
					curr.push_back(l[i]);
				}
				curr.push_back(r[n/2]);

				count++;
			} while (start != curr);
		}
	}

	cout << count << '\n';

    return 0;
}
