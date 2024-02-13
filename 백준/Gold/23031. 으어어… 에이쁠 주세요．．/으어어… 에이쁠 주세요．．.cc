#include <iostream>
#include <vector>
using namespace std;

struct zombie {
	int r, c, d;
};

int n, sr, sc, sd;
char arr[15][15];
bool visit[15][15];
vector<zombie> zom;

int dr[9] = { 1, 0, -1 ,0, 1, 1, -1, -1, 0 };
int dc[9] = { 0, -1, 0, 1, 1, -1, 1, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	string s;	cin >> s;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'Z') zom.push_back({i, j, 0});
		}

	int zize = zom.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'F') {
			sr += dr[sd];
			sc += dc[sd];

			if (sr < 0 || sc < 0 || sr >= n || sc >= n) {
				sr -= dr[sd];
				sc -= dc[sd];
			}

			if (arr[sr][sc] == 'S') {
				for (int k = 0; k < 9; k++) {
					int r = sr + dr[k];
					int c = sc + dc[k];

					if (r < 0 || c < 0 || r >= n || c >= n) continue;

					visit[r][c] = true;
				}
			}
		}

		else if (s[i] == 'R') sd = (sd + 1) % 4;
		else sd = (sd + 3) % 4;

		if (!visit[sr][sc]) {
			for (int k = 0; k < zize; k++) {
				if (sr == zom[k].r && sc == zom[k].c) {
					cout << "Aaaaaah!";
					return 0;
				}
			}
		}

		for (int k = 0; k < zize; k++) {
			int r = zom[0].r;
			int c = zom[0].c;
			int d = zom[0].d;
			zom.erase(zom.begin());

			int rr = r + dr[d];
			int cc = c + dc[d];

			if (rr < 0 || cc < 0 || rr >= n || cc >= n) zom.push_back({ r, c, abs(d - 2) });
			else zom.push_back({ rr, cc, d });
		}

		if (!visit[sr][sc]) {
			for (int k = 0; k < zize; k++) {
				if (sr == zom[k].r && sc == zom[k].c) {
					cout << "Aaaaaah!";
					return 0;
				}
			}
		}
	}

	cout << "Phew...";
}
