#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
	int n;	cin >> n;

	for (int i = 1; i <= n; i++) 
		cin >> arr[i] >> arr[i] >> arr[i];

	dp[0] = 0;
	dp[1] = arr[1];

	for (int i = 2; i <= n; i++) dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);

	cout << dp[n];
}
