#include <iostream>
#include <algorithm>
using namespace std;

int B[1000];
int C[1000];
int D[1000];

int main() {
	int b, c, d;		cin >> b >> c >> d;
	int sale = min(min(b, c), d);

	int sum = 0;
	for (int i = 0; i < b; i++) {
		cin >> B[i];
		sum += B[i];
	}
	
	for (int i = 0; i < c; i++) {
		cin >> C[i];
		sum += C[i];
	}

	for (int i = 0; i < d; i++) {
		cin >> D[i];
		sum += D[i];
	}

	sort(B, B + b, greater<>());
	sort(C, C + c, greater<>());
	sort(D, D + d, greater<>());

	cout << sum << "\n";

	for (int i = 0; i < sale; i++) {
		sum -= B[i] / 10;
		sum -= C[i] / 10;
		sum -= D[i] / 10;
	}

	cout << sum;
}