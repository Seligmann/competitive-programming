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

map<int, unordered_set<int>> adj;
map<int, int> visited;
map<int, unordered_set<int>> seen;

void buildAdj(int og, int n, int curr, vector<int> board) {
    // cout << curr << '\n';
    if (curr < 1 || curr > n || visited[curr] == 1) 
        return;

    visited[curr] = 1;

    if (board[curr] > 0 && board[curr] + curr <= n) {
        if (visited[board[curr] + 1] == 1)
            return;

        // cout << "inserting " << board[curr] + curr << '\n';
        adj[og].insert(board[curr] + curr);
        // adj[curr].insert(board[curr] + curr);
        
        buildAdj(og, n, board[curr] + curr, board);
    }

    if (board[curr] < 0 && curr - abs(board[curr]) >= 1) {
        if (visited[curr - abs(board[curr])] == 1)
            return;

        adj[curr].insert(curr - abs(board[curr]));
        buildAdj(og, n, curr - abs(board[curr]), board);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> board;
    int n;
    cin >> n;

    board.push_back(0);

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        board.push_back(tmp);
    }

    for (int i = 1; i <= n; i++) {
        buildAdj(i, n, i, board);
        visited.clear();
    }

    int cnt = 0;

    cnt += n - adj.size();

    for (auto it = adj.begin(); it != adj.end(); it++) {
        cnt++;
        if (it->first > 0) {
            cnt += it->second.size();
        } else {
            cnt += it->second.size();
            for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
                cnt += adj[*jt].size();
            }

        }
    }

    cout << cnt << '\n';
}
