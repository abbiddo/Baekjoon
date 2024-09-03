#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    
    stack<pair<int, int>> s;
    s.push({prices[size - 1], 0});
    answer[size - 1] = 0;
    
    for (int i = size - 2; i >= 0; i--){
        int tmp = 1;
        while(s.size() && prices[i] <= s.top().first){
            tmp += s.top().second;
            s.pop();
        }
        
        s.push({prices[i], tmp});
        answer[i] = tmp;
    }    
    
    return answer;
}