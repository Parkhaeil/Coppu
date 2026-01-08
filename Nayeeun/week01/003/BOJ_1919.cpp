#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	
	int arr[26] = { 0 };
	for (char &c : str1) arr[c - 97]++;
	for (char &c : str2) arr[c - 97]--;

	int cnt = 0;
	for (int& i : arr) {
		cnt += abs(i);
	}
	cout << cnt;
}
