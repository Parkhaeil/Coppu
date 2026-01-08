#include <iostream>
using namespace std;

int main() {
	int arr[10] = { 0 };
	int A, B, C;
	int result;
	cin >> A >> B >> C;

	result = A * B * C;
	while (result) {
		int alpah = result % 10;
		arr[alpah]++;
		result /= 10;
	}
	for (auto& a : arr) cout << a << "\n";
	return 0;
}
