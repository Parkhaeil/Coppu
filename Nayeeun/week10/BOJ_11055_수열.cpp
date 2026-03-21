#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[1001];
    int dp[1001];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int Max = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = a[i];

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + a[i]);
        }

        Max = max(Max, dp[i]);
    }

    cout << Max;
}
