#include <iostream>
using namespace std;

int color, res = 26;
int board[10][10];
int paperSize[6] = { 0, 5, 5, 5, 5, 5 };

bool check() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (board[i][j]) return false;
	return true;
}

bool square(int r, int c, int i) {
	if (r + i > 10 || c + i > 10) return false;

	for (int k = r; k < r + i; k++)
		for (int j = c; j < c + i; j++)
			if (board[k][j] == 0) return false;
	return true;
}

void paper() {
	if (check()) {
		int sum = 0;
		for (int i = 1; i <= 5; i++) sum += (5 - paperSize[i]);
		res = min(res, sum);
		return;
	}

	int temp[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) temp[i][j] = board[i][j];

	int r = 10, c = 10;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j]) {
				r = i;
				c = j;
				break;
			}
		}
		if (r != 10) break;
	}

	for (int i = 1; i <= 5; i++) {
		if (paperSize[i] == 0) continue;
		if (square(r, c, i)) {
			for (int k = r; k < r + i; k++)
				for (int j = c; j < c + i; j++) board[k][j] = 0;
			paperSize[i]--;

			paper();

			for (int k = 0; k < 10; k++)
				for (int j = 0; j < 10; j++) board[k][j] = temp[k][j];
			paperSize[i]++;
		}
	}
}

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) color++;
		}
	}

	paper();
	if (res == 26) cout << -1;
	else cout << res;
}