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

int countOcc(int i, int j, int m[][20], int n, set<pair<int,int>>& fillVisited, int& trav, set<pair<int,int>>& occV) {
    cout << "counting occurences\n";
    queue<pair<int,int>> q;
    set<pair<int,int>> v;
    int cnt = 0, c = m[i][j];

    q.push(make_pair(i,j));

    cout << "matrix before count\n";
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            cout << m[k][l];
        }
        cout << '\n';
    }

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        pair<int,int> p = make_pair(i,j);
        q.pop();

        if (m[i][j] != c)
            continue;

        if (occV.count(p) || v.count(p))
            return cnt;

        occV.insert(p);
        v.insert(p);

        // if (v.count(p) || occV.count(p))
        //     continue;

        // v.insert(p);

        // if (fillVisited.count(p))
        //     continue;

        // deb(i, j, m[i][j], cnt, trav);

        // if (m[i][j] == c)
        //     fillVisited.insert(p);

        // if (m[i][j] != c)
        //     continue;

        cnt++;
        trav++;

        if (i - 1 >= 0) q.push(make_pair(i - 1, j));
        if (j + 1 < n) q.push(make_pair(i, j + 1));
        if (i + 1 < n) q.push(make_pair(i + 1, j));
        if (j - 1 >= 0) q.push(make_pair(i, j - 1));
    }

    deb(c, cnt);

    return cnt;
}

void bfs(int oc, int c, int n, int m[][20], int colorChoiceFreq[7], set<pair<int,int>>& lastFill) {
    cout << "bfs\n";

    queue<pair<int,int>> q;
    set<pair<int,int>> v;
    vector<vector<int>> colorFreqs(7, vector<int>(2));
    int trav = 0;

    q.push(make_pair(0,0));
    m[0][0] = c;

    set<pair<int,int>> occV;
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        pair<int,int> p = make_pair(i,j);
        q.pop();

        if (v.count(p))
            continue;

        if (m[i][j] == oc && lastFill.count(p)) {
            m[i][j] = c;
            trav++;
        }

        v.insert(p);
        // lastFill.insert(p);

        deb(oc, c, i, j, m[i][j]);

        // keep track of # of possible tiles to color for each color
        if (m[i][j] != c && occV.count(p) == 0) {
            colorFreqs[m[i][j]][0] = m[i][j];
            colorFreqs[m[i][j]][1] += countOcc(i, j, m, n, v, trav, occV);
        }

        if (m[i][j] != c && m[i][j] != oc)
            continue;


        lastFill.insert(p);

        if (i - 1 >= 0) q.push(make_pair(i - 1, j));
        if (j + 1 < n) q.push(make_pair(i, j + 1));
        if (i + 1 < n) q.push(make_pair(i + 1, j));
        if (j - 1 >= 0) q.push(make_pair(i, j - 1));
    }

    cout << "matrix\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j];
        }
        cout << '\n';
    }

    sort(colorFreqs.begin(), colorFreqs.end(), [](const vector<int>& v1, const vector<int>& v2) { return v1[1] > v2[1]; });
    cout << "color freqs:\n";
    for (auto& v: colorFreqs)
        deb(v[0], v[1]);

    if (colorFreqs[0][0] == 0 && colorFreqs[0][1] == 0 || (trav == n * n))
        return;


    int mnColor = colorFreqs[0][0];
    int mxFreq = colorFreqs[0][1];

    for (int k = 1; k < colorFreqs.size(); k++) {
        deb(mnColor, mxFreq);

        if (mxFreq == colorFreqs[k][1])
            mnColor = min(mnColor, colorFreqs[k][0]);
        else {
            cout << "chose color " << mnColor << '\n';
            colorChoiceFreq[mnColor]++;
            break;
        }
    }

    // if (mnColor != oc) // color change is needed
    //     colorChoiceFreq[mnColor]++;

    bfs(m[0][0], mnColor, n, m, colorChoiceFreq, lastFill);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        int m[20][20] = {0};
        int colorChoiceFreq[7] = {0};
        set<pair<int,int>> lastFill;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < n; j++) {
                m[i][j] = s[j] - '0';
            }
        }

        bfs(m[0][0], m[0][0], n, m, colorChoiceFreq, lastFill);

        int ret = 0;
        for (int i = 1; i < 7; i++)
            ret += colorChoiceFreq[i];

        cout << ret << '\n';
        for (int i = 1; i < 7; i++) {
            if (i < 6)
                cout << colorChoiceFreq[i] << ' ';
            else
                cout << colorChoiceFreq[i] << '\n';
        }

    }

    /*
    1
    6
    123423
    334521
    433123
    543621
    324343
    234156
    */
}