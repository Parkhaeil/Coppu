#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> arr(20);

	for (int i = 0; i < 20; i++) {
		arr[i] = i + 1;
	}

	int a, b;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		reverse(arr.begin() + a-1, arr.begin() + b);
	}

	for (auto& a : arr) {
		cout << a << ' ';
	}
}