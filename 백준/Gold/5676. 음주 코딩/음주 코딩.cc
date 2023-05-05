#include <iostream>
#include <cmath>
#define MAX 100001
using namespace std;

int Arr[MAX];
int Tree[MAX * 4];

int init(int Node, int start, int end) {
	if (start == end) return Tree[Node] = Arr[start];

	int mid = (start + end) / 2;
	int left = init(Node * 2, start, mid);
	int right = init(Node * 2 + 1, mid + 1, end);
	return Tree[Node] = left * right;
}

int update(int Node, int start, int end, int index, int value) {
	if (index<start || index>end) return Tree[Node];
	if (start == end) return Tree[Node] = value;

	int mid = (start + end) / 2;
	int left = update(Node * 2, start, mid, index, value);
	int right = update(Node * 2 + 1, mid + 1, end, index, value);
	return Tree[Node] = left * right;
}

int mul(int Node, int start, int end, int left, int right) {
	if (right < start || left > end) return 1;
	if (left <= start && right >= end) return Tree[Node];

	int mid = (start + end) / 2;
	int mleft = mul(Node * 2, start, mid, left, right);
	int mright = mul(Node * 2 + 1, mid + 1, end, left, right);
	return mleft * mright;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, b, c, k;		char a;

	while(cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			if (k > 0) Arr[i] = 1;
			else if (k < 0) Arr[i] = -1;
			else Arr[i] = 0;
		}

		init(1, 0, n - 1);

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			if (a == 'C') {
				if (c > 0) update(1, 0, n - 1, b - 1, 1);
				else if (c < 0) update(1, 0, n - 1, b - 1, -1);
				else update(1, 0, n - 1, b - 1, 0);
			}
			else {
				k = mul(1, 0, n - 1, b - 1, c - 1);
				if (k == 1) cout << "+";
				else if (k == -1) cout << "-";
				else cout << "0";
			}
		}
		cout << "\n";
	}
}