#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

string unionFind (string a, unordered_map<string, string>& link) {
    while (a != link[a]) {
        a = link[link[a]];
    }

    return a;
}

bool same(string a, string b, unordered_map<string, string>& link) {
    return (unionFind(a, link) == unionFind (b, link));
}

void unite(string a, string b, unordered_map<string, string>& link, unordered_map<string, int>& size) {
    a = unionFind(a, link);
    b = unionFind(b, link);

    if (size[a] < size[b])
        swap(a, b);

    size[a] += size[b];
    link[b] = a;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int c;

    cin >> c;

    while (c--) {
        unordered_map<string, string> link;
        unordered_map<string, int> size;
        set<string> people;
        int f;

        cin >> f;
        cin.ignore();
        while (f--) {
            string s1, s2;

            getline(cin, s1, ' ');
            getline(cin, s2);

            if (people.count(s1) == 0) {
                people.insert(s1);
                link[s1] = s1;
                size[s1] = 1;
            }

            if (people.count(s2) == 0) {
                people.insert(s2);
                link[s2] = s2;
                size[s2] = 1;
            }

            if (!same(s1, s2, link)) {
                unite(s1, s2, link, size);
            }

            cout << size[unionFind(s1, link)] << '\n';
        }

    }


    return 0;
}
