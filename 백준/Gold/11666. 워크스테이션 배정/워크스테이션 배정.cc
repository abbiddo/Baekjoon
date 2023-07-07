#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, res;
pair<int, int> arr[300000];
priority_queue<int, vector<int>, greater< int>> work;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		arr[i] = { a, a + b };
	}
    
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		while (work.size() && arr[i].first - work.top() > m) work.pop();
		
		if (!work.size()) res++;
		else if (arr[i].first >= work.top()) work.pop();
		else res++;
		
		work.push(arr[i].second);
	}
	cout << n - res;
}