#include <iostream>
#include <math.h>
#define MAX 105
using namespace std;

int c, n, m;
double X[MAX], Y[MAX], V[MAX], x, y, r, d;
string S[MAX];


int main () {
    cin >> c;
    while (c--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> X[i] >> Y[i] >> V[i] >> S[i];
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            for (int j = n - 1; j >= 0; j--)
            {
                r = sqrt(V[j] / M_PI);
                d = sqrt(pow(X[j] - x, 2) + pow(Y[j] - y, 2));
                if (d <= r)
                {
                    cout << S[j] << "\n";
                    break;
                }
                if (j == 0)
                    cout << "white\n";
            }
        }
    }
    return 0;
}