#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m[5][5] = {0};
    vector<vector<int>> coords;
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char c;
            cin >> c;

            if (c == '.')
                continue;
            else {
                coords.push_back({i,j});
                // cout << i << ' ' << j << '\n';
                m[i][j] = 1;
                cnt++;
            }
        }
    }

    if (cnt != 9) {
        cout << "invalid\n";
        return 0;
    }


    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << m[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    bool invalid = false;
    for (auto& coord: coords) {
        int i = coord[0];
        int j = coord[1];

        // cout << "curr: " << i << ' ' << j << '\n';

        if (j - 2 >= 0 && i - 1 >= 0 && m[i - 1][j - 2]) {
            // cout << "found: " << i - 1 << ' ' << j - 2 << ": " << m[i - 1][j - 2] << '\n';
            invalid = true;
            break;
        }
        if (j - 1 >= 0 && i - 2 >= 0 && m[i - 2][j - 1]) {
            // cout << "found: " << i - 2 << ' ' << j - 1 << ": " << m[i - 2][j - 1] << '\n';
            invalid = true;
            break;
        }
        if (j + 1 < 5 && i - 2 >= 0 && m[i - 2][j + 1]) {
            // cout << "found: " << i - 2 << ' ' << j + 1 << ": " << m[i - 2][j + 1] << '\n';
            invalid = true;
            break;
        }
        if (j + 2 < 5 && i - 1 >= 0 && m[i - 1][j + 2]) {
            // cout << "found: " << i - 1 << ' ' << j + 2 << ": " << m[i - 1][j + 2] << '\n';
            invalid = true;
            break;
        }
        if (j + 1 < 5 && i + 2 < 5 && m[i + 2][j + 1]) {
            // cout << "found: " << i + 2 << ' ' << j + 1 << ": " << m[i + 2][j + 1] << '\n';
            invalid = true;
            break;
        }
        if (j + 2 < 5 && i + 1 < 5 && m[i + 1][j + 2]) {
            // cout << "found: " << i + 1 << ' ' << j + 2 << ": " << m[i + 1][j + 2] << '\n';
            invalid = true;
            break;
        }
        if (j - 1 >= 0 && i + 2 < 5 && m[i + 2][j - 1]) {
            // cout << "found: " << i + 2 << ' ' << j - 1 << ": " << m[i + 2][j - 1] << '\n';
            invalid = true;
            break;
        } 
        if (j - 2 >= 0 && i + 1 < 5 && m[i + 1][j - 2]) {
            // cout << "found: " << i + 1 << ' ' << j - 2 << ": " << m[i + 1][j - 2] << '\n';
            invalid = true;
            break;
        } 

        // cout << "found nothing\n";

    }

    if (invalid) {
        cout << "invalid\n";
    } else {
        cout << "valid\n";
    }

    return 0;
}