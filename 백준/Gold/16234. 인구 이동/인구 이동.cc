#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, l, r;
int board[50][50];
int visit[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> save;

	q.push({ x, y });
	visit[x][y] = 1;
	int sum = board[x][y];
	int cnt = 1;

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;

		q.pop();
		save.push({ curx, cury });

		for (int i = 0; i < 4; i++) {
			int xx = curx + dx[i];
			int yy = cury + dy[i];

			if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
			if (visit[xx][yy]) continue;

			int gap = abs(board[curx][cury] - board[xx][yy]);
			if (gap <= r && gap >= l) {
				q.push({ xx, yy });
				visit[xx][yy] = 1;
				cnt++;
				sum += board[xx][yy];
			}
		}
	}

	if (cnt == 1) return 0;

	while (!save.empty()) {
		int people = sum / cnt;
		int curx = save.front().first;
		int cury = save.front().second;

		save.pop();

		board[curx][cury] = people;
	}

	return cnt;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> board[i][j];

	int cnt = 0;
	while (1) {
		int a = -1;
		int k = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!visit[i][j]) a = BFS(i, j);
				if (!a) k++;
			}
		if (k == n * n) break;
		cnt++;
	}

	cout << cnt;
}