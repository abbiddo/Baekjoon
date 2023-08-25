#include <iostream>
#include <queue>
using namespace std;

int n, m;
int visit[50][50];
string arr[50];
queue<pair<int, int>> q;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void bfs() {
	q.push({ 0, 0 });
	visit[0][0] = 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];

			if (rr < 0 || cc < 0 || rr >= n || cc >= n) continue;
			if (arr[rr][cc] == '1') {
				if (visit[r][c] < visit[rr][cc]) {
					q.push({ rr, cc });
					visit[rr][cc] = visit[r][c];
				}
			}
			else {
				if (visit[r][c] + 1 < visit[rr][cc]) {
					q.push({ rr, cc });
					visit[rr][cc] = visit[r][c] + 1;
				}
			}
		}
	}
}

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) visit[i][j] = 3000;

	bfs();
	cout<<visit[n-1][n-1];
}