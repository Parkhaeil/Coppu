#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B;
	cin >> A >> B;
			
	if (A == B || B - A == 1) {
		cout << 0;
		return 0;
	}

	if (A > B) swap(A, B);

	A++;
	cout << B - A << '\n';

	for (; A < B; A++) {
		cout << A << ' ';
	}
}