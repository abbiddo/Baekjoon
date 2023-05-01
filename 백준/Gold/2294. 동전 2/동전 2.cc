#include <iostream>
using namespace std;

int arr[100];
int dp[100001];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}

	for (int i = 1; i <= k; i++) {
		if (dp[i] == 1) continue;
		dp[i] = 1000000;
		for (int j = 0; j < n; j++) {
			if (i - arr[j] < 1) continue;
			if (!dp[i - arr[j]]) continue;

			dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}
		if (dp[i] == 1000000) dp[i] = 0;
	}

	if (dp[k]) cout << dp[k];
	else cout << -1;
}