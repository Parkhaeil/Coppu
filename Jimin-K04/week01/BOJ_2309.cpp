#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr(9);
	int sum;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			vector<int> seven_tall;
			sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j) {
					sum += arr[k];
					seven_tall.push_back(arr[k]);
				}
			}
			if (sum == 100) {
				sort(seven_tall.begin(), seven_tall.end());
				for (auto t : seven_tall) cout << t << '\n';
				return 0;
			}
		}
	}
}