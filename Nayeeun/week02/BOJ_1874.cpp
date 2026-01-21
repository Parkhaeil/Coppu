#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, idx = 1;
	cin >> n;
	
	stack<int> num;
	vector<char> ans;
	while (n--) {
		int t;
		cin >> t;
		while (idx <= t) {
			num.push(idx++);
			ans.push_back('+');
		}

		if (num.top() != t) {
			cout << "NO";
			return 0;
		}

		num.pop();
		ans.push_back('-');
	}
	for (char a : ans) cout << a << "\n";
	return 0;
}
