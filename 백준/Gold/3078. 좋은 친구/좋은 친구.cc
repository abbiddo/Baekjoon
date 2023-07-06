#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int arr[300000];
long long res;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s;	cin >> s;
		arr[i] = s.size();
	}

	queue<int> q[21];

	for (int i = 0; i < n; i++) {
		res += q[arr[i]].size();
		q[arr[i]].push(i);

		for (int j = 2; j < 21; j++)
			if (q[j].size() && q[j].front() == i - k) {
				q[j].pop();
				break;
			}
	}

	cout << res;
}