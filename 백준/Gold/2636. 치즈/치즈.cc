#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, cnt;
int board[100][100];
int visit[100][100];
// 상하좌우 탐색을 위함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS() {
	int ccnt = 0;
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	visit[0][0] = 1;
	
	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;

		q.pop();

		// 상하좌우 4방향 이동을 위함
		for (int i = 0; i < 4; i++) {
			int xx = curx + dx[i];
			int yy = cury + dy[i];

			// 범위를 벗어나면 continue
			if (xx >= n || xx < 0 || yy >= m || yy < 0) continue;
			if (visit[xx][yy]) continue;

			if (!board[xx][yy]) {
				q.push({ xx, yy });
				visit[xx][yy] = 1;
			}
			// 값이 존재하지 않으면 바이러스가 이동
			else if (board[xx][yy]) {
				board[xx][yy] = 0;
				visit[xx][yy] = 1;
				ccnt++;
			}
		}
	}
	return ccnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> board[i][j];

	int cheese, before;
	while (1) {
		memset(visit, false, sizeof(visit));
		cheese = BFS();
		cnt++;

		if (!cheese) {
			cout << cnt - 1 << "\n" << before;
			break;
		}

		before = cheese;
	}
}