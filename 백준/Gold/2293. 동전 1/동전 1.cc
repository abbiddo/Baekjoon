#include <iostream>
using namespace std;
int dp[100001] = { 1 };
int arr[101];
int main() {
	int a, n;
	cin >> n >> a;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) 
		for (int j = arr[i]; j <= a; j++) 
			dp[j]+=dp[j-arr[i]];
	cout << dp[a];
}