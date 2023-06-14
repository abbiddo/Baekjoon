#include <iostream>
using namespace std;

int n, res, sr, sc;
int board[500][500];
int dp[500][500];

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int DFS(int r, int c) {
	if (dp[r][c]) return dp[r][c];
	dp[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i];
		int cc = c + dc[i];

		if (rr < 0 || cc < 0 || rr >= n || cc >= n) continue;
		if (board[rr][cc] <= board[r][c]) continue;

		dp[r][c] = max(dp[r][c], DFS(rr, cc) + 1);
	}

	return dp[r][c];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> board[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			sr = i; sc = j;
			res = max(res, DFS(i, j));
		}

	cout << res;
}