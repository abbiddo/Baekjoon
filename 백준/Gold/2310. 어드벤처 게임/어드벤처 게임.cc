#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int visit[1001];
vector<int> v[1001];
pair<char, int> maze[1001]; 
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	while (1) {
		cin >> n;
		if (n == 0) return 0;


		for (int i = 1; i <= n; i++) {
			char c;	int k;
			cin >> c >> k;
			maze[i] = { c, k };

			visit[i] = -1;
			v[i].clear();

			while (1) {
				int a;	cin >> a;
				if (a == 0) break;
				v[i].push_back(a);
			}
		}

		if (n == 1 && maze[1].first == 'T') {
			cout << "No\n";
			continue;
		}

		bool check = false;

		q.push({ 1, 0 });
		visit[1] = true;

		while (!q.empty()) {
			int coor = q.front().first;
			int coin = q.front().second;
			q.pop();

			if (coor == n) {
				check = true;
				break;
			}

			for (int i = 0; i < v[coor].size(); i++) {
				if (maze[v[coor][i]].first == 'E') {
					if (visit[v[coor][i]] < coin) {
						q.push({ v[coor][i], coin });
						visit[v[coor][i]] = coin;
					}
				}
				else if (maze[v[coor][i]].first == 'L') {
					int money = max(coin, maze[v[coor][i]].second);
					if (visit[v[coor][i]] < money) {
						q.push({ v[coor][i], money });
						visit[v[coor][i]] = money;
					}
				}
				else if (coin >= maze[v[coor][i]].second) {
					int money = coin - maze[v[coor][i]].second;
					if (visit[v[coor][i]] < money) {
						q.push({ v[coor][i], money });
						visit[v[coor][i]] = money;
					}
				}
			}

		}
		if (check) cout << "Yes\n";
		else cout << "No\n";
	}
}