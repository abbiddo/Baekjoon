#include <iostream>
#include <queue>
using namespace std;

int n, m;
char board[50][50];
bool pisit[50][50];	// 사람의 방문 체크
bool fisit[50][50];	// 불의 방문 체크
// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> pq;	// 사람 큐
queue<pair<int, int>> fq;	// 불 큐

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

				// 범위를 벗어나면 continue
				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				// 방문한 적이 있으면 continue
				if (fisit[r][c]) continue;
				// 벽이면 continue
				if (board[r][c] == '#') continue;

				if (board[r][c] == 'o') continue;

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

				// 범위를 벗어나면 continue
				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				// 방문한 적이 있으면 continue
				if (pisit[r][c]) continue;
				// 벽이면 continue
				if (board[r][c] == '#') continue;

				// 탈출 가능하면 출력 후 종료
				if (board[r][c] == 'o') {
					cout << cnt;
					return;
				}
				pq.push({ r,c });
				pisit[r][c] = 1;
			}
		}
	}
	cout << "KAKTUS";
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

			// 불 입력 시 불 큐에 추가, 벽과 같이 갈 수 없는 공간으로 취급
			if (board[i][j] == '*') {
				fq.push({ i, j });
				fisit[i][j] = 1;
				board[i][j] = '#';
			}

			// 사람 입력 시 사람 큐에 추가
			else if (board[i][j] == 'S') {
				pq.push({ i, j });
				pisit[i][j] = 1;
				board[i][j] = '.';
			}

			else if (board[i][j] == 'X') board[i][j] = '#';

			else if (board[i][j] == 'D') board[i][j] = 'o';
		}

	BFS();
}