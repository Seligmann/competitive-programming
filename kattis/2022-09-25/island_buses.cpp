#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(std::string vars, Args&&... values) {
    std::cout << vars << " = ";
    std::string delim = "";
    (..., (std::cout << delim << values, delim = ", "));
    std::cout << '\n';
}

using namespace std;


void floodFill(char ch, int i, int j, char m[][80], int r, int c, set<pair<int,int>>& v) {
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        pair<int,int> p = make_pair(i,j);
        q.pop();

        if (v.count(p))
            continue;
        v.insert(p);

        deb(ch, i, j, m[i][j]);

        if (i - 1 >= 0 && m[i - 1][j] == ch) q.push(make_pair(i - 1, j));
        if (j + 1 < c && m[i][j + 1] == ch) q.push(make_pair(i, j + 1));
        if (i + 1 < r && m[i + 1][j] == ch) q.push(make_pair(i + 1, j));
        if (j - 1 >= 0 && m[i][j - 1] == ch) q.push(make_pair(i, j - 1));
    }
}

vector<int> bfs(int i, int j, char m[][80], int r, int c, set<pair<int,int>>& v) {
    vector<int> ret(2); // islands and bridges
    queue<pair<int,int>> q;
    set<pair<int,int>> islands;
    set<pair<int,int>> bridges;
    q.push(make_pair(i,j));

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        pair<int,int> p = q.front();
        q.pop();

        if (v.count(p) || i < 0 || j < 0 || i == r || j == c) 
            continue;
        v.insert(p);

        if (m[i][j] == '.')
            continue;

        if (m[i][j] == 'B') {
            if (bridges.count(p) == 0) {
                ret[1]++;
                floodFill(m[i][j], i, j, m, r, c, bridges);
            }
        } else if (m[i][j] == '#') {
            if (islands.count(p) == 0) {
                ret[0]++;
                floodFill(m[i][j], i, j, m, r, c, islands);
            }
        } else if (m[i][j] == 'X') {
            bool isolated = true;
            
            if (islands.count(p) == 0) {
                if (i - 1 >= 0 && (m[i - 1][j] == 'B' || m[i - 1][j] == '#')) {
                    q.push(make_pair(i - 1, j));
                    if (m[i - 1][j] == '#') isolated = false;
                }
                if (j + 1 < c && (m[i][j + 1] == 'B' || m[i][j + 1] == '#')) {
                    q.push(make_pair(i, j + 1));
                    if (m[i][j + 1] == '#') isolated = false;
                } 
                if (i + 1 < r && (m[i + 1][j] == 'B' || m[i + 1][j] == '#')) {
                    q.push(make_pair(i + 1, j));
                    if (m[i + 1][j] == '#') isolated = false;
                }
                if (j - 1 >= 0 && (m[i][j - 1] == 'B' || m[i][j - 1] == '#')) {
                    q.push(make_pair(i, j - 1));
                    if (m[i][j - 1] == '#') isolated = false;
                }
                // continue;
            }
            islands.insert(p);

            if (isolated) ret[0]++;
        }

        
        if (m[i][j] == '#') {
            if (i - 1 >= 0 && m[i - 1][j] != 'B') q.push(make_pair(i - 1, j));
            if (j + 1 < c && m[i][j + 1] != 'B') q.push(make_pair(i, j + 1));
            if (i + 1 < r && m[i + 1][j] != 'B') q.push(make_pair(i + 1, j));
            if (j - 1 >= 0 && m[i][j - 1] != 'B') q.push(make_pair(i, j - 1));
        } else if (m[i][j] == 'X') {
            // m[i][j] = '#';
            // if (i - 1 >= 0 && (m[i - 1][j] == 'B' || m[i - 1][j] == '#')) q.push(make_pair(i - 1, j));
            // if (j + 1 < c && (m[i][j + 1] == 'B' || m[i - 1][j] == '#')) q.push(make_pair(i, j + 1));
            // if (i + 1 < r && (m[i + 1][j] == 'B' || m[i - 1][j] == '#')) q.push(make_pair(i + 1, j));
            // if (j - 1 >= 0 && (m[i][j - 1] == 'B' || m[i - 1][j] == '#')) q.push(make_pair(i, j - 1));
        } else if (m[i][j] == 'B') {
            if (i - 1 >= 0 && (m[i - 1][j] == 'B' || m[i - 1][j] == 'X')) q.push(make_pair(i - 1, j));
            if (j + 1 < c && (m[i][j + 1] == 'B' || m[i][j + 1] == 'X')) q.push(make_pair(i, j + 1));
            if (i + 1 < r && (m[i + 1][j] == 'B' || m[i + 1][j] == 'X')) q.push(make_pair(i + 1, j));
            if (j - 1 >= 0 && (m[i][j - 1] == 'B' || m[i][j - 1] == 'X')) q.push(make_pair(i, j - 1));

        }
    }

    return ret;
}

void solve(int map, string& s) {
    char m[80][80] = {0};
    int c = s.size();
    vector<int> ret(3);

    // fill m
    for (int j = 0; j < s.size(); j++)
        m[0][j] = s[j];

    string str;
    int r = 1;
    while (getline(cin, str)) {
        if (str.size() == 0) break;

        for (int j = 0; j < str.size(); j++)
            m[r][j] = str[j];
        // cout << '\n';
        r++;
    }

    // iter thru input matrix and do bfs where needed
    set<pair<int,int>> v;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] == '.' || v.count(make_pair(i, j))) continue;

            cout << "start of group\n";

            vector<int> tmp = bfs(i, j, m, r, c, v);

            ret[0] += tmp[0];
            ret[1] += tmp[1];
            ret[2]++;

        }
    }

    if (str.size() == 0) { 
        cout << "Map " << map << '\n';
        cout << "islands: " << ret[0] << '\n';
        cout << "bridges: " << ret[1] << '\n';
        cout << "buses needed: " << ret[2] << "\n\n";
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int map = 1;
    string s;

    while (getline(cin, s)) {
        if (s[0] == ' ')
            continue;

        solve(map, s);
        map++;
    }

}