#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <array>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <forward_list>
#include <vector>
#include <cmath>
#include <stdexcept>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

using namespace std;


int main () {
    string s, t;
    vector<string> moves;
    int count = 0;
    cin >> s >> t;
    pair<char,int> curr (s[0], s[1]);
    pair<char,int> goal (t[0], t[1]);

    while(true) {
        if (curr.first < goal.first) { // move right
            curr.first = static_cast<char>(curr.first + 1);
            if (curr.second > goal.second) { // move right then down
                curr.second--;
                moves.push_back("RD");
                count++;
            }
            else if (curr.second < goal.second) { // move right then up
                curr.second++;
                moves.push_back("RU");
                count++;
            }
            else { // only ended up moving right
                moves.push_back("R");
                count++;
            }
        }
        else if (curr.first > goal.first) { // move left
            curr.first = static_cast<char>(curr.first - 1);
            if (curr.second > goal.second) { // move left then down
                curr.second--;
                moves.push_back("LD");
                count++;
            }
            else if (curr.second < goal.second) { // move left then up
                curr.second++;
                moves.push_back("LU");
                count++;
            }
            else { // only ended up moving left
                moves.push_back("L");
                count++;
            }
        }
        else if (curr.second < goal.second) {
            curr.second++;
            moves.push_back("U");
            count++;
        }
        else if (curr.second > goal.second) {
            curr.second--;
            moves.push_back("D");
            count++;
        }
        else {
            break;
        }
    }

    cout << count << '\n';
    for (auto a: moves)
        cout << a << '\n';

    return 0;

}

