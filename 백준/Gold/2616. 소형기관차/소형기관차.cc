#include <iostream>
#include <algorithm>
using namespace std;

int arr[50001];
int sum[50001];
int dp[4][50001];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    int m;  cin >> m;
    int temp = 0;
    for (int i = 1; i <= m; i++) temp += arr[i];
    sum[m] = temp;

    for (int i = m + 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i] - arr[i - m];

    for (int i = 1; i < 4; i++) 
        for (int j = m; j <= n; j++) 
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + sum[j]);

    cout << dp[3][n];
}