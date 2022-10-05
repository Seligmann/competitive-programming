#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, currEv = 1;
    map<string, int> events;
    stack<string> stk;
    cin >> n;

    while (n--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'E') {
            string s;
            cin >> s;
            events[s] = currEv;
            currEv++;
            stk.push(s);
            // st.insert(s); 
        } else if (cmd == 'D') {
            int d;
            cin >> d;
            while (d--) {
                string recent = stk.top();
                events.erase(recent);
                currEv--;
                stk.pop();
            }
        } else {
            int sc, nEventsToRemove = INT_MIN;
            bool scenariosExist = true, pltErr = false;

            cin >> sc;

            // get list of scenarios
            set<string> scenarios;
            while (sc--) {
                string curr;
                cin >> curr;

                // does the current situation's opposite exist in the list of scenarios given?
                if (curr[0] == '!') {
                    string woBang = curr.substr(1, curr.size());
                    if (scenarios.count(woBang)) {
                        pltErr = true;
                        break;
                    }
                } else {
                    string wBang = "!";
                    wBang.append(curr);
                    if (scenarios.count(wBang)) {
                        pltErr = true;
                        break;
                    }
                }

                scenarios.insert(curr);
            }

            if (pltErr) {
                cout << "Plot Error\n";
                continue;
            }

            // iterate through scenarios
            for (auto it = scenarios.begin(); it != scenarios.end(); it++) {
                string curr = *it;
                string wBang = "!";
                wBang.append(curr);
                string woBang = curr.substr(1, curr.size());

                if (events.count(curr)) { // scenario exists in events -> Continue
                    continue;
                } else if (curr[0] == '!' && events.count(woBang)) { // scenario opposite exists in events -> n Just a dream
                    scenariosExist = false;
                    nEventsToRemove = max(nEventsToRemove, currEv - events[woBang]);

                } else if (curr[0] != '!' && events.count(wBang)) {
                    scenariosExist = false;
                    nEventsToRemove = max(nEventsToRemove, currEv - events[wBang]);

                } else if (curr[0] == '!') {
                    continue;
                } else {
                    cout << "Plot Error\n";
                    pltErr = true;
                    break;
                }
                
                // neither the scenario nor its opposite exists in events -> plot error
            }

            if (pltErr) {
                continue;
            } else if (!scenariosExist) {
                cout << nEventsToRemove << ' ' << "Just A Dream\n";
            } else {
                cout << "Yes\n";
            }

        }
    }
}