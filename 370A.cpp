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
    pair<int,int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    pair<int,int> rook(start);

    pair<int,int> bishop(start);
    pair<int,int> king(start);
    int rcount = 0, bcount = 0, kcount = 0;

    // rook
    if (rook.first != end.first)
        rcount++;
    if (rook.second != end.second)
        rcount++;
    cout << rcount << ' ';

    // bishop
    bool r1even = bishop.first % 2 == 0;
    bool c1even = bishop.second % 2 == 0;
    bool first = r1even == c1even;
    bool r2even = end.first % 2 == 0;
    bool c2even = end.second % 2 == 0;
    bool second = r2even == c2even;
    if (abs(bishop.first - end.first) == abs(bishop.second - end.second)) {
        bcount = 1;
        cout << bcount << ' ';
    }
    else if (first == second){
        bcount = 2;
        cout << bcount << ' ';
    }
    if (bcount != 1 && bcount != 2)
        cout << 0 << ' ';

    // king
    while (true) {
        if (king.first < end.first && king.second < end.second) {
            king.first++;
            king.second++;
            kcount++;
        }
        else if (king.first > end.first && king.second > end.second) {
            king.first--;
            king.second--;
            kcount++;
        }
        else if (king.first < end.first && king.second > end.second) {
            king.first++;
            king.second--;
            kcount++;
        }
        else if (king.first > end.first && king.second < end.second) {
            king.first--;
            king.second++;
            kcount++;
        }
        else if (king.first > end.first && king.second == end.second) {
            king.first--;
            kcount++;
        }
        else if (king.first < end.first && king.second == end.second) {
            king.first++;
            kcount++;
        }
        else if (king.second > end.second && king.first == end.first) {
            king.second--;
            kcount++;
        }
        else if (king.second < end.second && king.first == end.first) {
            king.second++;
            kcount++;
        }

        if (king.first == end.first && king.second == end.second) {
            cout << kcount << '\n';
            break;
        }
    }

return 0;
}

