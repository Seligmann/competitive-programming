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
    int distanceToMove = 0;
    map<char, vector<int>> mp;
    char c = 'A';
    int tmpi = 0;
    int tmpj = 0;
    while (c != 'P') {
        mp[c].push_back(tmpi);
        mp[c].push_back(tmpj);
        c++;
        tmpj++;
        if (tmpj == 4) {
            tmpj = 0;
            tmpi++;
        }
        
    }
    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 4; j++) {
            if (str[j] == '.') continue;
            distanceToMove += abs(mp[str[j]][0] - i) + abs(mp[str[j]][1] - j);
        }
    }
    cout << distanceToMove << '\n';
}

