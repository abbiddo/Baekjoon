#include <iostream>
using namespace std;

int n, m;
int dp[101][100001];
pair<int, int> thing[101];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a, b;	cin >> a >> b;
		thing[i] = { a, b };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (thing[i].first > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - thing[i].first] + thing[i].second);
		}
	}

	cout << dp[n][m];
}