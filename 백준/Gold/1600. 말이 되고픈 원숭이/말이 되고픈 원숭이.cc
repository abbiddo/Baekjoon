#include <iostream>
#include <queue>
using namespace std;

int k, n, m;
int board[200][200];
bool visit[200][200][31];

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int hr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int hc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// 섬(덩어리)을 구분해주기 위한 BFS
void BFS() {
	// <r, c>
	queue<pair<int, pair<int, int>>> q;

	board[0][0] = 1;
	q.push({ 0, { 0, 0 } });

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curr = q.front().second.first;
		int curc = q.front().second.second;
		int cnt = q.front().first;

		q.pop();

		if (cnt < k) {
			for (int i = 0; i < 8; i++) {
				int r = curr + hr[i];
				int c = curc + hc[i];

				// 범위를 벗어나면 continue
				if (r < 0 || c < 0 || r >= n || c >= m) continue;

				if (r == n - 1 && c == m - 1) {
					cout << board[curr][curc];
					return;
				}

				// 벽이 있다면 continue
				if (board[r][c] == -1) continue;

				// 방문한 적이 있다면 continue
				if (visit[r][c][cnt + 1]) continue;

				board[r][c] = board[curr][curc] + 1;
				visit[r][c][cnt + 1] = 1;
				q.push({ cnt + 1, { r, c } });
			}
		}

		for (int i = 0; i < 4; i++) {
			int r = curr + dr[i];
			int c = curc + dc[i];

			// 범위를 벗어나면 continue
			if (r < 0 || c < 0 || r >= n || c >= m) continue;

			if (r == n - 1 && c == m - 1) {
				cout << board[curr][curc];
				return;
			}

			// 벽이 있다면 continue
			if (board[r][c] == -1) continue;

			if (visit[r][c][cnt]) continue;

			board[r][c] = board[curr][curc] + 1;
			visit[r][c][cnt] = 1;
			q.push({ cnt, { r, c } });
		}
	}
	cout << -1;
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> m >> n;
	
	if (m == n && m == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j]) board[i][j] = -1;
		}

	BFS();
}