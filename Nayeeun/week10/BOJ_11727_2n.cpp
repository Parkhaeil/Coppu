#include <iostream>
using namespace std;

/*
* 1 ->1
* 2->1+1+1->3
* 3->3+2->5
* 4->2+3+5+1->11
* 5->21
*/
int dp[1001];
int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }
    cout << dp[n];
}
