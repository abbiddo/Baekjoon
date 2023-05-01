#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int board[300][300];
int visit[300][300];
// 상하좌우 탐색을 위함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int r, int c) {
	// <r, c>
	queue<pair<int, int>> q;

	visit[r][c] = 1;
	q.push({ r, c });
	
	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curr = q.front().first;
		int curc = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = curr + dx[i];
			int yy = curc + dy[i];

			// 범위를 벗어나거나 방문한 적 있으면 continue
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (visit[xx][yy]) continue;

			if (board[xx][yy] == 0)
				board[curr][curc] -= 1;

			else {
				q.push({ xx, yy });
				visit[xx][yy] = 1;
			}

			if (board[curr][curc] < 0) board[curr][curc] = 0;
		}
	}
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int cnt = 0;
	while (1) {
		memset(visit, false, sizeof(visit));
		int bfs = 0;
		for (int i = 0 ; i < n;i++)
			for (int j = 0; j < m; j++) {
				if (board[i][j] && !visit[i][j]) {
					BFS(i ,j);
					bfs++;
				}
			}

		if (bfs > 1) {
			cout << cnt;
			return 0;
		}
		else if (bfs == 0) {
			cout << 0;
			return 0;
		}

		cnt++;
	}
}