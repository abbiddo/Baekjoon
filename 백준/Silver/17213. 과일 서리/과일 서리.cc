#include <iostream>
using namespace std;

long long dp[31][31];

int n, m;

int main() {
	cin >> n >> m;

	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}

	cout << dp[m - 1][n - 1];
}