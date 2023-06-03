#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end());
    
    for (int i = 0; i < A.size(); i++){
        int index = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        if (index < B.size()){
            answer++;
            B.erase(B.begin() + index);
        }
    }
    return answer;
}