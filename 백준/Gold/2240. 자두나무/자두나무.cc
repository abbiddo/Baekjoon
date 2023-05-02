#include <iostream>
using namespace std;

int dp[3][1001][31];
int arr[1001] = { 1 };
int n, m;

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (arr[i - 1] == 1) {
                if (j == 0) dp[1][i][j] = dp[1][i - 1][j] + 1;
                else {
                    dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]) + 1;
                    dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);
                }
            }
            else {
                if (j == 0) dp[1][i][j] = dp[1][i - 1][j];
                else {
                    dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]);
                    dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]) + 1;
                }
            }
        }
    }

    int re = 0;
    for (int i = 0; i <= m; i++) re = max(re, max(dp[1][n][i], dp[2][n][i]));
    cout << re;
}