#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visit[8][8];
int board[8][8];
int n, m;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void bfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = 0;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (board[i][j]) {
				visit[i][j] = 1;
				if (board[i][j] == 2) q.push({ i, j });
			}
		}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];

			if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
			if (visit[rr][cc]) continue;

			q.push({ rr, cc });
			visit[rr][cc] = 1;
		}
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (!visit[i][j]) cnt++;
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> board[i][j];
	
	int v1r, v1c, v2r, v2c, v3r, v3c;
	int re = 0;
	for (int i = 0; i < n * m; i++) {
		v1r = i / m;
		v1c = i % m;
		if (board[v1r][v1c]) continue;
		board[v1r][v1c] = 1;
		for (int j = i + 1; j < n * m; j++) {
			v2r = j / m;
			v2c = j % m;
			if (board[v2r][v2c]) continue;
			board[v2r][v2c] = 1;
			for (int k = j + 1; k < n * m; k++) {
				v3r = k / m;
				v3c = k % m;
				if (board[v3r][v3c]) continue;
				board[v3r][v3c] = 1;
 				bfs();
				re = max(re, count());
				board[v3r][v3c] = 0;
			}
			board[v2r][v2c] = 0;
		}
		board[v1r][v1c] = 0;
	}
	cout << re;
}