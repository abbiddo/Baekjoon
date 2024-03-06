#include <iostream>
using namespace std;

int n, m, rr, rc;
int arr[1000][1000];

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int d = 0;
	int r = 1;
	int c = 1;

	for (int i = n * n; i > 0; i--) {
		if (i == m) {
			rr = r;
			rc = c;
		}
		arr[r][c] = i;
		r += dr[d];
		c += dc[d];

		if (r <= 0 || c <= 0 || r > n || c > n || arr[r][c]) {
			r -= dr[d];
			c -= dc[d];
			d = (d + 1) % 4;
			r += dr[d];
			c += dc[d];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}

	cout << rr << " " << rc;
}