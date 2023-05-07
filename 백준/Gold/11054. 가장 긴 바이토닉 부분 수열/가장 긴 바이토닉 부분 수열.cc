#include <iostream>
using namespace std;

int arr[1001];
int mi[1001];
int ma[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        ma[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i]) ma[i] = max(ma[i], ma[j] + 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        mi[i] = 1;
        for (int j = n - 1; j > i; j--)
            if (arr[j] < arr[i]) mi[i] = max(mi[i], mi[j] + 1);
    }

    for (int i = 0; i < n; i++)
        cnt = max(cnt, mi[i] + ma[i]);

    cout << cnt - 1;
}