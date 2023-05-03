#include <iostream>
#include <algorithm>
using namespace std;

pair<int ,int> arr[501];
int dp[501];
int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;   cin >> a >> b;
        arr[i] = { a,b };
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[j].second < arr[i].second) dp[i] = max(dp[i], dp[j] + 1);
        cnt = max(cnt, dp[i]);
    }

    cout << n - cnt;
}