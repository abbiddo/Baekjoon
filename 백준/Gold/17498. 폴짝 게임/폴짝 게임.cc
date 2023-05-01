#include <iostream>
#include <limits>
using namespace std;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, d;	cin >> n >> m >> d;

	int** arr = new int* [n];
	int** dp = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		dp[i] = new int[m];
	}

	fill(dp[0], dp[0] + m, 0);
	for (int i = 1; i < n; i++) fill(dp[i], dp[i] + m, numeric_limits<int>::min());

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k <= d; k++) {
				for (int l = 1; l <= k; l++) {
					int r = i - l;
					int c1 = j - (k - l);
					int c2 = j + (k - l);

					if (r < 0) continue;

					if (c1 >= 0) dp[i][j] = max(dp[i][j], dp[r][c1] + arr[r][c1] * arr[i][j]);
					if (c2 < m) dp[i][j] = max(dp[i][j], dp[r][c2] + arr[r][c2] * arr[i][j]);
				}
			}
		}
	}

	int re = numeric_limits<int>::min();
	for (int i = 0; i < m; i++)
		re = max(re, dp[n - 1][i]);

	cout << re;
}