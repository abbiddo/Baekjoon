#include <iostream>
#include <string>
using namespace std;

int n, res, len;
string arr[1000], sub[1000];

bool check(int res) {
	for (int i = 0; i < n; i++) {
		sub[i] = arr[i].substr(len - res, res);
		for (int j = 0; j < i; j++)
			if (sub[i] == sub[j]) return false;
	}
	return true;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	len = arr[0].size();
	while (res <= arr[0].size()) {
		if (check(res)) {
			cout << res;
			return 0;
		}
		res++;
	}

}