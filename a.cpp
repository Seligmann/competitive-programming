#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <limits.h>

typedef long long ll;

using namespace std;

#define MOD 1000000007;

int f(int n) {
    if (n < 7)
        return pow(2, n-1) % MOD;
    else
        return (f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)) % MOD;

}

int main() {
    double x;
    cin >> x;
//    vector<int> dpTable(x, -1);
    cout << f(x) << '\n';
}



