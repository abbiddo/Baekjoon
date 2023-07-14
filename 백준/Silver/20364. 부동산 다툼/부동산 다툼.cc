#include <iostream>
using namespace std;

int n, m, tmp, res;
bool visit[10000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		res = 0;
		cin >> tmp;
		int copy = tmp;

		while (tmp) {
			if (visit[tmp]) res = tmp;
			tmp /= 2;
		}
		visit[copy] = true;
		cout << res << "\n";
	}
}