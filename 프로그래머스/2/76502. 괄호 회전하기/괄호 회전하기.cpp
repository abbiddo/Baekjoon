#include <string>
#include <stack>

using namespace std;

bool check(string s){
    stack<char> st;
    for (int i = 0;i < s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else{
            if (!st.size()) return false;
            if (st.top() == '(' && s[i] == ')') st.pop();
            else if (st.top() == '{' && s[i] == '}') st.pop();
            else if (st.top() == '[' && s[i] == ']') st.pop();
        }
    }
    if (st.size()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++){
        answer += check(s);
        s = s[s.size() - 1] + s.substr(0, s.size() - 1);
    }
    
    return answer;
}