#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "clion-misra-cpp2008-5-0-4"
#pragma ide diagnostic ignored "clion-misra-cpp2008-8-0-1"
#pragma ide diagnostic ignored "clion-misra-cpp2008-0-1-7"
#include <bits/stdc++.h>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

using namespace std;

void fastscan();

void fastscan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c=='-')
    {
        negative = true;

        c = getchar();
    }

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    if (negative)
        number *= -1;
}

int main () {
    ios_base::sync_with_stdio(false); // NOLINT(clion-misra-cpp2008-0-1-7)
    cin.tie(nullptr);

        ll n , t;
        cin >> t;
        while(t--)
        {
            vector<ll> v;
            ll sum;
            cin >> n;
            for (ll i = 0; i < n; i++) {
                ll tmp;
                cin >> tmp;
                v.push_back(tmp);
            }
            sort(v.begin(), v.end());
            ll behind = 0;
            ll j = 1;
            ll remain = n - j;
            ll m = (remain * behind) + remain;
            sum = v[n - 1];
            for (ll i = n - 1; i > 0; i--) {
                ll tmp = m * (v[i - 1] - v[i]);
                if (tmp > 0) {
                    tmp = -tmp;
                }
                sum += tmp;
                behind++;
                remain--;
                m = (remain * behind) + remain;
            }
            cout << sum << '\n';


        }

    return 0;

}


#pragma clang diagnostic pop