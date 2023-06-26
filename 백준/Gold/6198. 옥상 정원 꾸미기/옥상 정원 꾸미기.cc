#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> s;
long long n, cnt;
int arr[80000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	s.push({ 1000000001, n });
	for (int i = n - 1; i >= 0; i--) {
		while (s.size() && arr[i] > s.top().first) s.pop();
		cnt += (s.top().second - i - 1);
		s.push({arr[i], i});
	}

	cout << cnt;
}