#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> arr[10000000];
int arrr[1000];
int n, m;

bool check() {
    for (int i = 0; i < n; i++) 
        if (arrr[i] == -1) return false;
    return true;
}

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) arrr[i] = -1;

    for (int i = 0; i < n * m; i++) {
        int a;  cin >> a;
        arr[i] = { a, i / m };
    }

    sort(arr, arr + n * m);

    int c = 0;
    int re = 1000000000;
    for (int i = 0; i < n * m; i++) {
        arrr[arr[i].second] = arr[i].first;
        if (!c) c = check();
        if (c) {
            int mi = 1000000000, ma = 0;
            for (int i = 0; i < n; i++) {
                if (mi > arrr[i]) mi = arrr[i];
                if (ma < arrr[i]) ma = arrr[i];
            }
            re = min(re, ma - mi);
        }
    }

    cout << re;
}