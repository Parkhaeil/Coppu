#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		string ord, str;
		int n;
		deque<int> dq;

		cin >> ord;
		cin >> n >> str;

		string num;
		for (char c : str) {
			if (c == '[') continue;
			if (c == ',' || c == ']') {
				if (!num.empty()) {
					dq.push_back(stoi(num));
                    num = "";
				}
			}
			else num += c;
		}

        bool reverse = false;
        bool error = false;

        for (char c : ord) {
            if (c == 'R') reverse = !reverse;
            else {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (reverse) dq.pop_back();
                else dq.pop_front();
            }
        }
        if (error) {
            cout << "error\n";
            continue;
        }

        int size = dq.size();

        cout << '[';
        if (reverse) {
            for (int i = size - 1; i >= 0; i--) {
                cout << dq[i];
                if (i != 0) cout << ",";
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                cout << dq[i];
                if (i != size - 1) cout << ",";
            }
        }
        cout << "]\n";
    }
}
