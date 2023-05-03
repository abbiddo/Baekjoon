#include <iostream>
#include <algorithm>
using namespace std;

long long arr[10000];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    long long cnt = 0;
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) {
            long long sum = arr[i] + arr[j];
            long long l = lower_bound(arr + j + 1 , arr + n, sum * -1) - arr;
            long long r = upper_bound(arr + j + 1 , arr + n, sum * -1) - arr;
            cnt += (r - l);
        }

    cout << cnt;
}