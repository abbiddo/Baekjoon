#include <iostream>
using namespace std;
int main() {
    int rgb[1001][3] = { 0 };
    int r[1001][3] = { 0 };
    int n, i, res = 1000000;

    cin >> n;

    for (i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++) cin >> rgb[i][j];

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            r[2][i] = rgb[1][k] + rgb[2][i];
            if (i == k) r[2][k] = 1000000;
        }
        for (i = 3; i <= n; i++) {
            r[i][0] = rgb[i][0] + min(r[i - 1][1], r[i - 1][2]);
            r[i][1] = rgb[i][1] + min(r[i - 1][0], r[i - 1][2]);
            r[i][2] = rgb[i][2] + min(r[i - 1][1], r[i - 1][0]);
        }
        for (int i = 0; i < 3; i++) {
            if (i == k) continue;
            res = min(res, r[n][i]);
        }
    }
    cout << res;
}