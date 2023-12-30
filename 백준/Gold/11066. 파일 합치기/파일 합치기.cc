#include <iostream>
#include <climits>
using namespace std;

int t, n;
int arr[501];
int dp[501][501];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= n; j++) dp[i][j] = INT_MAX;

		for (int i = 1; i <= n; i++) {
			cin >> dp[0][i];
			arr[i] = arr[i - 1] + dp[0][i];
		}

		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j >= i) {
					int tmp = arr[j] - arr[j - i];

					for (int k = i - 1; k > 0; k--) {
						dp[i][j] = min(dp[i][j], tmp + dp[k][j] + dp[i - k][j - k]);
					}
				}
			}
		}
		cout << dp[n][n] << "\n";
	}

}