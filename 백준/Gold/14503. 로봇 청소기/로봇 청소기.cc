#include <iostream>
using namespace std;

int n, m;
int sr, sc, d;
int arr[50][50];
int visit[50][50];

int dr[4] = { -1,0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> sr >> sc >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	while (1) {
		if (arr[sr][sc] == 0 && visit[sr][sc] == 0) visit[sr][sc] = 1;

		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int r = sr + dr[i];
			int c = sc + dc[i];

			if (arr[r][c] == 0 && visit[r][c] == 0) flag = true;
		}

		if (flag) {
			d -= 1;
			d += 4;
			d %= 4;

			sr += dr[d];
			sc += dc[d];
			
			if (sr < 0 || sc < 0 || sr >= n || sc >= m  || arr[sr][sc] == 1 || visit[sr][sc] == 1) {
				sr -= dr[d];
				sc -= dc[d];
			}
		}

		else {
			sr -= dr[d];
			sc -= dc[d];

			if (arr[sr][sc] == 1) break;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			if (visit[i][j] == 1) cnt++;

	cout << cnt;
}