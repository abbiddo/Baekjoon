#include <iostream>
using namespace std;

int n;
int arr[10000][6];
int pairs[6] = { 5, 3, 4, 1, 2, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < 6; i++) {
		int res = 6;
		int top = arr[0][pairs[i]];
		int bottom = arr[0][i];

		if (top == 6 || bottom == 6) res = 5;
		if (bottom + top == 11) res = 4;

		for (int j = 1; j < n; j++) {
			bottom = top;
			for (int k = 0; k < 6; k++) {
				if (top == arr[j][k]) {
					top = arr[j][pairs[k]];
					break;
				}
			}

			int tmp = 6;
			if (top == 6 || bottom == 6) tmp = 5;
			if (bottom + top == 11) tmp = 4;

			res += tmp;
		}

		result = max(result, res);
	}

	cout << result;
}