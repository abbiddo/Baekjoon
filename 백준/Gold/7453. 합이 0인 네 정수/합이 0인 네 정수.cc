#include <iostream>
#include <algorithm>
using namespace std;

int A[4000];
int B[4000];
int C[4000];
int D[4000];

int AB[16000000];
int CD[16000000];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;		cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

	int idx = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			AB[idx] = A[i] + B[j];
			CD[idx++] = C[i] + D[j];
		}

	sort(AB, AB + idx);
	sort(CD, CD + idx);

	int left = 0, right = idx - 1;
	long long cnt = 0;
	while (left < idx && right >= 0) {
		int sum = AB[left] + CD[right];

		if (sum == 0) {
			long long leftCnt = 1, rightCnt = 1;
			while (left < idx - 1 && AB[left] == AB[left + 1]) {
				left++;
				leftCnt++;
			}
			while (right > 0 && CD[right] == CD[right - 1]) {
				right--;
				rightCnt++;
			}
			left++;

			cnt += leftCnt * rightCnt;
		}
		else if (sum > 0) right--;
		else left++;
	}

	cout << cnt;
}