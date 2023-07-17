#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int res[5001];
pair<int, int> arr[5001];
vector<int> v[5001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		arr[i] = { a, i };
	}

	for (int i = 0; i < m; i++) {
		int a, b;	cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	sort(arr + 1, arr + n + 1);

	for (int i = n; i > 0; i--) {
		int ma = 0;
		int index = arr[i].second;
		for (int j = 0; j < v[index].size(); j++)
			ma = max(ma, res[v[index][j]]);
		res[index] = ma + 1;
	}

	for (int i = 1; i <= n; i++) cout << res[i] << "\n";
}