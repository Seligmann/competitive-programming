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

void printStr(const string& s) {
    for (auto c: s)
        cout << c;
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        cin.ignore();
        string s;
        getline(cin, s, '.');

        if (s.size() < 10)
            continue;

        string check = s.substr(0, 10);

        if (check.compare("Simon says") == 0) {
            string ret = s.substr(check.size() + 1, s.size() - check.size() + 1);
            ret.push_back('.');

            for (auto c: ret)
                cout << c;
            cout << '\n';
        }
    }
}
