#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int cnt = 0;
	int arr[2][7] = { 0 };
	while (N--) {
		int S, Y;
		cin >> S >> Y;
		arr[S][Y]++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			cnt += (arr[i][j] + K - 1) / K;
		}
	}
	cout << cnt;
}
