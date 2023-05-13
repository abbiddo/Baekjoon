#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	int n;		cin >> n;

	while (n--) {
		ll a, b;	cin >> a >> b;
		ll re = floor(log2(a) + 1) + b;
		cout << re << "\n";
	}
}