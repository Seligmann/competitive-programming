#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    stack<int> cards;
    int n;

    cin >> n;

    while (n--) {
        int curr;
        cin >> curr;

        if (!cards.empty() && ((cards.top() + curr) % 2 == 0)) {
            cards.pop(); 
        } else {
            cards.push(curr);
        }
    }

    cout << cards.size() << '\n';

	return 0;
}