#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int sum) {
    if (sum < 2) return false;
    for (int i = 2; i <= sqrt(sum); i++) {
        if (sum % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(vector<int>& nums, int start, int count, int sum, int& answer) {
    if (count == 3) {
        if (isPrime(sum)) {
            answer++;
        }
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        dfs(nums, i + 1, count + 1, sum + nums[i], answer);
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    dfs(nums, 0, 0, 0, answer);
    return answer;
}
