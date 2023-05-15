#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string aa = to_string(a);
    string bb = to_string(b);
    
    string ab = aa + bb;
    
    int aabb = stoi(ab);
    int res = 2 * a * b;
    
    answer = max(aabb, res);
    return answer;
}