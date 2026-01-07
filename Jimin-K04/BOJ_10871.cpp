#include <iostream>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;

	int num;
	while(N--) {
		cin >> num;
		if (num < X) cout << num << " ";
	}

}