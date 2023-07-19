#include <iostream>
using namespace std;

int n, s, e;
long long res;
int arr[100000];
bool visit[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (s; s < n; s++) {
		while (e < n) {
			if (visit[arr[e]]) break;
			visit[arr[e++]] = true;
		}
		res += (e - s);
		visit[arr[s]] = false;
	}
	cout << res;
}