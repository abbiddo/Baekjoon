#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                int sum = nums[i] + nums[j] + nums[k];
                bool flag = true;
                for(int tmp = 2; tmp <= sqrt(sum); tmp++){
                    if (sum % tmp == 0){
                        flag = false;
                        break;
                    }
                }
                if (flag) answer++;
            }
        }
    }

    return answer;
}