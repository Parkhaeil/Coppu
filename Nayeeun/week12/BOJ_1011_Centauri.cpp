#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long x, y;
        cin >> x >> y;

        long long d = y - x;

        long long k = 1;
        while (k * k <= d) k++;
        k--;

        int move = 0;
        long long sum = 0;
        int step = 1;

        while (step <= k) {
            sum += step;
            move++;
            if (sum >= d) break;
            sum += step;
            move++;
            step++;
        }
        if (sum < d) move++;
        cout << move << '\n';
    }
}
