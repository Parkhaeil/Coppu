#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	vector<int> arr;
	
	int num;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	
	int sum = accumulate(arr.begin(), arr.end(), 0);
	cout << sum / 5 << '\n' << arr[2];

}