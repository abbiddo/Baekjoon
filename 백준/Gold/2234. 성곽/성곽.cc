#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m, areaCnt;
string arr[50][50];
int visit[50][50];
int area[50][50];
int maxSize;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visit[i][j] = -1;

	int cnt = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (arr[r][c][i] == '1') continue;

			int rr = r + dr[i];
			int cc = c + dc[i];

			if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
			if (visit[rr][cc]) continue;
			
			visit[rr][cc] = -1;
			q.push({ rr, cc });

			cnt++;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visit[i][j] == -1) {
				visit[i][j] = cnt;
				area[i][j] = areaCnt;
			}
	areaCnt++;
	maxSize = max(maxSize, cnt);
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int a;	cin >> a;
			while (a) {
				arr[i][j] = to_string(a % 2) + arr[i][j];
				a /= 2;
			}
			while (arr[i][j].size() < 4) arr[i][j] = "0" + arr[i][j];
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visit[i][j] == 0) {
				BFS(i, j);
			}

	int remove = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int rr = i + dr[k];
				int cc = j + dc[k];

				if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
				if (area[i][j] == area[rr][cc]) continue;

				remove = max(remove, visit[i][j] + visit[rr][cc]);
			}
		}
	}

	cout << areaCnt << "\n" << maxSize << "\n" << remove;
}