#include <bits/stdc++.h>

typedef long unsigned int lu; 
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(std::string vars, Args&&... values) {
    std::cout << vars << " = ";
    std::string delim = "";
    (..., (std::cout << delim << values, delim = ", "));
    std::cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    
    while (c--) {
        int n;
        map<string, int> colToInt;
        map<int, string> intToCol;
        vector<vector<double>> m(c, vector<double>(4));

        cin >> n;

        int colIdx = 0;
        while (n--) {
            double x, y, v;
            string s;
            cin >> x >> y >> v >> s;

            if (!colToInt.count(s)) {
                intToCol
                [colIdx] = s;
                colToInt[s] = colIdx;
                colIdx++;
            }

            m.push_back({x, y, sqrt(v / PI), (double) colToInt[s]});
            // cout << sqrt(v/PI) << '\n';
        }

        int mm;
        cin >> mm;

        while (mm--) {
            double x, y;
            bool found = 0;

            cin >> x >> y;

            for (int i = m.size() - 1; i >= 0; i--) {
                double d = sqrt(pow(x - m[i][0], 2) + pow(y - m[i][1], 2));

                if (d <= m[i][2]) {
                    for (int k = 0; k < intToCol[m[i][3]].size(); k++) {
                        cout << intToCol[m[i][3]][k];
                    }
                    cout << '\n';
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "white\n";
        }
    }

}