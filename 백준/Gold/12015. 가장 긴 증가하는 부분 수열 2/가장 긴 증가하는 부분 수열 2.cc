#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000000];
vector <int> res;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;		cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	res.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (res[res.size() - 1] == arr[i]) continue;
		else if (res[res.size() - 1] < arr[i]) res.push_back(arr[i]);
		else res[lower_bound(res.begin(), res.end(), arr[i]) - res.begin()] = arr[i];
	}
	cout << res.size();
}