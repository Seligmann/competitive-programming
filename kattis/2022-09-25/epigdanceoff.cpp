#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    bool found = false;
    cin >> n >> m;

    vector<int> pos(m, 1);

    while (n--) {
        int i = m, j = 0;
        while (i--) {
            char c;
            cin >> c;

            if (c == '$') {
                pos[j] = 0;
                found = true;
            }

            j++;
        }
    }

    int cnt = 0;
    for (auto x: pos)
        cnt += x;

    cnt++;

    if (found)
        cout << cnt << '\n';
    else
        cout << 0 << '\n';
}