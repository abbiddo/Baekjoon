#include <iostream>
using namespace std;

long long dp[101][101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, r;	cin >> n >> l >> r;

	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 1; k + j <= i + 1; k++)
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % 1000000007;

	cout << dp[n][l][r];
}