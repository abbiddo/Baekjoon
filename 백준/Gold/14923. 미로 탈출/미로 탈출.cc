#include <iostream>
#include <queue>
using namespace std;

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int board[1001][1001];
int visit[1001][1001][2];

int n, m;
int sr, sc, er, ec;

struct wall {
    int r;
    int c;
    int ok; // 벽을 뚫은 적이 있는지 확인
};

int BFS() {
    queue<wall> q;

    q.push({ sr,sc,0 });
    // 시작은 벽을 뚫지 않음
    visit[sr][sc][0] = 1;
    visit[sr][sc][1] = 0;

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int ok = q.front().ok;

        q.pop();

        if (r == er && c == ec) {
            if (visit[r][c][0]) return visit[r][c][0] - 1;
            else if (visit[r][c][1]) return visit[r][c][1] - 1;
        }

        for (int i = 0; i < 4; i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];

            // 범위를 벗어나면 continue
            if (rr < 1 || rr > n || cc < 1 || cc > m) continue;

            // 두 경로 모두 방문한 적이 있으면 continue
            if (visit[rr][cc][0] && visit[rr][cc][1]) continue;

            // 벽을 뚫은 적이 있다면
            if (ok == 1) {
                // 다음 칸이 벽이면 또 벽을 뚫을 수 없기에 continue
                if (board[rr][cc]) continue;

                // 다음 칸이 벽이 아니고 어떤 경로든 방문한 적이 없으면
                if (!board[rr][cc] && !visit[rr][cc][1] && !visit[rr][cc][0]) {
                    q.push({ rr, cc, 1 });
                    visit[rr][cc][1] = visit[r][c][1] + 1;
                }
            }

            // 벽을 뚫은 적이 없다면
            else {
                // 다음 칸이 벽이고 벽을 뚫고 방문한 적이 없으면
                if (board[rr][cc] && !visit[rr][cc][1]) {
                    q.push({ rr,cc,1 });
                    visit[rr][cc][1] = visit[r][c][0] + 1;
                }

                // 다음 칸이 벽이 아니고 (벽을 뚫지 않고) 방문한 적이 없으면
                if (!board[rr][cc] && !visit[rr][cc][0]) {
                    q.push({ rr, cc, 0 });
                    visit[rr][cc][0] = visit[r][c][0] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> sr >> sc >> er >> ec;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];

    cout << BFS();
}