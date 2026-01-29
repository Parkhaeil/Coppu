#include <iostream>
#include <queue>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	string cmd;
	int num, N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;

		if (cmd == "size") cout << q.size() << "\n";
		else if (cmd == "empty") cout << q.empty() << "\n";
		else if (cmd == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (cmd == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
		else if (cmd == "push") {
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
	}
}