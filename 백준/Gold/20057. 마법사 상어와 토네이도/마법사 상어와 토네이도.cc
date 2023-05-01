#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int d1r[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };
int d1c[9] = { 0, -1, 0, 1, -2, -1, 0, 1, 0 };

int d2r[9] = { 0, 1, 0, -1, 2, 1, 0, -1, 0 };
int d2c[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };

int d3r[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };
int d3c[9] = { 0, 1, 0, -1, 2, 1, 0, -1, 0 };

int d4r[9] = { 0, -1, 0, 1, -2, -1, 0, 1, 0 };
int d4c[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };

int ratio[9] = { 2, 10, 7, 1, 5, 10, 7, 1, 2 };
int board[500][500];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, r, c, d = 1, re = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) cin >> board[i][j];

	r = c = N / 2 + 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < i; k++) {
				if (d == 1) c--;
				else if (d == 2) r++;
				else if (d == 3) c++;
				else if (d == 4) r--;

				int sand = board[r][c];
				int sum = 0;
				board[r][c] = 0;

				for (int l = 0; l < 9; l++) {
					int rr, cc;
					if (d == 1) {
						rr = r + d1r[l];
						cc = c + d1c[l];
					}
					else if (d == 2) {
						rr = r + d2r[l];
						cc = c + d2c[l];
					}
					else if (d == 3) {
						rr = r + d3r[l];
						cc = c + d3c[l];
					}
					else if (d == 4) {
						rr = r + d4r[l];
						cc = c + d4c[l];
					}
					int rat = sand * ratio[l] / 100;
					sum += rat;
					if (rr < 1 || rr > N || cc < 1 || cc > N) {
						re += rat;
						continue;
					}
					board[rr][cc] += rat;
				}
				int rr = r, cc = c;

				if (d == 1) cc = c - 1;
				else if (d == 2) rr = r + 1;
				else if (d == 3) cc = c + 1;
				else if (d == 4) rr = r - 1;

				if (rr < 1 || rr > N || cc < 1 || cc > N) re += (sand - sum);
				else board[rr][cc] += (sand - sum);

				if (r == 1 && c == 1) {
					cout << re;
					return 0;
				}			
			}
			d++;
			if (d > 4) d = 1;
		}
	}
}