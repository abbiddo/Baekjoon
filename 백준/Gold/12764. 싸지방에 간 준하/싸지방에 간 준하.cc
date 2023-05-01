#include <iostream>
#include <queue>
using namespace std;

// 오름차순 우선순위 큐
priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int,int >>> pq;
int arr[100000][2];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0;	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		pq.push({ a, b });
	}

	// 큐의 사이즈가 1이면, 카드가 한 묶음이면 종료
	for (int i = 0; i < n; i++) {
		int start = pq.top().first;
		int end = pq.top().second;
		pq.pop();

		int j = 0;
		while (arr[j][0] && arr[j][0] > start) j++;

		arr[j][0] = end;
		arr[j][1]++;
	}

	int k = 0;
	for (k; k < 100000; k++) 
		if (arr[k][1] == 0) break;

	cout << k << "\n";
	for (int i = 0; i < k; i++) cout << arr[i][1] << " ";
}