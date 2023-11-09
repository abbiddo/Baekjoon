#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int arr[100000];
int dp[100000][2];

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i][0] = arr[i];
		dp[i][1] = arr[i];
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
	}

	int res = INT_MIN;
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i][0]);
		res = max(res, dp[i][1]);
	}
	cout << res;

}