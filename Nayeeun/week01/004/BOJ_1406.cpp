#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> left, right;
    string str;
    int M;

    cin >> str >> M;

    for (char c : str) left.push(c);

    while (M--) {
        char order;
        cin >> order;

        switch (order) {
        case 'L':
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
            break;
        case 'D':
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
            break;
        case 'B':
            if (!left.empty()) {
                left.pop();
            }
            break;
        case 'P':
            char alp;
            cin >> alp;
            left.push(alp);
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

    return 0;
}
