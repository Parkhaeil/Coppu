#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> stack;

    int sum = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            sum -= stack.top();
            stack.pop();
        }
        else {
            sum += x;
            stack.push(x);
        }
    }
    cout << sum;
}
