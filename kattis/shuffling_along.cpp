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

	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}


	char c = 'A';
	for (int i = 0; i < n; i++) {
		c = (char) (c + i);
		curr.push_back(c);
	}

	start = curr;

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

			} while (curr.compare(start) != 0); // O(logn)?
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
			} while (curr.compare(start) != 0);
		}
	} else {
		if (s == "out") {
			do {
				string l = curr.substr(0, n/2 + 1);
				string r = curr.substr(n/2 + 1, n);
				curr.clear();

				for (int i = 0; i < n/2; i++) {
					curr.push_back(l[i]);
					curr.push_back(r[i]);
				}
				curr.push_back(l[l.size() - 1]);

				count++;
			} while (curr.compare(start) != 0);
		} else {
			do {
				string l = curr.substr(0, n/2);
				string r = curr.substr(n/2, n);
				curr.clear();

				for (int i = 0; i < n/2; i++) {
					curr.push_back(r[i]);
					curr.push_back(l[i]);
				}
				curr.push_back(r[r.size() - 1]);

				count++;
			} while (curr.compare(start) != 0);
		}
	}

	cout << count << '\n';

    return 0;
}
