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

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llu n;
	int len = 0;
	cin >> n;

	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}

	int i = 1349;
	while (i--) {
		if (n == 1) {
			len++;
			break;
		}

		if (n % 2 == 0) {
			len++;	
			n /= 2;
		}
		else {
			len++;
			n = 3*n + 1;
		}
	}


	cout << len << '\n';

    return 0;
}
