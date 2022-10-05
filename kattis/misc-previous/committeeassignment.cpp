#include <iostream>
#include <unordered_map>
#define MAX 20
using namespace std;

int n, m, last, pow2[MAX], num = 1, bitmasks[MAX], committees[MAX], com, ans;
string s1, s2;
unordered_map <string, int> mapp, vis;

void solve (int pos)
{
    if (com > ans)
        return;
    if (pos == last)
    {
        if (com < ans)
            ans = com;
        return;
    }
    int temp = 0;
    for (int i = 0; i < com; i++)
    {
        if ((committees[i] & pow2[pos]) == 0)
        {
            temp = committees[i];
            committees[i] = (committees[i] | bitmasks[pos]);
            solve(pos + 1);
            committees[i] = temp;
        }
    }
    committees[com] = bitmasks[pos];
    com++;
    solve(pos + 1);
    com--;
    committees[com] = 0;
    return;
}

int main () {
    
    for (int i = 0; i < 20; i++)
    {
        pow2[i] = num;
        num *= 2;
    }

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        if (m == 0)
        {
            cout << "1\n";
            continue;
        }
        mapp.clear();
        last = 0;
        vis.clear();
        for (int i = 0; i < 16; i++)
        {
            committees[i] = 0;
            bitmasks[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> s1 >> s2;
            if (vis[s1] == 0)
            {
                vis[s1] = 1;
                mapp[s1] = last;
                bitmasks[last] += pow2[last];
                last++;
            }
            if (vis[s2] == 0)
            {
                vis[s2] = 1;
                mapp[s2] = last;
                bitmasks[last] += pow2[last];
                last++;
            }
            bitmasks[mapp[s1]] += pow2[mapp[s2]];
            bitmasks[mapp[s2]] += pow2[mapp[s1]];
        }
        com = 0;
        ans = 1000000;
        solve(0);
        cout << ans << "\n";
    }
    return 0;
}