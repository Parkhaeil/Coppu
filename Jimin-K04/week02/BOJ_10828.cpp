#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> s;
	int n, num;
	string cmd;
	cin >> n;

	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop") {
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (cmd == "size") cout << s.size() << '\n';
		else if (cmd == "empty") {
			if (s.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "top") {
			if (s.empty()) cout << -1 << '\n';
			else cout << s.top() << '\n';
		}
		
	}
}