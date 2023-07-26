#include <iostream>
#include <queue>
using namespace std;

bool complete;
int zeroCnt;
int board[9][9];
pair<int, int> zero[81];

bool check(int r, int c, int n) {
	for (int i = 0; i < 9; i++)
		if (board[r][i] == n || board[i][c] == n) return false;

	for (int i = r / 3 * 3; i < r / 3 * 3 + 3; i++)
		for (int j = c / 3 * 3; j < c / 3 * 3 + 3; j++)
			if (board[i][j] == n) return false;

	return true;
}

void sudoku(int cnt) {
	if (cnt == zeroCnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j];
			cout << "\n";
		}
		complete = true;
		return;
	}

	int r = zero[cnt].first;
	int c = zero[cnt].second;

	for (int i = 1; i <= 9; i++) {
		if (check(r, c, i)) {
			board[r][c] = i;
			sudoku(cnt + 1);
		}
		if (complete) return;
	}

	board[r][c] = 0;
}

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	for (int i = 0; i < 9; i++) {
		cin >> s;
		for (int j = 0; j < 9; j++) {
			board[i][j] = s[j] - '0';
			if (board[i][j] == 0) zero[zeroCnt++] = { i, j };
		}
	}

	sudoku(0);
}