#include <iostream>
#include <vector>
using namespace std;

int n, m, res;
int arr[100];
vector<int> v;

bool already(int i) {
	for (int j = 0; j < v.size(); j++)
		if (v[j] == arr[i]) return true;
	return false;
}

int main() {
	// 입출력 속도 향상을 위함
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];

	for (int i = 0; i < m; i++) {
		if (already(i)) continue;
		if (v.size() < n) {
			v.push_back(arr[i]);
			continue;
		}

		int ma = 0, index = -1;
		for (int j = 0; j < n; j++) {
			bool tmp = true;
			for (int k = i + 1; k < m; k++) {
				if (v[j] == arr[k]) {
					if (index < k) {
						ma = j;
						index = k;
					}
					tmp = false;
					break;
				}
			}
			if (tmp) {
				ma = j;
				break;
			}
		}
		v.erase(v.begin() + ma);
		v.push_back(arr[i]);
		res++;
	}
	cout << res;
}