#include <iostream>
using namespace std;

/*
고려해야할점
 ->  6과 9를 포함한 경우
	- 6과 9를 같은 숫자로 보고 한 세트에 2개씩 있다고 생각한다.

결국 하나의 수가 몇번 등장하는지 
그중에 등장 횟수의 최댓값이 세트의 개수가 된다.
6/9 의 경우 모두 인덱스 6의 개수를 증가 시킨다.

따라서 인덱스 6의 배열값은 1,2 -> 1, 3,4->2, 5,6->3
짝수이면 /2 , 홀수이면 /2 + 1 값..
*/
int main() {
	string N; // 숫자를 string 으로 받는다.
	cin >> N;

	int arr[9] = {}; // 9 의 경우 6에 더한다.

	for (auto c : N) {
		if (c == '9') {
			arr[6]++;
			continue;
		}
		arr[c - '0']++; // 이렿게 되면 char '0' -> 0 번째 인덱스 증가.
	}

	// 홀수일 경우
	if (arr[6] % 2) arr[6] = arr[6] / 2 + 1;
	else arr[6] = arr[6] / 2;

	int max_num = 0;
	for (int i = 0; i < 9; i++) {
		max_num = max(arr[i], max_num);
	}

	cout << max_num;

}