#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, v;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> v;
	int cnt = count(arr.begin(), arr.end(), v);
	cout << cnt;
}
