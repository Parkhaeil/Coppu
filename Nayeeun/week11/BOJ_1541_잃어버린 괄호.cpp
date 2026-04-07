#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int num = 0, sum = 0;
    bool minus = false;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || i == s.size()) {
            if (minus) sum -= num;
            else sum += num;
            if (s[i] == '-') minus = true;
            num = 0;
        }
        else {
            num = num * 10 + (s[i] - '0');
        }
    }
    cout << sum;
}
