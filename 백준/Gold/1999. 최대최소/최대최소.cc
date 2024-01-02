#include <iostream>
using namespace std;

int n, b, k;
int board[250][250];
int arr[250][250];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> b >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> board[i][j];

	for (int i = 0; i <= n - b; i++) {
		for (int j = 0; j <= n - b; j++) {
			int mi = 250;
			int ma = 0;
			for (int ii = i; ii < i + b; ii++) {
				for (int jj = j; jj < j + b; jj++) {
					mi = min(mi, board[ii][jj]);
					ma = max(ma, board[ii][jj]);
				}
			}
			arr[i][j] = ma - mi;
		}
	}


	while (k--) {
		int r, c;	cin >> r >> c;
		cout << arr[r - 1][c - 1] << "\n";
	}
}