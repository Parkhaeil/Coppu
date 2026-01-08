#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[21];
	for (int i = 1; i < 21; i++) {
		arr[i] = i;
	}
	int cnt = 10;
	int start, end;
	while (cnt--) {
		cin >> start >> end;
		reverse(arr+start, arr+end+1);
	}
	for (int i = 1; i < 21; i++) {
		cout << arr[i] << " ";
	}
}
