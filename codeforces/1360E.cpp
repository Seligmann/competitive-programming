#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <array>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <forward_list>
#include <vector>
#include <cmath>
#include <stdexcept>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

using namespace std;


int main () {
    int t, n;
    cin >> t;

    for (int k = 0; k < t; k++) {
        // read
        cin >> n;
        int poly[n][n];
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < n; j++) {
                poly[i][j] = tmp[j] - '0';
            }
        }

        // solve
        bool flag = false;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-1; j++) {
                if (poly[i][j] == 0)
                    continue;
                else {
                    if (poly[i][j+1] == 0 && poly[i+1][j] == 0) {
                        flag = true;
                        cout << "NO\n";
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << "YES\n";
    }

return 0;
}

