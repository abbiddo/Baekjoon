#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0;	cin >> n;

	if (n == 1) { cout << 0; return 0; }

	for (int i = 0; i < n; i++) {
		int a;	cin >> a;
		pq.push(a);
	}

	while (pq.size() > 1) {
		int one = pq.top();	pq.pop();
		int two = pq.top();	pq.pop();
		pq.push(one + two);
		sum += one + two;
	}

	cout << sum;
}