#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a = 0, b = 1, c = 0;
    for (int i = 0; i < n - 1; i++){
        c = (a + b) % 1234567;
        a = b;
        b = c;
    }
    
    return c;
}