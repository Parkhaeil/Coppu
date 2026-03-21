#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int sum, Max;
    cin >> sum;
    Max = sum;

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;

        sum = max(sum + x, x);
        Max = max(Max, sum);
    }
    cout << Max;
}
