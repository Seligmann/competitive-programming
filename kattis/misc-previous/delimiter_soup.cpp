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

	int l, retInt = -1;
	char retChar;
	string s;
	set<char> open = {'[','{','('};
	stack<char> stk;

	cin >> l;
	cin.ignore();
	getline(cin, s);


	int retI = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;

		if (open.count(s[i])) {
			stk.push(s[i]);
		}
		else {
			if (stk.empty()){
				retInt = i;
				retChar = s[i];
				break;
			} else if ((s[i] == ']' && stk.top() != '[') || (s[i] == '}' && stk.top() != '{') || (s[i] == ')' && stk.top() != '(')) {
				retInt = i;
				retChar = s[i];
				break;
			} else {
				stk.pop();
			}
		}

		retI++;
	}

	if (retInt == -1)
		cout << "ok so far\n";
	else
		cout << retChar << ' ' << retInt << '\n';


    return 0;
}
