#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[10];
int res[10];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n - 2; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (res[j] == 0) cnt++;
			if (arr[i] == cnt - 1) {
				res[j] = i + 1;
				break;
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < n; i++)
		if (res[i] == 0) v.push_back(i);

	if (arr[n - 2] == 0) res[v[0]] = n - 1, res[v[1]] = n;
	else res[v[1]] = n - 1, res[v[0]] = n;

	for (int i = 0; i < n; i++) cout << res[i] << " ";
}