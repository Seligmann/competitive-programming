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
    cin >> n;
    stack<int> stk;
    int j = n; // save for last loop

    while (n--) {
        int tmp;
        cin >> tmp;
        stk.push(tmp);
    }
    for (int i = 0; i < j; i++) {
        cout << stk.top() << '\n';
        stk.pop();
    }
}
