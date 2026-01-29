#include<string>
#include<iostream>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<string> st;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='(') {
            st.push("(");
        }
        else if (s[i]==')'&& !st.empty()) {
            st.pop();
        }
        else if (s[i]==')'&& st.empty()) {
            answer=false;
            return answer;
        }
    }
    if (!st.empty()) {
        answer=false;
    }
    return answer;
}
