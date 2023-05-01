#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j;  cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int re = 0;
    for (i = n - 1; i > 0; i--) {
        if (arr[i - 1] < 0) break;
        if (arr[i] * arr[i - 1] > arr[i] + arr[i - 1]) {
            re += arr[i] * arr[i - 1];
            i--;
        }
        else re += arr[i];
    }

    for (j = 0; j < i; j++) {
        if (arr[j] * arr[j + 1] > arr[j] + arr[j + 1]) {
            re += arr[j] * arr[j + 1];
            j++;
        }
        else re += arr[j];
    }

    if (j == i) re += arr[j];
    cout << re;
}