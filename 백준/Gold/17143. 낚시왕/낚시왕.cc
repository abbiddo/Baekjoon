#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

struct shark {
	int r, c, s, d, z;
};

vector<shark> bada[101][101];
queue<shark> q;

int main() {
	int R, C;	cin >> R >> C;
	int n;	cin >> n;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;	cin >> a >> b >> c >> d >> e;
		bada[a][b].push_back({ a,b,c,d,e });
		q.push({ a,b,c,d,e });
	}

	for (int T = 1; T <= C; T++) {
		int dc = -1, dr = -1;
		for (int i = 1; i <= R; i++) {
			if (bada[i][T].size() > 0) {
				sum += bada[i][T][0].z;
				bada[i][T].clear();
				dc = T;
				dr = i;
				break;
			}
		}

		int qize = q.size();
		for (int i = 0; i < qize; i++) {
			int r = q.front().r;
			int c = q.front().c;
			int s = q.front().s;
			int d = q.front().d;
			int z = q.front().z;
			q.pop();

			if (bada[r][c].size() == 0 || (dc == c && dr == r)) continue;

			bada[r][c].erase(bada[r][c].begin());

			int dir;
			int rr = r, cc = c;

			if (d == 1) {
				if (s < r) {
					r -= s;
					if (r == 1) d = 2;
				}
				else {
					dir = (R - r + s - 1) / (R - 1);
					if (dir % 2 == 1) d = 2;
					r = 2 + s - r;
					r %= ((R - 1) * 2);
					if (r == 0) r = (R - 1) * 2;
					r = abs(R - r);
					r = R - r;
					if (r == 1) d = 2;
					else if (r == R) d = 1;
				}
			}
			else if (d == 2) {
				r += s;
				dir = (r - 2) / (R - 1);
				if (dir % 2 == 1) d = 1;
				r %= ((R - 1) * 2);
				if (r == 0) r = (R - 1) * 2;
				r = abs(R - r);
				r = R - r;
				if (r == 1) d = 2;
				else if (r == R) d = 1;
			}
			else if (d == 3) {
				c += s;
				dir = (c - 2) / (C - 1);
				if (dir % 2 == 1) d = 4;
				c %= ((C - 1) * 2);
				if (c == 0) c = (C - 1) * 2;
				c = abs(C - c);
				c = C - c;
				if (c == 1) d = 3;
				else if (c == C) d = 4;
			}
			else {
				if (s < c) {
					c -= s;
					if (c == 1) d = 3;
				}
				else {
					dir = (C - c + s - 1) / (C - 1);
					if (dir % 2 == 1) d = 3;
					c = 2 + s - c;
					c %= ((C - 1) * 2);
					if (c == 0) c = (C - 1) * 2;
					c = abs(C - c);
					c = C - c;
					if (c == 1) d = 3;
					else if (c == C) d = 4;
				}
			}
			bada[r][c].push_back({ r,c,s,d,z });
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (bada[i][j].size() == 1) {
					q.push(bada[i][j][0]);
				}
				else if (bada[i][j].size() > 1) {
					shark maxi = bada[i][j][0];
					int bize = bada[i][j].size();
					for (int k = 1; k < bize; k++)
						if (maxi.z < bada[i][j][k].z) maxi = bada[i][j][k];

					bada[i][j].clear();
					q.push(maxi);
					bada[i][j].push_back(maxi);
				}
			}
		}
	}
	cout << sum;
}