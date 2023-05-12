#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int board[1000000];

int BFS() {
	queue<pair<int, int>> q;
	board[s] = 1;
	q.push(make_pair(s, 0));

	while (!q.empty()) {
		int cur = q.front().first;
		int count = q.front().second;
		q.pop();

		int up = cur + u;
		int down = cur - d;

		if (up == g || down == g) return count + 1;

		if (up <= f && !board[up]) {
			board[up] = 1;
			q.push(make_pair(up, count + 1));
		}
		if (down > 0 && !board[down]) {
			board[down] = 1;
			q.push(make_pair(down, count + 1));
		}
	}
	return 0;
}

int main() {
	cin >> f >> s >> g >> u >> d;

	if (s == g) {
		cout << 0;
		return 0;
	}

	int cnt = BFS();
	
	if (cnt) cout << cnt;
	else cout << "use the stairs";
}