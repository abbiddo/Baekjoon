#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100000];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N;

	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) 
			cin >> arr[i].first >> arr[i].second;

		// 서류 점수를 기준으로 정렬
		sort(arr, arr + N);

		int myeonJub = arr[0].second;
		int cnt = 1;

		for (int i = 1; i < N; i++) 
			// 정렬 했으므로 서류 점수는 증가하고 면접 점수는 감소해야 함
			if (arr[i].second < myeonJub) {
				cnt++;
				myeonJub = arr[i].second;
			}

		cout << cnt << "\n";
	}
}