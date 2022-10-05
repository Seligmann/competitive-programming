#include <iostream>
#include <math.h>

using namespace std;

int T, k, A[4][3]{{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}}, res, res2;

void solve (int x, int y, int sum)
{
    if (sum > 999 || x >= 4 || y >= 3 || A[x][y] == -1)
        return;
    int sum2 = sum * 10 + A[x][y];
    if (abs(sum2 - k) < res)
    {
        res = abs(sum2 - k);
        res2 = sum2;
    }
    solve (x + 1, y, sum);
    solve (x + 1, y, sum2);
    solve (x, y + 1, sum);
    solve (x, y + 1, sum2);
    if (sum2 != 0)
        solve (x, y, sum2);
}
int main () {
    cin >> T;
    
    while (T--)
    {
        cin >> k;
        res = 1000000000;
        solve(0,0,0);
        cout << res2 << "\n";
    }
    return 0;
}