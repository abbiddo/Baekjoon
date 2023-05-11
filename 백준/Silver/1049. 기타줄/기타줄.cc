#include <iostream>
using namespace std;

int main() {
	int n, m;	cin >> n >> m;
	int set = 1000, single = 1000;

	for (int i = 0; i < m; i++) {
		int a, b;	cin >> a >> b;
		set = min(set, a);
		single = min(single, b);
	}

	if (single * 6 <= set) {
		cout << single * n;
		return 0;
	}

	if (n < 6) {
		if (single * n <= set) cout << single * n;
		else cout << set;
		return 0;
	}
	
	if (n % 6 * single > set) cout << set * (n / 6 + 1);
	else cout << set * (n / 6) + single * (n % 6);
}