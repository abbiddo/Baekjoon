#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[5];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i < 5; i++) {
		string s;	cin >> s;
		for (int j = 0; j < 8; j++) {
			arr[i].push_back(s[j] - '0');
		}
	}

	cin >> n;
	while (n--) {
		int a, b;	cin >> a >> b;
		int l = arr[a][6];
		int r = arr[a][2];
		int d = b;

		if (b == 1) {
			arr[a].insert(arr[a].begin(), arr[a][7]);
			arr[a].erase(arr[a].end() - 1);
		}
		else {
			arr[a].push_back(arr[a][0]);
			arr[a].erase(arr[a].begin());
		}

		for (int i = a - 1; i > 0; i--) {
			if (arr[i][2] == l) break;
			l = arr[i][6];

			if (d == -1) {
				arr[i].insert(arr[i].begin(), arr[i][7]);
				arr[i].erase(arr[i].end() - 1);
			}
			else {
				arr[i].push_back(arr[i][0]);
				arr[i].erase(arr[i].begin());
			}

			d = d == 1 ? -1 : 1;
		}

		d = b;
		for (int i = a + 1; i < 5; i++) {
			if (arr[i][6] == r) break;
			r = arr[i][2];

			if (d == -1) {
				arr[i].insert(arr[i].begin(), arr[i][7]);
				arr[i].erase(arr[i].end() - 1);
			}
			else {
				arr[i].push_back(arr[i][0]);
				arr[i].erase(arr[i].begin());
			}

			d = d == 1 ? -1 : 1;
		}

	}

	int score[4] = { 1, 2, 4, 8 };
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i + 1][0] == 1) res += score[i];
	}

	cout << res;

}
