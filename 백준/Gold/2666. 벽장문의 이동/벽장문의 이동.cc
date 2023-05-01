#include <iostream>
#include <string>
using namespace std;

int dp[21][21][21];
int arr[21];
int op, en;


int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;		cin >> n >> op >> en;
	int m;	cin >> m;

	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++) dp[i][j][k] = 1000000;
	
	for (int i = 0; i < m; i++) cin >> arr[i];

	dp[0][op][en] = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[i][j][k] != 1000000) {
					if (j == arr[i] || k == arr[i]) dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
					else if (j > arr[i]) dp[i + 1][arr[i]][k] = min(dp[i + 1][arr[i]][k], dp[i][j][k] + abs(arr[i] - j));
					else if (k < arr[i]) dp[i + 1][j][arr[i]] = min(dp[i + 1][j][arr[i]], dp[i][j][k] + abs(arr[i] - k));
					else {
						dp[i + 1][arr[i]][k] = min(dp[i + 1][arr[i]][k], dp[i][j][k] + abs(arr[i] - j));
						dp[i + 1][j][arr[i]] = min(dp[i + 1][j][arr[i]], dp[i][j][k] + abs(arr[i] - k));
					}
				}
			}
		}
	}

	int re = 1000000;
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= n; k++) {
			if (j == arr[m - 1] || k == arr[m - 1]) re = min(re, dp[m][j][k]);
		}
	}
	cout << re;
}