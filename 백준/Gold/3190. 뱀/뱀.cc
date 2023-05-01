#include <iostream>
#include <queue>
using namespace std;

int dummy[101][101];
int snakes[101];
char snaked[100];

int main() {
	int n;		cin >> n;

	int a;	cin >> a;
	for (int i = 0; i < a; i++) {
		int x, y;		cin >> x >> y;
		dummy[x][y] = 1;
	}

	int s;		cin >> s;
	for (int i = 0; i < s; i++) 
		cin >> snakes[i] >> snaked[i];

	snakes[s] = snakes[s - 1] + n;

	deque<pair<int, int>> q;
	q.push_back({ 1, 1 });
	dummy[1][1] = 2;

	int sec = 0;
	int d = 1;
	for (int i = 0; i <= s; i++) {
		for (int j = sec; j < snakes[i]; j++) {
			sec++;
			pair<int, int> cur = q.back();

			int r, c;

			if (d == 1) {
				r = cur.first;
				c = cur.second + 1;

				if (c > n) {
					cout << sec;
					return 0;
				}
			}

			else if (d == 2) {
				r = cur.first + 1;
				c = cur.second;

				if (r > n) {
					cout << sec;
					return 0;
				}
			}

			else if (d == 3) {
				r = cur.first;
				c = cur.second - 1;

				if (c < 1) {
					cout << sec;
					return 0;
				}
			}

			else if (d == 4) {
				r = cur.first - 1;
				c = cur.second;

				if (r < 1) {
					cout << sec;
					return 0;
				}
			}

			q.push_back({ r, c });
			if (dummy[r][c] == 1) dummy[r][c] = 2;
			else if (dummy[r][c] == 0) {
				dummy[r][c] = 2;
				pair<int, int> tail = q.front();
				dummy[tail.first][tail.second] = 0;
				q.pop_front();
			}
			else {
				cout << sec;
				return 0;
			}
		}
		
		if (snaked[i] == 'L') {
			d--;
			if (d < 1) d = 4;
		}
		else {
			d++;
			if (d > 4) d = 1;
		}
	}
}