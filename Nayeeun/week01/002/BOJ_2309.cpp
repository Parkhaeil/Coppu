#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9] = { 0 };
	int sum = 0;
	for (int &a : arr) {
		cin >> a;
		sum += a;
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if ((sum - arr[i] - arr[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << arr[k] << "\n";
				}
				return 0;
			}
		}
	}
	return 0;
}
