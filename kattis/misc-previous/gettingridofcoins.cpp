#include <iostream>

using namespace std;

long long int P, n[4], n2[4] = {1, 5, 10, 25}, res;

bool solve (long long int price, long long int pos, long long int amount)
{
    if (price == 0)
    {
        res = amount;
        return 1;
    }
    if (pos == 5)
        return 0;
    long long int amnt = min(price / n2[pos],n[pos]);
    
    long long int i = 0;
    
    while (amnt >= 0 && price - (amnt * n2[pos]) >= 0 && solve(price - (amnt * n2[pos]), pos + 1, amount + amnt) == 0 && i <= 25)
    {
        i++;
        amnt--;
    }
    if (res != 0)
        return 1;
    return 0;
}

int main () {
    cin >> P >> n[0] >> n[1] >> n[2] >> n[3];
    solve (P, 0, 0);
    if (res > 0)
        cout << res;
    else
        cout << "Impossible";
    return 0;
}