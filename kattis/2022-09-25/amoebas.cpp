#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

void dfs(int mat[][100], int m, int n, int i, int j, set<vector<int>>& visited) { // FIXME: idk if int** mat is right
    // cout << "in dfs: " << i << ' ' << j << ' ' << mat[i][j] << ' ';
    if (i < 0 || j < 0 || i >= m || j >= n || mat[i][j] == 0) {
        // cout << "out of bounds or mat[i][j] == 0\n";
        return;
    }

    if (visited.count({i, j}) || mat[i][j] == -1) {
        // cout << "looped\n";
        return;
    }

    int adj = 0;
    if (i - 1 >= 0 && mat[i - 1][j] != 0)
        adj++;
    if (i - 1 >= 0 && j + 1 < n && mat[i - 1][j + 1] != 0)
        adj++;
    if (j + 1 < n && mat[i][j + 1] != 0)
        adj++;
    if (i + 1 < m && j + 1 < n && mat[i + 1][j + 1] != 0)
        adj++;
    if (i + 1 < m && mat[i + 1][j] != 0)
        adj++;
    if (i + 1 < m && j - 1 >= 0 && mat[i + 1][j - 1] != 0)
        adj++;
    if (j - 1 >= 0 && mat[i][j - 1] != 0)
        adj++;
    if (i - 1 >= 0 && j - 1 >= 0 && mat[i - 1][j - 1] != 0)
        adj++;

    // cout << "adj count: " << adj << ' ';

    if (adj < 2) {
        // cout << "adj cout < 2\n";
        return;
    }

    visited.insert({i, j});
    mat[i][j] = -1;

    // cout << '\n';

    if (i - 1 >= 0 && mat[i - 1][j] == 1)
        dfs(mat, m, n, i - 1, j, visited);
    if (i - 1 >= 0 && j + 1 < n && mat[i - 1][j + 1] == 1)
        dfs(mat, m, n, i - 1, j + 1, visited);
    if (j + 1 < n && mat[i][j + 1] == 1)
        dfs(mat, m, n, i, j + 1, visited);
    if (i + 1 < m && j + 1 < n && mat[i + 1][j + 1] == 1)
        dfs(mat, m, n, i + 1, j + 1, visited);
    if (i + 1 < m && mat[i + 1][j] == 1)
        dfs(mat, m, n, i + 1, j, visited);
    if (i + 1 < m && j - 1 >= 0 && mat[i + 1][j - 1] == 1)
        dfs(mat, m, n, i + 1, j - 1, visited);
    if (j - 1 >= 0 && mat[i][j - 1] == 1)
        dfs(mat, m, n, i, j - 1, visited);
    if (i - 1 >= 0 && j - 1 >= 0 && mat[i - 1][j - 1] == 1)
        dfs(mat, m, n, i -1, j - 1, visited);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, cnt = 0;
    int mat[100][100] = {0};

    cin >> m >> n;

    // pre-process input to make matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if (c == '#')
                mat[i][j] = 1;
        }
    }

    // iter through matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1) continue;
            // cout << i << ' ' << j << ": " << mat[i][j] << '\n';

            if (mat[i][j] == 1) {
                // cout << i << ' ' << j << '\n';
                set<vector<int>> visited;
                dfs(mat, m, n, i, j, visited);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

}