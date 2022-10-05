#include <iostream>
#include <iomanip>
#define MAX 1005

using namespace std;

int n, A[MAX][2];
double area;

int main () {
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> A[i][0] >> A[i][1];
        A[n][0] = A[0][0];
        A[n][1] = A[0][1];
        area = 0;
        for (int i = 0; i < n; i++)
            area += (A[i][1] + A[i + 1][1]) * (A[i][0] - A[i + 1][0]);
        area /= 2;
        if (area < 0)
            cout << "CW ";
        else
            cout << "CCW ";
        cout << fixed << setprecision(1) << abs(area) << "\n";
    }
}