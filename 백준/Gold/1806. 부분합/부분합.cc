#include <iostream>
using namespace std;

int n, s, res = 1000000;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int left = 0, right = 0;
	int sum = arr[0];

	while (left < n) {
		if (sum < s) {
			right++;
			sum += arr[right];
			if (right >= n) break;
		}
		else {
			if (left == right) {
				cout << 1;
				return 0;
			}
			res = min(res, (right - left + 1));
			sum -= arr[left];
			left++;
		}
	}
	if (res == 1000000) cout << 0;
	else cout << res;
}