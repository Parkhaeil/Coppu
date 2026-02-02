#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);

    int answer = 0;

    while (m--) {
        int num;
        cin >> num;

        int target = 0;
        while (dq[target] != num) target++;

        int size = dq.size();

        if (target <= size/2) {
            for (int i = 0; i < target; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
                answer++;
            }
        }
        else {
            int right = size - target;
            for (int i = 0; i < right; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
                answer++;
            }
        }

        dq.pop_front();
    }

    cout << answer;
}
