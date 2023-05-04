#include <iostream>
#include <stack>
using namespace std;

int arr[500000];
int re[500000];
stack<pair<int, int>> s;

int main() {
	int n;		cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	s.push({ arr[n - 1], n - 1 });
	for (int i = n - 2; i >= 0; i--) {
		while (s.size() && arr[i] > s.top().first) {
			re[s.top().second] = i + 1;
			s.pop();
		}

		s.push({ arr[i], i });
	}

	for (int i = 0; i < n; i++) cout << re[i] << " ";
}