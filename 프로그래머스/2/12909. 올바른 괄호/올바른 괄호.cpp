#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(') st.push(0);
        else{
            if (st.size()) st.pop();
            else return false;
        }
    }
    if (st.size()) return false;
    return true;
}