#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }
    while (q.size() > 1) {

        q.pop();

        if (q.size() > 0) {
            int move_card = q.front();
            q.pop();                  
            q.push(move_card);        
        }
    }

    cout << q.front() << "\n";

    return 0;
}