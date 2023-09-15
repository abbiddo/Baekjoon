#include <iostream>
using namespace std;

int main() {
    int t;
    int direction = 0; // 초기 방향은 북쪽 (0: N, 1: E, 2: S, 3: W)
    for (int i = 0; i < 10; i++) {
        cin >> t;
        if (t == 1) { // 우향우
            direction = (direction + 1) % 4;
        } else if (t == 2) { // 뒤로 돌아
            direction = (direction + 2) % 4;
        } else if (t == 3) { // 좌향좌
            direction = (direction + 3) % 4;
        }
    }
    if (direction == 0) { // 북쪽
        cout << "N";
    } else if (direction == 1) { // 동쪽
        cout << "E";
    } else if (direction == 2) { // 남쪽
        cout << "S";
    } else if (direction == 3) { // 서쪽
        cout << "W";
    }
    return 0;
}