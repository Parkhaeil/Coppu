#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int max = 0;
	int n, idx=0;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		if (n > max) {
			max = n;
			idx = i + 1;
		}
	}
	cout << max << "\n" << idx;
	return 0;
}
