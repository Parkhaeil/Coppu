#include <iostream>
using namespace std;

int main() {
	int arr[10] = { 0 };
	int num;
	cin >> num;

	int max = 0;
	while (num) {
		int i = num % 10;
		arr[i]++;
		num /= 10;
		if (i == 6 || i == 9) continue;
		if (arr[i] > max){
			max = arr[i];
		}
	}
	int result = (arr[6] + arr[9] + 1) / 2;
	if (max > result) result = max;
	cout << result;
	return 0;
}
