#include <iostream>
#include <climits>
using namespace std;

int n, m;
int arr[1001][1001];
int dpLeft[1002][1002];
int dpRight[1002][1002];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> arr[i][j];

	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++) {
			dpLeft[i][j] = INT_MIN + 100000;
			dpRight[i][j] = INT_MIN + 100000;
		}

	dpLeft[1][1] = dpRight[1][1] = arr[1][1];
	for (int i = 2; i <= m; i++) {
		dpLeft[1][i] = dpLeft[1][i - 1] + arr[1][i];
		dpRight[1][i] = dpRight[1][i - 1] + arr[1][i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = m; j > 0; j--)
			dpLeft[i][j] = max(dpLeft[i - 1][j], dpLeft[i][j + 1]) + arr[i][j];
		for (int j = 1; j <= m; j++)
			dpRight[i][j] = max(dpRight[i - 1][j], dpRight[i][j - 1]) + arr[i][j];
		for (int j = 1; j <= m; j++) {
			dpLeft[i][j] = max(dpLeft[i][j], dpRight[i][j]);
			dpRight[i][j] = dpLeft[i][j];
		}
	}
	cout << dpLeft[n][m];
}