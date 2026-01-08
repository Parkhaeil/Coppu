#include <iostream>
#include <string>
using namespace std;

int main() {
	int arr[26] = { 0 };
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int alpah = str[i] - 97;
		arr[alpah]++;
	}
	for (auto& a : arr) cout << a << " ";
	return 0;
}
