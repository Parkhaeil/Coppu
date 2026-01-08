#include <iostream>
#include <vector>
using namespace std;

vector<int> make_arr(string str) {
	int len = str.length();
	vector<int> arr(26,0);
	for (int i = 0; i < len; i++) {
		int alpah = str[i] - 97;
		arr[alpah]++;
	}
	return arr;
}

int main() {
	int n;
	string a, b;

	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a.length() != b.length()) {
			cout << "Impossible\n";
			continue;
		}
		vector<int> arr1 = make_arr(a);
		vector<int> arr2 = make_arr(b);
		if (arr1 == arr2) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}
