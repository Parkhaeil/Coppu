#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> arr(N);
	int idx = 0;
	int people = N;
	for (int i = 0; i < N; i++) arr[i] = i+1;

	cout << "<";
	while (N--) {
		idx = (idx + K - 1) % people;
		cout << arr[idx];
		people--;
		if (people > 0) cout << ", ";
		for (int i = idx; i < people; i++)
			arr[i] = arr[i + 1];
	}
	cout << ">";
}
