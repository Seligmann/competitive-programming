#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, focus;
    cin >> n >> focus;
    n--;
    while (n--) {
        int t;
        cin >> t;
        if (t % focus == 0) {
            cout << t << '\n';
            cin >> focus;
            n--;
        }
    }
}
