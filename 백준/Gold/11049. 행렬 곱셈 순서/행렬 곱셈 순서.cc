#include <iostream>
#include <climits>
using namespace std;

int n;	
int dp[501][501];
pair<int, int> arr[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;	cin >> x >> y;
		arr[i] = { x, y };
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < n; i++) 
		for (int j = 1; i + j <= n; j++) {
			dp[j][i + j] = INT_MAX;
			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[j].first * arr[k].second * arr[i + j].second);
			}
		}

	cout << dp[1][n];
}