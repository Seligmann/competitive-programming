#include <iostream>
#define MAX 22
using namespace std;

struct page {
    int w;
    int h;
    int x;
    int y;
};

int n, inter[MAX], num, pow2, ans, areas[MAX], vis[2000000], testCase, vis2[2000000];
bool intersections[MAX][MAX];
page pages[MAX];

int area, bitmask;

bool intersect (int i, int j)
{
    if (pages[i].x >= pages[j].x + pages[j].w || pages[j].x >= pages[i].x + pages[i].w)
        return 0;
    if (pages[i].y >= pages[j].y + pages[j].h || pages[j].y >= pages[i].y + pages[i].h)
        return 0;
    return 1;
}

int findArea (int i)
{
    return pages[i].h * pages[i].w;
}

void solve ()
{
    if (area > ans)
        ans = area;
    if (vis[bitmask] == testCase && area <= vis2[bitmask])
        return;
    vis[bitmask] = testCase;
    vis2[bitmask] = area;
    int power = 1;
    int temp = bitmask;
    for (int i = 0; i < n; i++)
    {
        if ((power & temp) == 0)
        {
            bitmask = (temp | inter[i]);
            area += areas[i];
            solve ();
            area -= areas[i];
        }
        power *= 2;
    }
    return;
}

int main()
{
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        ans = 0;
        testCase++;
        for (int i = 0; i < n; i++)
        {
            inter[i] = 0;
            for (int j = 0; j < n; j++)
                intersections[i][j] = 0;
            cin >> pages[i].w >> pages[i].h >> pages[i].x >> pages[i].y;
            areas[i] = findArea(i);
        }
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (intersect(i, j))
                {
                    intersections[i][j] = 1;
                    intersections[j][i] = 1;
                }
        for (int i = 0; i < n; i++)
        {
            num = 0;
            pow2 = 1;
            for (int j = 0; j < n; j++)
            {
                if (intersections[i][j])
                    num += pow2;
                pow2 *= 2;
            }
            inter[i] = num;
        }
        for (int i = 0; i < n; i++)
        {
            area = areas[i];
            bitmask = inter[i];
            solve();
        }
        cout << ans << '\n';
    }
    return 0;
}
