#include <iostream>
using namespace std;

int fib0[41];
int fib1[41];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    fib0[0] = 1;
    fib0[1] = 0;
    fib1[0] = 0;
    fib1[1] = 1;

    for (int i = 2; i <= 40; i++) {
        fib0[i] = fib0[i - 1] + fib0[i - 2];
        fib1[i] = fib1[i - 1] + fib1[i - 2];
    }

    while (T--) {
        int n;
        cin >> n;
        cout << fib0[n] << " " << fib1[n] << '\n';
    }
}
