/*
입력된 숫자와 스택의 top 값을 비교한다
1. 같을 경우 pop
2. top 이 작을 경우 -> 같아질 때까지 push
3. top 이 클 경우 -> No 출력
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> s;
	int n, num;
	string ans;
	cin >> n;

	int i = 1;
	while (n--) {
		cin >> num;
		while (i <= num) {
			s.push(i++);
			ans += "+\n";
		}
		if (s.top() > num) {
			cout << "NO";
			return 0;
		}
		s.pop();
		ans += "-\n";
	}
	cout << ans;
}