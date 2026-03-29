#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int num = 0, sum = 0;
    char op = '+';
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || i == s.size()) {
            if (op == '+')
                sum += num;
            else
                sum -= num;

            num = 0;
            op = s[i];
        }
        else {
            num = num * 10 + (s[i] - '0');
        }
    }
    cout << sum;
}
