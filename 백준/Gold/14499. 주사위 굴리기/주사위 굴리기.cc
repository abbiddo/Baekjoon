#include <iostream>
using namespace std;

int n, m, r, c, k;
int arr[6];
int board[20][20];

int main() {
	cin >> n >> m >> r >> c >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> board[i][j];

	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		if (a == 1) {
			if (c + 1 == m) continue;
			c++;
			int tmp = arr[3];
			arr[3] = arr[2];
			arr[2] = arr[1];
			arr[1] = arr[5];
			arr[5] = tmp;
		}
		
		if (a == 2) {
			if (c == 0) continue;
			c--;
			int tmp = arr[1];
			arr[1] = arr[2];
			arr[2] = arr[3];
			arr[3] = arr[5];
			arr[5] = tmp;
		}
	
		if (a == 3) {
			if (r == 0) continue;
			r--;
			int tmp = arr[0];
			arr[0] = arr[2];
			arr[2] = arr[4];
			arr[4] = arr[5];
			arr[5] = tmp;
		}

		if (a == 4) {
			if (r + 1 == n) continue;
			r++;
			int tmp = arr[5];
			arr[5] = arr[4];
			arr[4] = arr[2];
			arr[2] = arr[0];
			arr[0] = tmp;
		}

		if (board[r][c] == 0) board[r][c] = arr[5];
		else {
			arr[5] = board[r][c];
			board[r][c] = 0;
		}
		cout <<arr[2] << "\n";
	}
}