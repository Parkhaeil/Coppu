#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	cin >> x;

	int left = 0, right = n - 1;
	int cnt = 0;
	while (left < right) {
		int sum = arr[left] + arr[right];
		if (sum == x) {
			cnt++;
			left++;
			right--;
		}
		else if (sum < x)left++;
		else right--;
	}
	cout << cnt;
}
