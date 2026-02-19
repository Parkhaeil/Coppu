#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> given_list;
vector<int> result;

void BT(int start) {
    if (result.size() == 6) {
        for (int num : result) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < N; i++) {
        result.push_back(given_list[i]);
        BT(i + 1);          // 다음 인덱스부터 선택
        result.pop_back();  // 백트래킹
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> N;
        if (N == 0) break;

        given_list.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> given_list[i];
        }

        result.clear();
        BT(0);
        cout << '\n';
    }

    return 0;
}
