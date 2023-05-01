#include <iostream>
#include <queue>
using namespace std;

int n, s, x, y, k;	
int board[200][200];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS() {
	// <바이러스 번호, <행, 열>, 오름차순>
	priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

	// 바이러스가 존재하면 우선순위 큐에 삽입
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j]) q.push(make_pair(board[i][j], make_pair(i, j)));

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curx = q.top().second.first;
		int cury = q.top().second.second;
		int num = q.top().first;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = curx + dx[i];
			int yy = cury + dy[i];

			if (xx >= n || xx < 0 || yy >= n || yy < 0) continue;
			if (!board[xx][yy]) board[xx][yy] = num;
			if (xx == x - 1 && yy == y - 1) return board[xx][yy];
		}
	}

	// 큐가 비어버리면 엘리베이터로 갈 수 없으므로 0 리턴
	return 0;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> board[i][j];

	cin >> s >> x >> y;

	if (!s) {
		cout << board[x - 1][y - 1];
		return 0;
	}

	for (int i = 0; i < s; i++) {
		int re = BFS();
		if (re) {
			cout << re;
			return 0;
		}
	}
	cout << 0;
}