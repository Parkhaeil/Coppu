#include<string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for (char c : s) {
        if (c == '(') st.push('(');
        else {
            if (st.empty()) {
                answer = false;
                break;
            }
            st.pop();
        }
    }
    if (!st.empty()) answer = false;
    return answer;
}
