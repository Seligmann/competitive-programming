#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        string ret;

        cin >> n >> m;

        vector<int> all(m, 0);

        int nn = n;
        while (nn--) {
            string s;
            cin >> s;

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '1')
                    all[i]++;
            }
        }

        for (int i = 0; i < all.size(); i++) {
            if (n - all[i] < n + (all[i] - n))
                ret.push_back('1');
            else
                ret.push_back('0');
        }

        for (auto c: ret)
            cout << c;
        cout << '\n';
    }
}