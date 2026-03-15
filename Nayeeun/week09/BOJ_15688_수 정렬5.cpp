#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  int cnt[2000001];
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    cnt[x + 1000000]++;
  }

  for (int i = 0; i <= 2000000; i++) {
    while (cnt[i] > 0) {
      cout << i - 1000000 << "\n";
      cnt[i]--;
    }
  }
}
