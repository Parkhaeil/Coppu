#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    stack<int> stack;

    while (n--) {
        string ord;
        cin >> ord;

        if (ord == "push") {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (ord == "pop") {
            if (stack.empty()) cout << "-1\n";
            else {
                cout << stack.top() << "\n";
                stack.pop();
            }
        }
        else if (ord == "size") {
            cout << stack.size() << "\n";
        }
        else if (ord == "empty") {
            cout << (stack.empty() ? "1\n" : "0\n");
        }
        else if (ord == "top") {
            if (stack.empty()) cout << "-1\n";
            else cout << stack.top() << "\n";
        }
    }
    return 0;
}
