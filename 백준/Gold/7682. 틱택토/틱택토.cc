#include <iostream>
using namespace std;

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        string s;   cin >> s;
        int o = 0, x = 0, c = 0;
        if (s == "end") break;

        for (int i = 0; i < 9; i++) {
            if (s[i] == 'O') o++;
            else if (s[i] == 'X') x++;
            else c++;
        }

        int gap = x - o;
        if (gap != 1 && gap != 0) {
            cout << "invalid\n";
            continue;
        }

        int cnto = 0, cntx = 0;
        for (int i = 0; i < 3; i++) {
            if (s[i] == s[i + 3] && s[i] == s[i + 6]) {
                if (s[i] == 'O') cnto++;
                else if (s[i] == 'X') cntx++;
            }
        }

        for (int i = 0; i < 7; i+=3) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                if (s[i] == 'O') cnto++;
                else if (s[i] == 'X') cntx++;
            }
        }

        if (s[0] == s[4] && s[0] == s[8]) {
            if (s[0] == 'O') cnto++;
            else if (s[0] == 'X') cntx++;
        }

        if (s[2] == s[4] && s[2] == s[6]) {
            if (s[2] == 'O') cnto++;
            else if (s[2] == 'X') cntx++;
        }

        if (cnto && cntx) {
            cout << "invalid\n";
            continue;
        }

        if (cnto && gap == 1) {
            cout << "invalid\n";
            continue;
        }

        if (cntx && gap == 0) {
            cout << "invalid\n";
            continue;
        }

        if (!cntx && !cnto && c) {
            cout << "invalid\n";
            continue;
        }

        cout << "valid\n";
    }
}