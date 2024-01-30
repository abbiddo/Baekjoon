#include <iostream>
#include <stack>
using namespace std;

int n, m, deep;
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int k;	cin >> k;
		if (s.size() && s.top() < k) k = s.top();
		s.push(k);
	}

	for (int i = 0; i < m; i++) {
		int a;	cin >> a;
		while (s.size() && s.top() < a) s.pop();
		if (s.size()) s.pop();
		else {
			cout << 0;
			return 0;
		}
	}
	cout << s.size() + 1;
}