#include <iostream>
#include <queue>
using namespace std;

int n, m, k, res;
bool visit[1001];
vector<pair<int, int>> road[100001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void prim() {
	while (!pq.empty()) {
		pair<int, int> edge = pq.top();
		pq.pop();

		if (visit[edge.second]) continue;

		visit[edge.second] = true;
		res += edge.first;

		for (int i = 0; i < road[edge.second].size(); i++)
			if (!visit[road[edge.second][i].second])
				pq.push({ road[edge.second][i] });
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int a;	cin >> a;
		visit[a] = true;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;		cin >> a >> b >> c;
		road[a].push_back({ c, b });
		road[b].push_back({ c, a });

		if (visit[a]) pq.push({ c, b });
		else if (visit[b]) pq.push({ c, a });
	}

	prim();

	cout << res;
}