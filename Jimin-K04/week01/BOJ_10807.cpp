#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int len, num;
	cin >> len;
	
	vector<int> nums(len);
	
	for (int i = 0; i < len; i++) cin >> nums[i];

	cin >> num;

	cout << count(nums.begin(), nums.end(), num);

}