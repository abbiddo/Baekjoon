#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int a[1501][1501];
int b[1501][1501];
int apple[1501][1501];
int banana[1501][1501];
int dp[1501][1501];

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char x; int n;
			cin >> x >> n;
			if (x == 'A') a[i][j] = n;
			else b[i][j] = n;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			apple[i][j] = apple[i - 1][j] + a[i][j];
			banana[i][j] = banana[i - 1][j] + b[i][j];
		}

	for (int i = 1; i <= n; i++) dp[i][1] = apple[n][1] - apple[i][1];
	for (int i = 1; i <= m; i++) dp[1][i] = dp[1][i - 1] + apple[n][i] - apple[1][i];

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j] - (apple[i][j] - apple[i - 1][j]));
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + banana[i - 1][j] + (apple[n][j] - apple[i][j]));
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + banana[i - 1][j] + (apple[n][j] - apple[i][j]));
		}
	}
	cout << dp[n][m];
}