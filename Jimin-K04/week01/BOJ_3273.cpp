#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num, x;
	cin >> n;
	vector<int> occur(1000001);
	vector<int> arr(n);

	for (auto& c : arr) cin >> c;


	cin >> x;

	int cnt = 0;
	for (auto& c : arr) {
		if (x - c < 0 || x - c > 1000000) continue; // 예외처리..
		if (occur[x - c]) cnt++;
		occur[c] = 1;
	}

	cout << cnt;

}