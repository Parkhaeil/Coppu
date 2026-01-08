#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> alpha(26);
	string word;

	cin >> word;

	for (auto c : word) {
		alpha[c - 'a']++;
	}

	for (int& a : alpha) cout << a << ' ';

}