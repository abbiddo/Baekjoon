#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define MAX 2001

using namespace std;
vector<int> arr[MAX];
vector<int> Tree;

void update(int Node, int start, int end, int val) {
	if (start == end) {
		Tree[Node] ++;
		return;
	}

	int mid = (start + end) / 2;
	if (val <= mid) update(Node * 2, start, mid, val);
	else update(Node * 2 + 1, mid + 1, end, val);
	Tree[Node] = Tree[Node * 2] + Tree[Node * 2 + 1];
}

ll query(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 0;
	if (left <= start && right >= end) return Tree[Node];

	int mid = (start + end) / 2;
	ll mleft = query(Node * 2, start, mid, left, right);
	ll mright = query(Node * 2 + 1, mid + 1, end, left, right);
	return mleft + mright;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b;	ll answer = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
	}

	Tree.resize(1 << (int)(1 + ceil(log2(n))));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			int x = arr[i][j];
			answer += query(1, 1, n, x + 1, n);
		}
		for (int j = 0; j < arr[i].size(); j++) {
			int x = arr[i][j];
			update(1, 1, n, x);
		}
	}
	cout << answer;
}