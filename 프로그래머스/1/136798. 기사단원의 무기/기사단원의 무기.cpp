#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;
    
    for (int i = 2; i <= number; i++){
        int cnt = 0;
        for (int j = 1; j <= sqrt(i); j++){
            if (i % j == 0) cnt+=2;            
        }
        if (sqrt(i) == (int)sqrt(i)) cnt--;
        if (cnt > limit) answer += power;
        else answer += cnt;
    }
    
    return answer;
}