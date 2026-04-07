#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최댓값이 9876543210 이구나.. 너무 복잡하게 생각할 필요가 없는 문제인가..?
long long n;
vector<long long> v;

int main() {
    cin >> n;

    long long stack[1050];
    int top = -1;

    for (int i = 0; i <= 9; i++) {
        stack[++top] = i;
    }

    while (top >= 0) {
        long long num = stack[top--];

        v.push_back(num);

        int last = num % 10;

        for (int i = 0; i < last; i++) {
            stack[++top] = num * 10 + i;
        }
    }

    sort(v.begin(), v.end());

    if (n >= v.size()) cout << -1;
    else cout << v[n];

    return 0;
}
