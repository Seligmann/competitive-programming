#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;

    cin >> r >> c;

    char m[r][c];

    int rr = r;
    int ii = 0;
    while (rr--) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            m[ii][j] = s[j];
        }
        ii++;
    }

    vector<int> lowest(c, r - 1);

    for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            if (m[i][j] == '#') {
                lowest[j] = i - 1;
            } else if (m[i][j] == '.') {
                continue;
            } else if (m[i][j] == 'a') {
                if (lowest[j] > i) {
                    m[i][j] = '.';
                    m[lowest[j]][j] = 'a';
                    lowest[j]--;
                } else if (lowest[j] == i) {
                    lowest[j]--;
                }

            }

        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j];
        }
        cout << '\n';
    }


}