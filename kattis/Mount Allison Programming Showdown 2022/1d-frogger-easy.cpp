#include <bits/stdc++.h>

typedef long unsigned int lu; 
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(std::string vars, Args&&... values) {
    std::cout << vars << " = ";
    std::string delim = "";
    (..., (std::cout << delim << values, delim = ", "));
    std::cout << '\n';
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, s, m;
    cin >> n >> s >> m;

    vector<int> board(n + 1);

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        board[i] = tmp;
        // cout << board[i] << '\n';
    }

    int steps = 0;
    while (true) {
        if (s <= 0) {
            cout << "left\n";
            cout << steps << '\n';
            break;
        }

        if (s > n) {
            cout << "right\n";
            cout << steps << '\n';
            break;
        }

        if (board[s] == m) {
            cout << "magic\n";
            cout << steps << '\n';
            break;
        } 

        if (board[s] == INT_MAX) {
            cout << "cycle\n";
            cout << steps << '\n';
            break;
        }

        steps++;
        int prev = s;

        if (board[s] < 0) 
            s -= abs(board[s]);
        else 
            s += board[s];

        board[prev] = INT_MAX;
    }

}
