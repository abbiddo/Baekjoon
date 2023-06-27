#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int shushi[200000];
int res[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;	cin >> a;
		for (int j = 0; j < a; j++) {
			int k;	cin >> k;
			pq.push({ k, i });
		}
	}

	for (int i = 0; i < m; i++) cin >> shushi[i];
	sort(shushi, shushi + m);

	for (int i = 0; i < m; i++) {
		while (pq.size() && pq.top().first < shushi[i]) pq.pop();
		if (pq.empty()) break;
		if (pq.top().first == shushi[i]) {
			res[pq.top().second]++;
			pq.pop();
		}
	}

	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}