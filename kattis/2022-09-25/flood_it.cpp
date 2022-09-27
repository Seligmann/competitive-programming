#include <bits/stdc++.h>

typedef long unsigned int lu; 
typedef long long int ll;
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

int countOcc(int i, int j, int c, int n, int m[][20], set<pair<int,int>>& coordsCounted) {
    set<pair<int, int>> v;
    queue<pair<int, int>> q;
    int cnt = 0;

    q.push(make_pair(i, j));

    while (!q.empty()) {
        int ii = q.front().first;
        int jj = q.front().second;
        q.pop();
        pair<int, int> p = make_pair(ii, jj);

        if (v.count(p))
            continue;

        v.insert(p);

        if (m[ii][jj] != c) {
            // cout << "m[ii][jj] != c\n";
            continue;
        }

        coordsCounted.insert(p);

        cnt++;

        if (ii - 1 >= 0) q.push(make_pair(ii - 1, jj));
        if (jj + 1 < n) q.push(make_pair(ii, jj + 1));
        if (ii + 1 < n) q.push(make_pair(ii + 1, jj));
        if (jj - 1 >= 0) q.push(make_pair(ii, jj - 1));
    }

    return cnt;
}

void bfs(int oc, int c, int m[][20], int n, vector<int>& colorChoiceFreqs, set<pair<int, int>>& prevFill) {
    set<pair<int,int>> v;
    queue<pair<int,int>> q;
    unordered_map<int, vector<pair<int, int>>> colorToPos;

    q.push(make_pair(0,0));

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        pair<int, int> p = make_pair(i, j);

        if (v.count(p))
            continue;
        v.insert(p);

        // filling
        if (m[i][j] == oc && (oc == c || prevFill.count(p))) { // filling tiles w/ previous best color choice w/ new color choice
            // cout << "filled " << m[i][j] << " at " << i << ',' << j << " with " << c << '\n';
            m[i][j] = c;
            prevFill.insert(p);
        } else if (m[i][j] == c) { // filling tiles that are best color choice
            // cout << "filled " << m[i][j] << " at " << i << ',' << j << " with " << c << '\n';
            prevFill.insert(p);
        } else {
            // cout << "found bordering tile color " << m[i][j] << " at " << i << ',' << j << '\n';
            colorToPos[m[i][j]].push_back(p);
            continue;
        }

        if (i - 1 >= 0) q.push(make_pair(i - 1, j));
        if (j + 1 < n) q.push(make_pair(i, j + 1));
        if (i + 1 < n) q.push(make_pair(i + 1, j));
        if (j - 1 >= 0) q.push(make_pair(i, j - 1));
    }

    set<pair<int, int>> coordsCounted;
    vector<vector<int>> colorFreqs(7, vector<int>(2));

    // iter through coordinates of tiles on edge of last fill to find how many more tiles each color choice yields
    for (auto it = colorToPos.begin(); it != colorToPos.end(); it++) {
        colorFreqs[it->first][0] = it->first;

        for (int k = 0; k < it->second.size(); k++) {
            int row = it->second[k].first;
            int col = it->second[k].second;

            if (coordsCounted.count(make_pair(row, col)))
                continue;

            colorFreqs[it->first][1] += countOcc(row, col, it->first, n, m, coordsCounted);
        }
        
        // deb(it->first, colorFreqs[it->first][1]);
    }

    // find best choice for next fill
    sort(colorFreqs.begin(), colorFreqs.end(), [](const vector<int>& v1, const vector<int>& v2) { return v1[1] > v2[1]; });

    int mnColor = colorFreqs[0][0];
    int mxFreq = colorFreqs[0][1];

    if (mnColor == 0)
        return;

    assert(mxFreq > 0);

    for (int k = 1; k < colorFreqs.size(); k++) {
        if (mxFreq == colorFreqs[k][1]) {
            mnColor = min(mnColor, colorFreqs[k][0]);
        } else {
            break;
        }
    }
    // cout << "chose color " << mnColor << '\n';
    colorChoiceFreqs[mnColor]++;

    bfs(m[0][0], mnColor, m, n, colorChoiceFreqs, prevFill);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        int m[20][20] = {0};
        cin >> n;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < n; j++) {
                m[i][j] = s[j] - '0';
            }
        }

        vector<int> colorChoiceFreqs(7, 0);
        set<pair<int, int>> prevFill;

        bfs(m[0][0], m[0][0], m, n, colorChoiceFreqs, prevFill);

        cout << accumulate(colorChoiceFreqs.begin(), colorChoiceFreqs.end(), 0) << '\n';
        for (int i = 1; i < colorChoiceFreqs.size(); i++) {
            if (i < 6)
                cout << colorChoiceFreqs[i] << ' ';
            else
                cout << colorChoiceFreqs[i] << '\n';
        }
    }
}
