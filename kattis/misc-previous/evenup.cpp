#include <bits/stdc++.h>

using namespace std;

int dfs(set<vector<stack<int>>>& visited, stack<int>& og, stack<int>& aux, map<vector<stack<int>>, int>& mem, int count) {
	if (visited.count({og, aux})) {
		return INT_MAX;
	}

	visited.insert({og, aux});

	if (og.empty() && aux.empty()) {
		return count;
	}

	if (mem.count({og, aux})) {
		return mem[{og, aux}];
	}

	int matchRemoved = INT_MAX;
	if (!og.empty() && !aux.empty()) {
		int ogTop = og.top(), auxTop = aux.top();
		if (ogTop == auxTop) {
			og.pop();
			aux.pop();
			matchRemoved = dfs(visited, og, aux, mem, count + 1);
			visited.erase({og, aux});
			og.push(ogTop);
			aux.push(auxTop);
		}
	}

	int ogToAux = INT_MAX, auxToOg = INT_MAX, mn;

	if (!og.empty()) {
		aux.push(og.top());
		og.pop();
		ogToAux = dfs(visited, og, aux, mem, count + 1); // 2: [2],[1], 3: -,[2,1]
		visited.erase({og, aux});
		og.push(aux.top());
		aux.pop();
	}

	if (!aux.empty()) { // -,[1,2]
		og.push(aux.top());
		aux.pop();
		auxToOg = dfs(visited, og, aux, mem, count + 1); // 1,2
		visited.erase({og, aux});
		aux.push(og.top());
		og.pop();
	}

	mn = min(ogToAux, auxToOg);
	mn = min(mn, matchRemoved);

	mem[{og, aux}] = mn;

	return mn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> og;
	stack<int> aux;
	set<vector<stack<int>>> visited;
	map<vector<stack<int>>, int> mem;
	int n, mn = INT_MAX;

	cin >> n;
	n *= 2;

	// make stack 
	vector<int> tmpv;
	while (n--) {
		int tmp;
		cin >> tmp;
		tmpv.push_back(tmp);
	}

	for (int i = tmpv.size() - 1; i >= 0; i--) {
		og.push(tmpv[i]);
	}

	int ret = dfs(visited, og, aux, mem, 0);

	if (ret == INT_MAX) cout << "impossible\n";
	else cout << ret << '\n';

	return 0;
}