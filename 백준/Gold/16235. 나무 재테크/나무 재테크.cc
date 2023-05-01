#include <iostream>
#include <algorithm>
using namespace std;

int k, n, m;
int tree[10][10][2002];
int arr[10][10];
int bab[10][10];

// 
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			bab[i][j] = 5;
		}

	for (int i = 0; i < m; i++) {
		int r, c, a;	cin >> r >> c >> a;
		tree[r - 1][c - 1][0] = 1;
		tree[r - 1][c - 1][1] = a;
	}

	for (int i = 0; i < k; i++) {
		// 봄
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				if (tree[r][c][0]) {
					if (tree[r][c][0] > 1)	sort(tree[r][c] + 1, tree[r][c] + tree[r][c][0] + 1);
					/*if (i < 10) {
						for (int g = 0; g <= tree[r][c][0]; g++) cout << tree[r][c][g] << " ";
						cout << "\n";
					}*/
					tree[r][c][2001] = 1;
					for (int j = 1; j <= tree[r][c][0]; j++) {
						if (bab[r][c] >= tree[r][c][j]) {
							bab[r][c] -= tree[r][c][j];
							tree[r][c][j]++;
							tree[r][c][2001] = j + 1;
						}
						else break;
					}
				}

		// 여름
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				if (tree[r][c][0]) {
					int cnt = tree[r][c][0];
					for (int j = tree[r][c][2001]; j <= cnt; j++) {
						bab[r][c] += tree[r][c][j] / 2;
						tree[r][c][j] = 0;
						tree[r][c][0]--;
					}
				}

		// 가을
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				if (tree[r][c][0]) {
					for (int j = 1; j <= tree[r][c][0]; j++) {
						if (tree[r][c][j] % 5 == 0) {
							for (int l = 0; l < 8; l++) {
								int rr = r + dr[l];
								int cc = c + dc[l];

								if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;

								tree[rr][cc][0]++;
								tree[rr][cc][tree[rr][cc][0]] = 1;
							}
						}
					}
				}

		// 겨울
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				bab[r][c] += arr[r][c];
	}

	int re = 0;
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			re += tree[r][c][0];

	cout << re;
}