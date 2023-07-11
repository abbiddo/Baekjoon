#include <iostream>
#include <queue>
using namespace std;

int n, m, hour, res;
int arr[200000];
priority_queue<pair<int, int>> pq;

int main() {
	cin >> n >> m;
	hour = 24 * n;
	for (int i = 0; i < m; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) {
		int a;	cin >> a;
		pq.push({ a, arr[i]});
		res += arr[i];
	}

	while (pq.size() && hour) {
		int time = pq.top().first;
		int score = pq.top().second;
		pq.pop();

		int get = (100 - score) / time;
		if (get <= hour) {
			res += get * time;
			hour -= get;
		}
		else {
			res += time * hour;
			hour = 0;
			break;
		}
		if ((100 - score) % time != 0)
			pq.push({ (100 - score) % time, 100 - (100 - score) % time });
	}

	cout << res;
}