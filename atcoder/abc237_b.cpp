#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

int main() {
   int h, w, i = 0;
   cin >> h >> w;
   map<int, vector<int>> m;
   int hclone = h;

   while (h--) {
       for (int j = 0; j < w; j++) {
           int tmp;
           cin >> tmp;
           m[i].push_back(tmp);
       }
       i++;
   }

   for (int k = 0; k < w; k++) {
       for (int j = 0; j < hclone; j++) {
            if (j != hclone - 1)
                cout << m[j][k] << ' ';
            else
                cout << m[j][k] << '\n';
        }
   }


}
