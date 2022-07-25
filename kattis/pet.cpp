#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

int main() {
    int sum = 0;
    int max = 0;
    int maxIndex;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int tmp;
            cin >> tmp;
            sum += tmp;
            if (sum > max) {
                max = sum;
                maxIndex = i + 1;
            }
        }
        sum = 0;
    }
    cout << maxIndex << ' ' << max << '\n';
}
