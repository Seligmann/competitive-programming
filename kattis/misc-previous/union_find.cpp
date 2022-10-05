#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;

// UTILITY (MIGHT NOT BE USED)
void printStr(const string& s) {
	for (lu i = 0; i < s.size(); i++)
		cout << s[i];
	cout << '\n';
}

int UnionFind(int x, unordered_map<int,int>& link) {
	while (x != link[x]) {
		x = link[link[x]];
	}

	return x;
}

bool same(int a, int b, unordered_map<int, int>& link) {
	return UnionFind(a, link) == UnionFind(b, link);
}

void unite(int a, int b, unordered_map<int,int>& link, unordered_map<int,int>& size) {
	a = UnionFind(a, link);
	b = UnionFind(b, link);

	if (size[a] < size[b])
		swap(a,b);

	size[a] += size[b];
	link[b] = a;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;

	cin >> n >> q;

	unordered_map<int,int> link;
	unordered_map<int,int> size;

	for (int i = 0; i < n; i++) {
		link[i] = i;
		size[i] = 1;
	}

	while (q--) {
		char c;
		int a, b;
		cin >> c >> a >> b;

		if (c == '=') {
			if (!same(a, b, link)) {
				unite(a, b, link, size);
			}
		} else {
			if (same(a, b, link)) {
				cout << "yes\n";
			} else {
				cout << "no\n";
			}
		}
	}
    return 0;
}
