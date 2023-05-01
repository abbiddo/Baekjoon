#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int re[1000001];

stack<int> s;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = n - 1; i >= 0; i--) {
		while (s.size() && arr[i] >= s.top()) s.pop();
		if (s.size() == 0) re[i] = -1;
		else re[i] = s.top();
		s.push(arr[i]);
	}

	for (int i = 0; i < n; i++) cout << re[i] << " ";
}