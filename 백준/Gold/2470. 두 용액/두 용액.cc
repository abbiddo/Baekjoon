#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int gap = 2000000000, s = arr[0], m = arr[n - 1], l = 0, r = n - 1;

    while (l < r) {
        int sum = arr[l] + arr[r];
        if (gap > abs(sum)) {
            gap = abs(sum);
            s = arr[l]; m = arr[r];
        }

        if (sum == 0) break;
        else if (sum < 0) l++;
        else r--;
    }

    cout << s << " " << m;
}