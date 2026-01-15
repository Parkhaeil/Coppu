#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str;
    cin >> str >> n;

    list<char> lst;
    for (auto c : str) lst.push_back(c);

    list<char>::iterator t = lst.end();
    char cmd, c;
    while (n--) {
        cin >> cmd;
        if (cmd == 'L') {
            if (t != lst.begin()) t--;
        }
        else if (cmd == 'D') {
            if (t != lst.end()) t++;
        }
        else if (cmd == 'B') {
            if (t != lst.begin()) {
                t--;
                t = lst.erase(t);
            }
        }
        else {
            cin >> c;
            lst.insert(t, c);
        }
    }
    for (auto c : lst) cout << c;
}