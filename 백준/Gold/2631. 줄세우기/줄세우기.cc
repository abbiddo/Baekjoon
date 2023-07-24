#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
int arr[200];
int dp[200];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) 
			if (arr[i] > arr[j]) 
				dp[i] = max(dp[i], dp[j] + 1);
		res = max(res, dp[i]);
	}
	cout << n - res;
}