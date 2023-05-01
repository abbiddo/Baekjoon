#include <iostream>
#include <algorithm>
using namespace std;

struct ball {
    int size, color, index;
};
ball arr[200001];
int color[200001];
int re[200001];

bool cmp(ball& b1, ball& b2) {
    return b1.size < b2.size;
}
int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, s;   cin >> c >> s;
        arr[i] = { s, c, i };
    }

    sort(arr + 1, arr + n + 1, cmp);

    int sum = 0, j = 1;
    for (int i = 1; i <= n; i++) {
        for (j; j < i && arr[i].size > arr[j].size; j++) {
            sum += arr[j].size;
            color[arr[j].color] += arr[j].size;
        }
        re[arr[i].index] = sum - color[arr[i].color];
    }

    for (int i = 1; i <= n; i++) 
        cout << re[i] << "\n";
}