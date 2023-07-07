#include <iostream>
#include <queue>
using namespace std;

int n, m, res;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater< int>> work;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		pq.push({ a, a + b });
	}

	for (int i = 0; i < n; i++) {
		while (work.size() && pq.top().first - work.top() > m) work.pop();
		if (!work.size()) res++;
		else if (pq.top().first >= work.top()) work.pop();
		else res++;
		work.push(pq.top().second);
		pq.pop();
	}

	cout << n - res;
}