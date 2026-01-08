#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        stack<char> left, right;

        for (char order : str) {
            switch (order) {
            case '-':
                if (!left.empty()) {
                    left.pop();
                }
                break;
            case '<':
                if (!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
                break;
            case '>':
                if (!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
                break;
            default:
                left.push(order);
                break;
            }
        }
        while (!left.empty()) {
            right.push(left.top());
            left.pop();
        }

        while (!right.empty()) {
            cout << right.top();
            right.pop();
        }
        cout << "\n";
    }
    return 0;
}
