#include <iostream>
using namespace std;

int n, m;
int dp[1001][1001];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) dp[i][1] = i;

	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j / 2 >= i) dp[j][i] = (dp[j - 1][i] + dp[j - 2][i - 1])%1000000003;
		}
	}

	cout << dp[n][m];
}