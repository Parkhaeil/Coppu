#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (q.size()>1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}

// 이건 수학적...?으로 접근한 코드
// 그냥 k=2인 요세푸스 풀 때랑 똑같은 경우라 그 공식 적용
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int i = 1;
	while (i * 2 <= N) {
		i *= 2;
	}
	if (i == N) cout << N;
	else cout << 2 * (N - i);
}
