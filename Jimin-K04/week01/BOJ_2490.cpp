#include <iostream>
using namespace std;

int main() {
	int n = 3, cnt_zero, num;

	while (n--) {
		cnt_zero = 0;
		for (int i = 0; i < 4; i++) {
			cin >> num;
			if (!num) cnt_zero++;
		}
		switch (cnt_zero)
		{
		case 1:
			cout << "A\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "C\n";
			break;
		case 4:
			cout << "D\n";
			break;
		case 0:
			cout << "E\n";
			break;
		default:
			break;
		}
	}
}