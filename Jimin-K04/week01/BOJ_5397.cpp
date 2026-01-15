#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

// cursor 는 현재 커서의 오른쪽을 가리킨다.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n;
    cin >> n;

    while (n--) {
        cin >> str;
        list<char> L;
        list<char>::iterator cursor = L.end();

        for (auto c : str) {
            if (c == '<') {
                if (cursor != L.begin()) cursor--;
            }
            else if (c == '>') {
                if (cursor != L.end())cursor++;
            }
            else if (c == '-') {
                if (cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else {
                L.insert(cursor, c);
            }
        }

        for (auto c : L) cout << c;
        cout << '\n';
    }

}