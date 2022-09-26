#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std; 

void joeBfs(queue<vector<int>>& qFire, int& cnt, queue<vector<int>>& q, char m[][1000], int r, int c);

void fireBfs(queue<vector<int>>& qFire, int& cnt, queue<vector<int>>& q, char m[][1000], int r, int c) {
    if (qFire.empty())
        return;

    if (qFire.front()[0] == -1 && qFire.front()[1] == -1) {
        qFire.pop();

        if (qFire.empty() || qFire.front()[0] == -1) {
            return;
        }
    }

    while (qFire.front()[0] != -1 && qFire.front()[1] != -1) {
        int y = qFire.front()[0];
        int x = qFire.front()[1];
        m[y][x] = 'F';
        qFire.pop();

        if (x + 1 < c && (m[y][x + 1] == '.' || m[y][x + 1] == 'J')) {
            m[y][x + 1] = 'F';
            qFire.push({y, x + 1});
        }
        if (y + 1 < r && (m[y + 1][x] == '.' || m[y + 1][x] == 'J')) {
            m[y + 1][x] = 'F';
            qFire.push({y + 1, x});
        }
        if (x - 1 >= 0 && (m[y][x - 1] == '.' || m[y][x - 1] == 'J')) {
            m[y][x - 1] = 'F';
            qFire.push({y, x - 1});
        }
        if (y - 1 >= 0 && (m[y - 1][x] == '.' || m[y - 1][x] == 'J')) {
            m[y - 1][x] = 'F';
            qFire.push({y - 1, x});
        }
    }
    qFire.push({-1, -1});

    // joeBfs(qFire, cnt, q, m, r, c);
}

void joeBfs(queue<vector<int>>& qFire, int& cnt, queue<vector<int>>& q, char m[][1000], int r, int c) {
    while (!q.empty()) {
        if (q.front()[1] == -1 && q.front()[0] == -1) {
            q.pop();

            if (q.empty() || q.front()[1] == -1) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }

        while (q.front()[0] != -1) {

            int x = q.front()[1];
            int y = q.front()[0];
            m[y][x] = 'J';
            q.pop();

            if (x + 1 == c || y + 1 == r || x == 0 || y == 0) {
                cnt++;
                cout << cnt << '\n';
                return;
            }

            if (m[y][x + 1] == '.') {
                q.push({y, x + 1});
                m[y][x + 1] = 'J';
            }
            if (m[y + 1][x] == '.') {
                q.push({y + 1, x});
                m[y + 1][x] = 'J';
            }
            if (m[y][x - 1] == '.') {
                q.push({y, x - 1});
                m[y][x - 1] = 'J';
            }
            if (m[y - 1][x] == '.') {
                q.push({y - 1, x});
                m[y - 1][x] = 'J';
            }

        }
        q.push({-1, -1});
        cnt++;


        fireBfs(qFire, cnt, q, m, r, c);

    }
    // if (q.empty()) {
    //     cout << "IMPOSSIBLE\n";
    //     return;
    // }
    cout << "IMPOSSIBLE\n";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, cnt = 0;
    bool found = false;
    cin >> r >> c;

    char m[1000][1000] = {'~'};
    int f[2];
    int joe[2];
    queue<vector<int>> q;
    queue<vector<int>> qFire;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            m[i][j] = s[j];

            if (m[i][j] == 'J') {
                joe[0] = i;
                joe[1] = j;
            }
            if (m[i][j] == 'F') {
                qFire.push({i, j});
            }
        }
    }

    q.push({joe[0], joe[1]});
    q.push({-1, -1});
    // qFire.push({f[0], f[1]});
    qFire.push({-1, -1});
    fireBfs(qFire, cnt, q, m, r, c);
    joeBfs(qFire, cnt, q, m, r, c);
}