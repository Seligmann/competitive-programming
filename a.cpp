#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <limits.h>

using namespace std;

int main() {
    int n;
    map<int, vector<int>> v;
    cin >> n;
    while (n--) {
        string str;
        int sq;
        cin >> str;
        sq = sqrt(str.length());

        int currChar = 0;
        for (int i = 0; i < sq; i++) {
            for (int j = 0; j < sq; j++) {
                v[i].push_back(str[currChar]);
                currChar++;
            }
        }
        

        
    }
}
