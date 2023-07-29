#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long n, m, res;
int bag[300000];
pair<int, int> jewelry[300001];
priority_queue<int> pq;

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		jewelry[i] = { a, b };
	}
	for (int i = 0; i < m; i++) cin >> bag[i];

	sort(jewelry, jewelry + n);
	sort(bag, bag + m);

	jewelry[n] = { 100000001, 0 };

	int index = 0;
	for (int i = 0; i < m; i++) {
		while (jewelry[index].first <= bag[i]) {
			pq.push(jewelry[index].second);
			index++;
		}
		if (pq.size()) {
			res += pq.top();
			pq.pop();
		}
	}

	cout << res;
}