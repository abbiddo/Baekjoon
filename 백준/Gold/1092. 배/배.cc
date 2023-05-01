#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int limit[50];
vector<int> box;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;		cin >> n;
	for (int i = 0; i < n; i++) cin >> limit[i];
	
	int m;	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;	cin >> a;
		box.push_back(a);
	}

	sort(limit, limit + n);
	sort(box.begin(), box.end());

	if (box[m - 1] > limit[n - 1]) {
		cout << -1;
		return 0;
	}

	int cnt = 0;
	while (box.size()) {
		int i = box.size() - 1;
		cnt++;
		for (int j = n - 1; j >= 0; j--) {
			for (i; i >= 0; i--) {
				if (box[i] <= limit[j]) {
					box.erase(box.begin() + i);
					i--;
					break;
				}
			}
		}
	}
	cout << cnt;
}