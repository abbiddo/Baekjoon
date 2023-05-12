#include <iostream>
#include <cmath>
using namespace std;

int arr[1001][2];
int re[1001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;		cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];
	re[1][0] = arr[1][0]; re[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		re[i][0] = arr[i][0] + max(re[i - 1][0] + abs(arr[i - 1][1] - arr[i][1]), 
												re[i - 1][1] + abs(arr[i - 1][0] - arr[i][1]));
		re[i][1] = arr[i][1] + max(re[i - 1][1] + abs(arr[i - 1][0] - arr[i][0]), 
											   re[i - 1][0] + abs(arr[i - 1][1] - arr[i][0]));
	}
	cout << max(re[n][0], re[n][1]);
}