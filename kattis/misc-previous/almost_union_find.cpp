#include <bits/stdc++.h>
#include <iomanip>

typedef long unsigned int lu; typedef long long int ll;
typedef long long unsigned int llu;

#define PI 3.14159265359

using namespace std;


struct Node {
	int val;
	int parent;
	int size;
	int sum;
	vector<int> adj;
};


int unionFind (int a, vector<Node>& link) {
	while (link[a].val != link[a].parent) {
		link[a].val = link[a].parent;
		a = link[a].val;
	}

	return a;
}

void unite(int a, int b, vector<Node>& link, vector<Node>& size, vector<Node>& sum){
	a = unionFind(a, link);
	b = unionFind(b, link);

	if (size[a].size < size[b].size)
		swap(a, b);

	size[a].size += size[b].size;
	sum[a].size += sum[b].size;
	link[b].parent = a;
}

bool same(int a, int b, vector<Node>& link) {
	return unionFind (a, link) == unionFind (b, link );
}

int main() {
	int n;
	while (cin >> n) {
		int m;
		cin >> m;
		vector<Node> link;
		vector<Node> size;
		vector<Node> sum;

		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			Node nd;
			nd.val = i;
			nd.parent = i;
			nd.size = 1;
			nd.sum = i;

			link[nd.val] = nd;
			size[nd.val] = nd;
			sum[nd.val] = nd;
		}

		while (m--) {
			int comm, p, q;
			cin >> comm;

			switch (comm) {
			case 1:
				cin >> p >> q;
				if (!same(p, q, link )) {
					unite(p, q, link, size, sum);					
				}

				break;

			case 2:
				cin >> p >> q;
				removeAndMove(p, q, link, size, sum, adj);	
				break;

			case 3:
				cin >> p;
				cout << size[link[p].val].size << ' ' << sum[link[p].val].sum << '\n';
				break;
			
			default:
				break;
			}
		}
	}


	return 0;
}