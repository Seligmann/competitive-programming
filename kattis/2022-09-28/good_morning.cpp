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

char m[4][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}, {'.','0','.'}};
int currMin = INT_MAX;

int dfs(int i, int j, string kstr, int k, int curr, string currStr) {
    if (m[i][j] == '.' || abs(curr - k) >= currMin && curr > k)
        return INT_MIN;

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        string k;
        cin >> k;

        cout << dfs(0, 0, k, stoi(k), 0, "") << '\n';

        currMin = INT_MAX;
    }    
}
