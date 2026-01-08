#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	int time;
	int Y = 0, M = 0;
	while (N--) {
		cin >> time;
		Y += (time / 30 + 1) * 10;
		M += (time / 60 + 1) * 15;
	}
	if (Y < M) cout << "Y " << Y;
	else if (Y > M) cout << "M " << M;
	else cout << "Y M " << M;
	
	return 0;
}
