#include <iostream>
using namespace std;

int n, m, res = 64;
int cctvCnt, fiveCnt;
int board[8][8];
int rotation[5] = { 0, 4, 2, 4, 4 };
pair<int, pair<int, int>> cctv[8];
pair<int, int> five[8];

void UP(int cnt) {
	int r = cctv[cnt].second.first;
	int c = cctv[cnt].second.second;

	for (int j = r - 1; j >= 0; j--) {
		if (board[j][c] == 6) break;
		if (board[j][c]) continue;
		board[j][c] = 9;
	}
}

void RIGHT(int cnt) {
	int r = cctv[cnt].second.first;
	int c = cctv[cnt].second.second;

	for (int j = c + 1; j < m; j++) {
		if (board[r][j] == 6) break;
		if (board[r][j]) continue;
		board[r][j] = 9;
	}
}

void DOWN(int cnt) {
	int r = cctv[cnt].second.first;
	int c = cctv[cnt].second.second;

	for (int j = r + 1; j < n; j++) {
		if (board[j][c] == 6) break;
		if (board[j][c]) continue;
		board[j][c] = 9;
	}
}

void LEFT(int cnt) {
	int r = cctv[cnt].second.first;
	int c = cctv[cnt].second.second;

	for (int j = c - 1; j >= 0; j--) {
		if (board[r][j] == 6) break;
		if (board[r][j]) continue;
		board[r][j] = 9;
	}
}

int blind() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 0) cnt++;
	return cnt;
}

void watch(int cnt) {
	if (cnt == cctvCnt) {
		res = min(res, blind());
		return;
	}

	int tmp[9][9];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) tmp[i][j] = board[i][j];

	for (int i = 1; i <= rotation[cctv[cnt].first]; i++) {
		if (cctv[cnt].first == 1) {
			if (i == 1) UP(cnt);
			else if (i == 2) RIGHT(cnt);
			else if (i == 3) DOWN(cnt);
			else if (i == 4) LEFT(cnt);
		}

		else if (cctv[cnt].first == 2) {
			if (i == 1) {
				UP(cnt);
				DOWN(cnt);
			}
			else {
				RIGHT(cnt);
				LEFT(cnt);
			}
		}

		else if (cctv[cnt].first == 3) {
			if (i == 1) {
				UP(cnt);
				RIGHT(cnt);
			}
			else if (i == 2) {
				RIGHT(cnt);
				DOWN(cnt);
			}
			else if (i == 3) {
				DOWN(cnt);
				LEFT(cnt);
			}
			else {
				LEFT(cnt);
				UP(cnt);
			}
		}

		else {
			if (i == 1) {
				UP(cnt);
				RIGHT(cnt);
				DOWN(cnt);
			}
			else if (i == 2) {
				RIGHT(cnt);
				DOWN(cnt);
				LEFT(cnt);
			}
			else if (i == 3) {
				DOWN(cnt);
				LEFT(cnt);
				UP(cnt);
			}
			else {
				LEFT(cnt);
				UP(cnt);
				RIGHT(cnt);
			}
		}

		watch(cnt + 1);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) board[i][j] = tmp[i][j];
	}
}

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] < 5)
				cctv[cctvCnt++] = { board[i][j], {i, j} };
			if (board[i][j] == 5) five[fiveCnt++] = { i, j };
		}
	}

	for (int i = 0; i < fiveCnt; i++) {
		for (int j = five[i].second; j < m; j++) {
			if (board[five[i].first][j] == 6) break;
			if (board[five[i].first][j]) continue;
			board[five[i].first][j] = 9;
		}

		for (int j = five[i].second; j >=0; j--) {
			if (board[five[i].first][j] == 6) break;
			if (board[five[i].first][j]) continue;
			board[five[i].first][j] = 9;
		}

		for (int j = five[i].first; j < n; j++) {
			if (board[j][five[i].second] == 6) break;
			if (board[j][five[i].second]) continue;
			board[j][five[i].second] = 9;
		}

		for (int j = five[i].first; j >=0; j--) {
			if (board[j][five[i].second] == 6) break;
			if (board[j][five[i].second]) continue;
			board[j][five[i].second] = 9;
		}
	}

	watch(0);
	cout << res;
}