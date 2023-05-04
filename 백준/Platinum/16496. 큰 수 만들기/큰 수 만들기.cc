#include <iostream>
#include <algorithm>
using namespace std;

string arr[1000];

int cmp(string a, string b) {
    if (a == b) return false;
    if (a + b > b + a) return true;
    return false;
}

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n, cmp);

    if (arr[0][0] == '0') {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) cout << arr[i];
}