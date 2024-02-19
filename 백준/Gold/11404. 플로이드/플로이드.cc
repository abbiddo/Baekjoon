#include <iostream>
using namespace std;

int n, m;
int arr[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int r = 1; r <= n; r++) 
		for (int c = 1; c <= n; c++) 
			arr[r][c] = 987654321;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}

	for (int i = 1; i <= n; i++) {
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				arr[r][c] = min(arr[r][c], arr[r][i] + arr[i][c]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 987654321 || i == j) cout << 0<<" ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
