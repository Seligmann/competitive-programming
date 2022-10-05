#include <iostream>

using namespace std;

int a, b, turns, winner;

int main () {
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        winner = -1; 
        turns = 0;
        while (a > 0 && b > 0)
        {
            if (max(a, b) / min(a, b) > 1)
            {
                winner = turns;
                break;
            }
            if (a > b)
                a %= b;
            else
                b %= a;
            turns++;
        }
        if ((winner != -1 && winner % 2 == 0) || (winner == -1 && turns % 2 == 1))
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
    }
    return 0;
}