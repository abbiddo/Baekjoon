#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct fire {
	int r;
	int c;
	int m;
	int s;
	int d;
};

vector<fire> board[51][51];
vector<fire> visit;
int v[51][51];
int N, M, K;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		visit.push_back({ a,b,c,d,e });
	}

	for (int i = 0; i < K; i++) {
		int vize = visit.size();
		for (int j = 0; j < vize; j++) {
			int r = visit.front().r;
			int c = visit.front().c;
			int m = visit.front().m;
			int s = visit.front().s;
			int d = visit.front().d;

			visit.erase(visit.begin());

			int rr = r, cc = c;
			if (d == 0 || d == 1 || d == 7) {
				rr = (r - s) % N;
				if (rr < 1) rr += N;
			}
			if (d == 1 || d == 2 || d == 3) {
				cc = (c + s) % N;
				if (cc == 0) cc = N;
			}
			if (d == 3 || d == 4 || d == 5) {
				rr = (r + s) % N;
				if (rr == 0) rr = N;
			}
			if (d == 5 || d == 6 || d == 7) {
				cc = (c - s) % N;
				if (cc < 1) cc += N;
			}

			board[rr][cc].push_back({ rr,cc,m,s,d });
		}

		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (board[j][k].size() == 0) continue;
				else if (board[j][k].size() == 1) {
					visit.push_back(board[j][k][0]);
					board[j][k].erase(board[j][k].begin());
				}
				else {
					int bize = board[j][k].size();
					int m = 0, s = 0, dsum = 0, d;

					for (int l = 0; l < bize; l++) {
						m += board[j][k].front().m;
						s += board[j][k].front().s;
						d = board[j][k].front().d;

						dsum += (d % 2);

						board[j][k].erase(board[j][k].begin());
					}

					m /= 5;
					s /= bize;

					if (m > 0) {
						if (dsum == 0 || dsum == bize)
							for (int l = 0; l < 8; l += 2)
								visit.push_back({ j,k,m,s,l });
						else
							for (int l = 0; l < 8; l += 2)
								visit.push_back({ j,k,m,s,l + 1 });
					}
				}
			}
		}
	}

	int re = 0;
	for (int i = 0; i < visit.size(); i++)
		re += visit[i].m;

	cout << re;
}