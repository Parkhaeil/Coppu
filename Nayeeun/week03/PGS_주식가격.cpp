#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            int j = st.top();
            st.pop();
            answer[j] = i - j;
        }
        st.push(i);
    }

    while (!st.empty()) {
        int j = st.top();
        st.pop();
        answer[j] = (n - 1) - j;
    }
    return answer;
}
