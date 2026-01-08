#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	int arr[10] = {};

	cin >> A >> B >> C;
	
	int mul = A * B * C;
	
	while (mul > 0) {
		arr[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++) cout << arr[i] << '\n';
}