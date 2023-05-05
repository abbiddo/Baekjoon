#include <iostream>
#include <stack>
using namespace std;

int arr[1000];
int dp[1000];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;		cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int ma = 0, madp = 0;
	for (int i = 0; i < n; i++) {
		if (madp < dp[i]) {
			madp = dp[i];
			ma = i;
		}
	}
	cout << madp << "\n";

	int index = madp;
	for (int i = ma; i >= 0; i--)
		if (dp[i] == index) {
			s.push(arr[i]);
			index--;
		}

	for (int i = 0; i < madp; i++) {
		cout << s.top() << " ";
		s.pop();
	}

}