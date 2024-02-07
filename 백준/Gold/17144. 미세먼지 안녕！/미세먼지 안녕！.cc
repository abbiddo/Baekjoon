#include <iostream>
using namespace std;

int n, m, t, dir;
int arr[50][50];
int temp[50][50];
int gr = -1, gc = -1;

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				gr = i;
		}

	while (t--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > 0) {
					int tmp = arr[i][j] / 5;

					for (int k = 0; k < 4; k++) {
						int r = i + dr[k];
						int c = j + dc[k];

						if (r < 0 || c < 0 || r >= n || c >= m) continue;
						if (arr[r][c] == -1) continue;

						temp[r][c] += tmp;
						temp[i][j] -= tmp;
					}
				}
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] += temp[i][j];

		for (int i = gr + 2; i < n; i++) 
			arr[i - 1][0] = arr[i][0];

		for (int i = 1; i < m; i++) 
			arr[n - 1][i - 1] = arr[n - 1][i];

		for (int i = n - 1; i > gr; i--)
			arr[i][m - 1] = arr[i - 1][m - 1];

		for (int i = m - 1; i > 1; i--)
			arr[gr][i] = arr[gr][i - 1];



		for (int i = gr - 2; i > 0; i--)
			arr[i][0] = arr[i - 1][0];

		for (int i = 1; i < m; i++)
			arr[0][i - 1] = arr[0][i];

		for (int i = 0; i < gr - 1; i++)
			arr[i][m - 1] = arr[i + 1][m - 1];

		for (int i = m - 1; i > 1; i--)
			arr[gr - 1][i] = arr[gr - 1][i - 1];

		arr[gr][1] = 0;
		arr[gr - 1][1] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				temp[i][j] = 0;
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res += arr[i][j];

	cout << res + 2;

}