#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

// cursor 는 현재 커서의 오른쪽을 가리킨다.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    list<int> arr;
    for (int i = 1; i <= N; i++) arr.push_back(i);

    list<int>::iterator it = arr.begin();
    cout << '<';
    while (!arr.empty()) {
        for (int i = 1; i < K; i++) {
            it++;
            if (it == arr.end()) it = arr.begin();
        }
        if (arr.size() == 1) break;
        cout << *it << ", ";
        it = arr.erase(it);
        if (it == arr.end()) it = arr.begin();
    }
    cout << *it << '>';

}