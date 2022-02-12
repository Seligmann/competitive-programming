#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <array>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <forward_list>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <queue>
#include <deque>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    const int max = (int) (2 * 1e4 + 1);
    queue<int> q; // que of values to move to
    vector<int> counts(max, -1); // visited values. -1 if not visited, > 0 if has been visited (represents the sum)

    q.push(n);
    counts[n] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int x = node - 1;
        int y = node * 2;
        if (x < 0 || y > max)
            continue;

        if (counts[x] == -1) {
            counts[x] = counts[node] + 1;
            if (x == m)
                break;
            q.push(x);
        }
        if (counts[y] == -1) {
            counts[y] = counts[node] + 1;
            if (y == m)
                break;
            q.push(y);
        }
    }

    cout << counts[m] << '\n';
    return 0;

}
