#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool arr[100][100];
int visit[100][100];

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

void BFS() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];

			if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
			
			int tmp = visit[rr][cc];
			if (arr[rr][cc] == 0) visit[rr][cc] = min(visit[rr][cc], visit[r][c]);
			if (arr[rr][cc] == 1) visit[rr][cc] = min(visit[rr][cc], visit[r][c] + 1);

			if (tmp != visit[rr][cc])	q.push({ rr, cc });
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;	cin >> s;
		for (int j = 0; j < m; j++) 
			if (s[j] == '1') arr[i][j] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visit[i][j] = 1000;
	}

	BFS();
	
	cout << visit[n - 1][m - 1];
}