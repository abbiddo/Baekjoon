#include <iostream>
using namespace std;

int arr[2001];
bool dp[2001][2001];
int n, m;

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
        if (arr[i] == arr[i - 1]) dp[i - 1][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        int k = 1;
        while (i - k > 0 && i + k <= n) {
            if ((arr[i - k] == arr[i + k]) && dp[i - k + 1][i + k - 1]) dp[i - k][i + k] = 1;
            k++;
        }
    }

    for (int i = 1; i < n; i++) {
        int k = 1;
        while (i - k > 0 && i + k + 1 <= n) {
            if ((arr[i - k] == arr[i + k + 1]) && dp[i - k + 1][i + k]) dp[i - k][i + k + 1] = 1;
            k++;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;   cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
}