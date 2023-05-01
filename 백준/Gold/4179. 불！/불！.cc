#include <iostream>
#include <queue>
using namespace std;

int n, m;
char board[1000][1000];
bool pisit[1000][1000];
bool fisit[1000][1000];
// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };


queue<pair<int, int>> pq;
queue<pair<int, int>> fq;

void BFS() {
	int cnt = 0;

	// 큐가 빌 때까지 반복
	while (!pq.empty()) {
		cnt++;

		int fize = fq.size();
		int pize = pq.size();

		for (int i = 0; i < fize; i++) {
			int fr = fq.front().first;
			int fc = fq.front().second;

			fq.pop();

			for (int j = 0; j < 4; j++) {
				int r = fr + dr[j];
				int c = fc + dc[j];

				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				if (fisit[r][c]) continue;
				if (board[r][c] == '#') continue;

				fq.push({ r,c });
				fisit[r][c] = 1;
				board[r][c] = '#';
			}
		}

		for (int i = 0; i < pize; i++) {
			int pr = pq.front().first;
			int pc = pq.front().second;

			pq.pop();

			for (int j = 0; j < 4; j++) {
				int r = pr + dr[j];
				int c = pc + dc[j];

				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				if (pisit[r][c]) continue;
				if (board[r][c] == '#') continue;

				if (board[r][c] == 'o') {
					cout << cnt + 1;
					return;
				}
				pq.push({ r,c });
				pisit[r][c] = 1;
			}
		}
	}
	cout << "IMPOSSIBLE";
	return;
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				fq.push({ i, j });
				fisit[i][j] = 1;
				board[i][j] = '#';
			}
			else if (board[i][j] == 'J') {
				pq.push({ i, j });
				pisit[i][j] = 1;
			}

			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				if (board[i][j] == '.') board[i][j] = 'o';
				else if (board[i][j] == 'J') {
					cout << 1;
					return 0;
				}
			}
		}

	BFS();
}