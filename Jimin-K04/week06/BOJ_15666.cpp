#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*일단 가로 길이를 받는다
가로 를 반으로 나누면 8 -> 4 0-3 : 왼쪽, 4-7 : 오른쪽
이렇게 2차원 배열을 받고 인덱스로 확인을 하는데 
함수 인자 : 확인할 범위의 가로 세로 길이, 시작 지점
만약 확인 도중에 다른 숫자가 발견된다면 ? -> 4지점으로 나눠서 다시 시작
-> 4지점으로 분기하는거지
그리고 return 조건은 모든 숫자가 일치 했을 때 
출력은
재귀 호출이 발생할 때마다 ( 열기 출력, 재귀호출 끝난 후에 ) 출력
그리고 return 조건과 함께 해당 숫자를 출력
*/

void recursive_f(int len, int row, int col, vector<vector<int>> arr) {
	int num = arr[row][col];
	for (int i = row; i < row+len; i++) {
		for (int j = col; j < col+len; j++) {
			if (arr[i][j] != num) {
				cout << '(';
				recursive_f(len / 2, row, col , arr);
				recursive_f(len / 2, row, col + len/2, arr);
				recursive_f(len / 2, row + len/2, col, arr);
				recursive_f(len / 2, row + len/2, col + len/2, arr);
				cout << ')';
				return;
			}
		}
	}
	cout << num;
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string line;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) arr[i][j] = line[j] - '0';
	}

	recursive_f(n, 0, 0, arr);
}