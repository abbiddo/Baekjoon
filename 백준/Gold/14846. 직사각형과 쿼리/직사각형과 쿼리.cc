#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[301][301];
int sumsum[301][301][11];

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= 10; k++) {
				sumsum[i][j][k] = (sumsum[i - 1][j][k]
					+ sumsum[i][j - 1][k]
					- sumsum[i - 1][j - 1][k]);
				sumsum[i][j][arr[i][j]]++;
			}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;	cin >> a >> b >> c >> d;
		int cnt = 0, res[11] = { 0 };

		for (int k = 1; k <= 10; k++) {
			res[k] = (sumsum[c][d][k]
				- sumsum[a - 1][d][k]
				- sumsum[c][b - 1][k]
				+ sumsum[a - 1][b - 1][k]);
		}

		for (int k = 1; k <= 10; k++)
			if (res[k]) cnt++;
		cout << cnt << "\n";
	}
}