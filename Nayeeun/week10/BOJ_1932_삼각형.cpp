#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            int x;
            cin >> x;

            if (j == 0)
                dp[0] = dp[j] + x;
            else if (i == j)
                dp[j] = dp[j - 1] + x;
            else
                dp[j] = max(dp[j], dp[j - 1]) + x;
        }
    }
    int Max = 0;
    for (int i = 0; i < n; i++) {
        Max = max(Max, dp[i]);
    }
    cout << Max;
}
