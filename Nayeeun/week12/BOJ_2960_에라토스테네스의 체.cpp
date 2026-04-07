#include <iostream>

using namespace std;

int arr[1001];
int main() {
    int n, k;
    cin >> n >> k;

    int cnt = 0;

    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {
            for (int j = i; j <= n; j += i) {
                if (arr[j] == 0) {
                    arr[j] = 1;
                    cnt++;

                    if (cnt == k) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
}
