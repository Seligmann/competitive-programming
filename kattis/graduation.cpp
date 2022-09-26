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

int UnionFind(int x, unordered_map<char,char>& link) {
	while (x != link[x]) {
		x = link[x];
	}

	return x;
}

bool same(int a, int b, unordered_map<char, char>& link) {
	return UnionFind(a, link) == UnionFind(b, link);
}

void unite(int a, int b, unordered_map<char,char>& link, unordered_map<char,int>& size) {
	a = UnionFind(a, link);
	b = UnionFind(b, link);

	if (size[a] < size[b])
		swap(a,b);

	size[a] += size[b];
	link[b] = a;
}

int main () {
	// cout << std::fixed;
	// cout << std::setprecision(6);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;

	cin >> n >> m >> k;

	char mat[n][m];
	int count = k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			mat[i][j] = s[j];
			// cout << s[j] << '\n';
		}
	}

	unordered_map<char, char> link;
	unordered_map<char, int> size;
	char c = 'A';
	while (k--) {
		link[c] = c;
		size[c] = 1;
		// cout << "char, link[char]: " << c << ',' << link[c] << '\n';
		c++;
	}

	char prev;
	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++) {
			prev = mat[i - 1][j];
			// cout << "count: " << count << " i,j: " <<  i << ',' << j << " | prev: " << prev << " curr: " << mat[i][j] << '\n';
			// cout << "prev link, curr link: " << link[prev] << ',' << link[mat[i][j]] << '\n';
			if (!same(prev, mat[i][j], link)) {
				count--;
				unite(prev, mat[i][j], link, size);
			}
		}
	}

	cout << count << '\n';


    return 0;
}
