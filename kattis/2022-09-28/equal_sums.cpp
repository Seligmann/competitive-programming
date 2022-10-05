#include <bits/stdc++.h>

using namespace std;

typedef long unsigned int lu; 
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359
#define MAX 100000

int rec(vector<int>& input, vector<int> v1, vector<int> v2, vector<int> v3, vector<int> v4, set<vector<int>>& visited, int i) {
    if (visited.count(v1) || visited.count(v2))
        return 0;
    visited.insert(v1);
    visited.insert(v2);


    if (accumulate(v1.begin(), v1.end(), 0) == accumulate(v2.begin(), v2.end(), 0)) {
        return 1;
    }

    return (rec(input, v1.push_back(input[i + 1]), v2, i + 1) || rec(input, v1, v2.push_back(input[i + 1]), i + 1) || rec(input, v1.))
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int T, casen = 1;
    cin >> T;

    while (T--) {
        cout << "Case #" << casen << ":\n";
        casen++;

        int S;
        vector<int> input, v1, v2;
        set<vector<int>> visited;
        cin >> S;

        for (int i = 0; i < S; i++) {
            int tmp;
            cin >> tmp;

            input.push_back(tmp);
        }

        vector<int> v1cpy = v1;
        vector<int> v2cpy = v2;
        v1cpy.push_back(input[0]);
        v2cpy.push_back(input[0]);

    }

}