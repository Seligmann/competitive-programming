#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

void dfs(int val, int y, int x, int r, int c, int m[][1000], vector<set<vector<int>>>& ones, vector<set<vector<int>>>& zeros) {
    if (m[y][x] == -1 || y >= r || x >= c || y < 0 || x < 0) {
        return;
    }

    if (m[y][x] != val)
        return;

    m[y][x] = -1;

    if (val == 1)
        ones[ones.size() - 1].insert({x, y});
    else
        zeros[zeros.size() - 1].insert({x, y});

    dfs(val, y - 1, x, r, c, m, ones, zeros);
    dfs(val, y, x + 1, r, c, m, ones, zeros);
    dfs(val, y + 1, x, r, c, m, ones, zeros);
    dfs(val, y, x - 1, r, c, m, ones, zeros);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    int m[1000][1000];
    int mcpy[1000][1000];
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            m[i][j] = s[j] - '0';
            mcpy[i][j] = s[j] - '0';
        }
    }


    vector<set<vector<int>>> ones;
    vector<set<vector<int>>> zeros;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] == -1) continue;

            set<vector<int>> tmp;
            if (m[i][j] == 1)
                ones.push_back(tmp);
            else
                zeros.push_back(tmp);

            dfs(m[i][j], i, j, r, c, m, ones, zeros);

        }
    }

    int n;
    cin >> n;

    while (n--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;

        if (mcpy[r1][c1] != mcpy[r2][c2]) {
            cout << "neither\n";
        } else if (mcpy[r1][c1] == 1) {
            bool found = false;
            for (int i = 0; i < ones.size(); i++) {
                if (ones[i].count({c1, r1}) && ones[i].count({c2, r2})) {
                    cout << "decimal\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "neither\n";

        } else if (mcpy[r1][c1] == 0) {
            bool found = false;
            for (int i = 0; i < zeros.size(); i++) {
                if (zeros[i].count({c1, r1}) && zeros[i].count({c2, r2})) {
                    found = true;
                    cout << "binary\n";
                    break;
                }
            }
            if (!found)
                cout << "neither\n";
        }
    }
}