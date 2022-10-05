#include <iostream>
#include <unordered_map>
#define MAX 25

using namespace std;

int t, N, A[MAX], res, res2, pos2, testCase = 1;
unordered_map <int, int> mapp;

int solve (int pos, int sum, int prev, bool check)
{
    if (pos > N)
        return 0;
    if (mapp[sum] != 0 && check == 1)
    {
        res2 = sum;
        pos2 = prev + 1;
        return sum;
    }
    if (check == 1)
        mapp[sum] = prev + 1;
    int res3 = 0;
    res3 = solve(pos + 1, sum, prev, 0);
    if (res3)
        return res3;
    res3 = solve(pos + 1, sum + A[pos], sum, 1);
    if (res3)
        return res3;
    return 0;
}

int main () {
    cin >> t;
    while (t--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> A[i];
        res = solve(0,0,0,0);
        cout << "Case #" << testCase << ":\n";
        if (res == 0)
        {
            cout << "Impossible\n";
            testCase++;
            mapp.clear();
            continue;
        }
        while (mapp[res] - 1 > 0)
        {
            cout << res - mapp[res] + 1 << " ";
            res = mapp[res] - 1;
        }
        cout << res << "\n";
        mapp[res2] = pos2;
        while (mapp[res2]  - 1 > 0)
        {
            cout << res2 - mapp[res2]  + 1<< " ";
            res2 = mapp[res2] - 1;
        }
        cout << res2 << "\n";
        testCase++;
        mapp.clear();
    }
    return 0;
}