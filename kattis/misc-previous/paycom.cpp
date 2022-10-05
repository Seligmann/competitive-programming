#include <bits/stdc++.h>

typedef long unsigned int lu; 
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(std::string vars, Args&&... values) {
    std::cout << vars << " = ";
    std::string delim = "";
    (..., (std::cout << delim << values, delim = ", "));
    std::cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int x = a, y = b;

    while (x != y) {
        if (x > y)
            x -= y;

        if (x < y)
            y -=x;
    }

    cout << x << ' ' << y << '\n';

}
