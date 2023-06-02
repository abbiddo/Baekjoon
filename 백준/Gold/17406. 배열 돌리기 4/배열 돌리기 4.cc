#include <iostream>
using namespace std;

int n, m, r, res = 5000;
int visit[6];
int rotat[6][3];
int board[50][50];

void ratation(int width) {
	int tmp;
	int rr = rotat[width][0] - 1;
	int cc = rotat[width][1] - 1;
	int s = rotat[width][2];

	for (int i = 1; i <= s; i++) {
		tmp = board[rr - i][cc - i];
		for (int j = rr - i; j < rr + i; j++) board[j][cc - i] = board[j + 1][cc - i];
		for (int j = cc - i; j < cc + i; j++) board[rr + i][j] = board[rr + i][j + 1];
		for (int j = rr + i; j > rr - i; j--) board[j][cc + i] = board[j - 1][cc + i];
		for (int j = cc + i; j > cc - i; j--) board[rr - i][j] = board[rr - i][j - 1];
		board[rr - i][cc - i + 1] = tmp;
	}
}

void permutation(int cnt) {
	if (cnt == r) {
		int sum;
		for (int i = 0; i < n; i++) {
			sum = 0;
			for (int j = 0; j < m; j++) sum += board[i][j];
			res = min(res, sum);
		}
		return;
	}

	int temp[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) temp[i][j] = board[i][j];

	for (int i = 0; i < r; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ratation(i);
			
			permutation(cnt + 1);

			visit[i] = false;
			for (int k = 0; k < n; k++)
				for (int j = 0; j < m; j++) board[k][j] = temp[k][j];
		}
	}
}

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> board[i][j];

	for (int i = 0; i < r; i++)
		cin >> rotat[i][0] >> rotat[i][1] >> rotat[i][2];

	permutation(0);
	cout << res;
}