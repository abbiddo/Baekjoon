#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000][1000];
int dp[1000][1000];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;  cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (i == 0 || j == 0) {
                if (arr[i][j] == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
    
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            if (arr[i][j]) {
                dp[i][j] = 0;
                continue;
            }

            if (arr[i - 1][j] || arr[i][j - 1] || arr[i - 1][j - 1]) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }

    int re = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) re = max(re, dp[i][j]);
        
    cout << re;
}