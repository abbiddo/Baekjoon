#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[502][502];
int dp[502][502];

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int dfs(int r, int c) {
	if (r == n && c == m) return 1;
	if (dp[r][c] != -1) return dp[r][c];
	else {
		dp[r][c] = 0;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (arr[r][c] <= arr[nr][nc]) continue;

			dp[r][c] += dfs(nr, nc);

		}
	}
	return dp[r][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(1, 1);
}