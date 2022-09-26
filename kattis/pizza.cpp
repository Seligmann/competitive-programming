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
	cout << std::fixed;
	cout << std::setprecision(6);
	double r, c;

	cin >> r >> c;

	cout << 100.0 * (PI*pow(r - c, 2.0)) / (PI*pow(r , 2.0)) << '\n';

    return 0;
}
