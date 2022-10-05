#include <bits/stdc++.h>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359;

using namespace std;

void printStr(string& s) {
	for (int i = 0; i < s.size(); i++)
		cout << s[i];
	cout << '\n';
}

int UnionFind(int x, unordered_map<int,int>& link) {
	while (x != link[x]) {
		x = link[x];
	}

	return x;
}

bool same(int a, int b, unordered_map<int,int>& link) {
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
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, q;
	cin >> n >> q;

	unordered_map<int,int> link;
	unordered_map<int,int> size;

	for (int i = 1; i <= n; i++) {
		link[i] = i;
		size[i] = 1;
	}

	while (q--) {
		char c;
		cin >> c;

		if (c == 't') {
			int a, b;
			cin >> a >> b;

			if (!same(a, b, link)) {
				unite(a, b, link, size);
			}

		} else {
			int a;
			cin >> a;

			cout << size[UnionFind(a, link)] << '\n';
		}
	}

    return 0;
}
