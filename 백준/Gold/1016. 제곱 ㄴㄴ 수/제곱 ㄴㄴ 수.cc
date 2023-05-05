#include <iostream>
using namespace std;

typedef long long ll;
ll arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll min, max;
	cin >> min >> max;

	for (ll i = 2; i *i <= max; i++) {
		ll n = min / (i * i);
		if (min % (i * i) != 0) n++;
		while (n * i * i <= max) {
			arr[n * i * i - min] = 1;
			n++;
		}
	}
	int cnt = 0;
	for (int i = 0; i <= max - min; i++) 
		if (!arr[i]) cnt++;
	cout << cnt;
}