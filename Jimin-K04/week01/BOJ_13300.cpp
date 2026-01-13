#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// 인덱스가 학년, 값은 학년별 학생수
	vector<int> male(6);
	vector<int> female(6);

	int N, K, s, y, cnt = 0;

	cin >> N >> K;

	while (N--) {
		cin >> s >> y;
		if (s) {
			if (!male[y - 1]) cnt++;
			male[y - 1]++;
			if (male[y - 1] > K) {
				cnt++;
				male[y - 1] -= K;
			}
		}
		else {
			if (!female[y - 1]) cnt++;
			female[y - 1]++;
			if (female[y - 1] > K) {
				cnt++;
				female[y - 1] -= K;
			}
		}
	}
	cout << cnt;
}