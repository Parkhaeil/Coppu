#include<iostream>
#include<deque>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    deque<int> dq;
    for (int i=1;i<=n;i++) {
        dq.push_back(i);
    }
    int num=0;
    for (int i=0;i<m;i++) {
        int k;
        cin >> k;

        int idx=0;
        for (int j=0;j<dq.size();j++) {
            if (dq[j]==k) {
                break;
            }
            idx++;
        }
        // 연산 2
        if (idx <= dq.size()/2) {
            while(dq.front()!=k) {
                dq.push_back(dq.front()); dq.pop_front();
                num++;
            }
        } else { // 연산 3
            while(dq.front()!=k) {
                dq.push_front(dq.back()); dq.pop_back();
                num++;
            }
        }
        // 연산 1
        dq.pop_front();
    }
    cout << num;
}
