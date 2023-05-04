#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dr[9] = { -1, 0, 1, 0, -1, -1, 1, 1, 0 };
int dc[9] = { 0, 1, 0, -1,-1, 1, -1, 1, 0 };

char board[8][8];

queue<pair<int, int>> q;

void wall() {
	for (int i = 0; i < 8; i++) board[7][i] = '.';
	for (int i = 6; i >= 0; i--) 
		for (int j = 0; j < 8; j++) 
			if (board[i][j] == '#') {
				board[i][j] = '.';
				board[i + 1][j] = '#';
			}
}

bool bfs(int size) {
	for (int t = 0; t < size; t++) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 9; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (rr < 0 || rr > 7 || cc < 0 || cc > 7) continue;
			if (board[rr][cc] == '#') continue;
			if (i == 8) q.push({ rr, cc });

			if (rr == 0 && cc == 7) return true;
			q.push({ rr, cc });
		}
	}
	wall();

	int qsize = q.size();
	for (int i = 0; i < qsize; i++) {
		pair<int, int> rc = q.front();
		q.pop();

		if (board[rc.first][rc.second] != '#') q.push(rc);
	}
	return false;
}
int main() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) cin >> board[i][j];

	q.push({ 7, 0 });

	while (!q.empty()) {
		if (bfs(q.size())) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
}