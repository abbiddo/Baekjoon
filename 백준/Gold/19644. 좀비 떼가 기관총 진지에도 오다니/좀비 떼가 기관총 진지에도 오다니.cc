#include <iostream>
#include <queue>
using namespace std;

int n, g, gc, c, cc;
int arr[3000001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> g >> gc >> c;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cc = c;

	if (n <= c) {
		cout << "YES";
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (q.size() && q.front() == i) {
			c--;
			q.pop();
		}

		if (!arr[i]) continue;

		int him = gc * (g - (c - cc));
		if (i < g) him = gc * (i - (c - cc));

		if (arr[i] > him) {
			if (cc) {
				cc--;
				q.push(i + g);
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}