#include <iostream>
#include <unordered_map>
#include <vector>
#define MAX 12
using namespace std;

int T, N, M, res, ans[MAX];
string colors[MAX], a, b;
bool check, vis[MAX];
unordered_map <string, int> mapp;
bool hideous[MAX][MAX];

void solve (int pos, int last)
{
    if (pos == N)
    {
        res++;
        if (check == 0)
            check = 1;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == 1 || hideous[last][i] == 1)
            continue;
        vis[i] = 1;
        if (check == 0)
            ans[pos] = i;
        solve(pos + 1, i);
        vis[i] = 0;
    }
}

int main () {
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> colors[i];
            mapp[colors[i]] = i;
            for (int j = 0; j < N; j++)
                hideous[i][j] = 0;
        }
        cin >> M;
        for (int i = 0; i < M; i++)
        {
            cin >> a >> b;
            hideous[mapp[a]][mapp[b]] = 1;
            hideous[mapp[b]][mapp[a]] = 1;
        }
        res = 0;
        check = 0;
        for (int i = 0; i < N; i++)
        {
            if (check == 0)
                ans[0] = i;
            vis[i] = 1;
            solve (1, i);
            vis[i] = 0;
        }
        cout << res << '\n';
        for (int i = 0; i < N; i++)
            cout << colors[ans[i]] << " ";
        cout << '\n';
    }
    return 0;
}