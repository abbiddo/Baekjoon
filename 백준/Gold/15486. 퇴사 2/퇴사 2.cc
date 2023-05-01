#include <iostream>
using namespace std;

int arr[1500001][2];
int dp[1500001];

int main() {
	int n;		cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

	for (int i = n; i > 0; i--) {
		if (arr[i][0] + i > n + 1) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], dp[arr[i][0] + i] + arr[i][1]);
	}

	cout << dp[1];
}