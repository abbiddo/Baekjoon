#include <iostream>
#define MOD 1000000000
using namespace std;

long long dp[101][10][1 << 10];

int main() {
	int n, cnt = 0;		cin >> n;
	if (n / 10 == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <10; i++) dp[1][i][1 << i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < (1 << 10); k++)
				dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + 
												((0 < j ? dp[i - 1][j - 1][k] : 0) +
												(j < 9 ? dp[i - 1][j + 1][k] : 0)) % MOD) % MOD;

	for (int i = 0; i < 10; i++) cnt = (cnt + dp[n][i][(1 << 10) - 1]) % MOD;
	cout << cnt;
}