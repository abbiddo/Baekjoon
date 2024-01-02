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
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			arr[i][j] = -1;
		}
    
	while (k--) {
		int r, c;	cin >> r >> c;
		r--;
		c--;

		if (arr[r][c] >= 0) {
			cout << arr[r][c] << "\n";
			continue;
		}

		int mi = 250;
		int ma = 0;

		for (int ii = r; ii < r + b; ii++) {
			for (int jj = c; jj < c + b; jj++) {
				mi = min(mi, board[ii][jj]);
				ma = max(ma, board[ii][jj]);
			}
		}

		arr[r][c] = ma - mi;

		cout << ma- mi << "\n";
	}
}