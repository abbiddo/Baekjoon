#include <iostream>
using namespace std;

int r, c, n, sr, sc, res;
bool board[40][40];
bool sticker[10][10];

bool attach() {
	for (int i = 0; i <= r - sr; i++) {
		for (int j = 0; j <= c - sc; j++) {
			bool check = false;
			for (int k = 0; k < sr; k++) {
				for (int l = 0; l < sc; l++)
					if (sticker[k][l] && board[i + k][j + l]) {
						check = true;
						break;
					}
				if (check) break;
			}
			if (check) continue;

			for (int k = 0; k < sr; k++)
				for (int l = 0; l < sc; l++)
					if (sticker[k][l]) board[i + k][j + l] = true;

			return true;
		}
	}
	return false;
}

void rotate() {
	int tmp[10][10];
	for (int i = 0; i < sr; i++) 
		for (int j = 0; j < sc; j++)
			tmp[j][sr - i - 1] = sticker[i][j];

	int temp = sr;
	sr = sc;
	sc = temp;

	for (int i = 0; i < sr; i++)
		for (int j = 0; j < sc; j++)
			sticker[i][j] = tmp[i][j];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> r >> c >> n;
	for (int i = 0; i < n; i++) {
		cin >> sr >> sc;
		for (int j = 0; j < sr; j++)
			for (int k = 0; k < sc; k++) cin >> sticker[j][k];

		for (int j = 0; j < 4; j++) {
			bool ok = attach();
			if (!ok) rotate();
			else break;
		}
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (board[i][j]) res++;

	cout << res;
}