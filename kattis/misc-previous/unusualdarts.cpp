#include <iostream>
#include <math.h>
using namespace std;

int t;
pair <double,double> darts[10];
int order[10];
bool vis[10];
double p;

bool onSegment (pair<double,double> p, pair<double,double> q, pair<double, double> r)
{
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) && q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
       return 1;
    return 0;
}

int orientation (pair<double,double> p, pair<double,double> q, pair<double, double> r)
{
    double num = (q.second - p.second) * (r.first - q.first) -(q.first - p.first) * (r.second - q.second);
    if (fabs(num) < 0.00000001)
        return 0;
    if (num > 0)
        return 1;
    return 2;
}

bool intersect  (pair<double,double> p1, pair<double,double> q1, pair<double,double> p2, pair<double,double> q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return 1;
    if (o1 == 0 && onSegment(p1, p2, q1))
        return 1;
    if (o2 == 0 && onSegment(p1, q2, q1))
        return 1;
    if (o3 == 0 && onSegment(p2, p1, q2))
        return 1;
    if (o4 == 0 && onSegment(p2, q1, q2))
        return 1;
    return 0;
}

bool check () {
    order[7] = order[0];

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == j || (i + 1) % 7 == j || (j + 1) % 7 == i)
                continue;
            if (intersect(darts[order[i]], darts[order[(i + 1) % 7]], darts[order[j]], darts[order[(j + 1) % 7]]))
            {
                return 0;
            }
        }
    }

    double area = 0;
    for (int i = 0; i < 7; i++)
    {
        area += (darts[order[i]].second + darts[order[i + 1]].second) * (darts[order[i]].first - darts[order[i + 1]].first);
    }
    area /= 2;
    area = fabs(area);
    double p2 = area / 4;
    p2 = p2 * p2 * p2;
    /*if (order[0] == 0 && order[1] == 3 && order[2] == 2 && order[3] == 1 && order[4] == 6 && order[5] == 4 && order[6] == 5)
        cout << area << " " << p2 << endl;*/
    if (fabs(p2 - p) < 0.00001)
    {
        for (int i = 0; i < 7; i++)
            cout << order[i] + 1 << " ";
        cout << endl;
        //cout << area << " " << p2 << endl;
        return 1;
    }
    return 0;
}

bool solve (int pos)
{
    if (pos == 7)
        return check();
    for (int i = 0; i < 7; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            order[pos] = i;
            if (solve(pos + 1))
                return 1;
            vis[i] = 0;
        }
    }
    return 0;
}

int main()
{
    cin >> t;
    t++;
    while (t-- > 1)
    {
        for (int i = 0; i < 7; i++)
        {
            cin >> darts[i].first >> darts[i].second;
            vis[i] = 0;
        }
        cin >> p;
        for (int i = 0; i < 7; i++)
        {
            order[0] = i;
            vis[i] = 1;
            if (solve(1))
                break;
            vis[i] = 0;
        }
    }
    return 0;
}
