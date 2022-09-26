#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, count = 0, curr;
	stack<int> aux;
	cin >> n;
	n *= 2;

	for (int i = 0; i < n; i++) {
		cin >> curr;
		if (aux.empty() || aux.top() != curr) {
			aux.push(curr);
		} else {
			aux.pop();
		}
		count++;
	}

	if (aux.size())
		cout << "impossible\n";
	else
		cout << count << '\n';

	return 0;
}