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

// vector<string> colors;
map<int, string> colors;
map<string, int> colorsToInt;
map<int, map<int, int>> hideous;
vector<int> best(12), used(12);

int dp(int prev, int step, int N) {
    if (step == N) {
        return 1;
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (used[i] == 1)
            continue;

        if (prev != -1 && hideous[prev][i] == 1)
            continue;

        used[i] = 1;
        prev = i;
        step++;

        cnt += dp(i, step, N);
        step--;
        used[i] = 0;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            string tmp;
            cin >> tmp;
            // colors.push_back(tmp);
            colors[i] = tmp;
            colorsToInt[tmp] = i;
            hideous[i] = {};
        }

        int M;
        cin >> M;

        for (int i = 0; i < M; i++) {
            string tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            hideous[colorsToInt[tmp1]][colorsToInt[tmp2]] = 1; 
            hideous[colorsToInt[tmp2]][colorsToInt[tmp1]] = 1;
        }

        cout << dp(-1, 0, N) << '\n';

        colors.clear();
        colorsToInt.clear();
        hideous.clear();
        best.clear();
        used.clear();
        

    }
}