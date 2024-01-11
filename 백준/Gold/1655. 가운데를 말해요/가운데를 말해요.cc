#include <iostream>
#include <queue>
using namespace std;

int n, res;
priority_queue<int> small;
priority_queue<int, vector<int>, greater<int>> big;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> res;
	cout << res << "\n";

	for (int i = 2; i <= n; i++) {
		int a;	cin >> a;
		if (i % 2 == 0) {
			if (res > a) {
				big.push(res);
				res = a;

				if (small.size() && small.top() > res) {
					small.push(res);
					res = small.top();
					small.pop();
				}

			}
			else big.push(a);
		}
		else {
			if (res < a) {
				small.push(res);
				res = a;

				if (big.size() && big.top() < res) {
					big.push(res);
					res = big.top();
					big.pop();
				}

			}
			else small.push(a);
		}
		cout << res << "\n";;
	}

}