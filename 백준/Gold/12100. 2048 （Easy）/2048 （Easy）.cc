#include <iostream>
#include <vector>
using namespace std;

int n, res;
int board[21][21];

int count() {
	int ma = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			ma = max(ma, board[i][j]);
	return ma;
}

void move(int d) {
	bool flag = false;
	if (d == 0){
		for (int i = 1; i <= n; i++) {
			int index = 1;
			for (int j = 1; j <= n; j++) {
				if (board[j][i]) {
					if (board[j][i] == board[index - 1][i] && flag) {
						board[j][i] = 0;
						board[index - 1][i] *= 2;
						flag = false;
					}
					else {
						int tmp = board[j][i];
						board[j][i] = 0;
						board[index++][i] = tmp;
						flag = true;
					}
				} 
			}
		}
	}

	else if (d == 1) {
		for (int i = n; i > 0; i--) {
			int index = n;
			for (int j = n; j > 0; j--) {
				if (board[i][j]) {
					if (board[i][j] == board[i][index + 1] && flag) {
						board[i][j] = 0;
						board[i][index + 1] *= 2;
						flag = false;
					}
					else {
						int tmp = board[i][j];
						board[i][j] = 0;
						board[i][index--] = tmp;
						flag = true;
					}
				}
			}
		}
	}

	else if (d == 2) {
		for (int i = n; i > 0; i--) {
			int index = n;
			for (int j = n; j > 0; j--) {
				if (board[j][i]) {
					if (board[j][i] == board[index + 1][i] && flag) {
						board[j][i] = 0;
						board[index + 1][i] *= 2;
						flag = false;
					}
					else {
						int tmp = board[j][i];
						board[j][i] = 0;
						board[index--][i] = tmp;
						flag = true;
					}
				}
			}
		}
	}

	else {
		for (int i = 1; i <= n; i++) {
			int index = 1;
			for (int j = 1; j <= n; j++) {
				if (board[i][j]) {
					if (board[i][j] == board[i][index - 1] && flag) {
						board[i][j] = 0;
						board[i][index - 1] *= 2;
						flag = false;
					}
					else {
						int tmp = board[i][j];
						board[i][j] = 0;
						board[i][index++] = tmp;
						flag = true;
					}
				}
			}
		}
	}
}

void game(int cnt) {
	if (cnt == 5) {
		res = max(res, count());
		return;
	}

	int temp[21][21];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) temp[i][j] = board[i][j];

	for (int i = 0; i < 4 ; i++) {
		move(i);
		game(cnt + 1);
		for (int k = 1; k <= n; k++)
			for (int j = 1; j <= n; j++) board[k][j] = temp[k][j];
	}
}

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			cin >> board[i][j];

	game(0);
	cout << res;
}