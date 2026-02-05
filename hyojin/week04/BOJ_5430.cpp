#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string func;
        cin >> func;
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        deque<int> dq;
        if (n>0) {
            int curNum=0;
            for (int i=1;i<arr.size();i++) {
                if (arr[i]==','||arr[i]==']') {
                    dq.push_back(curNum);
                    curNum=0;
                }
                else {
                    curNum = curNum*10 + arr[i]-'0';
                }
            }
        }
        bool revFlag=false;
        bool errorFlag=false;
        for (int i=0;i<func.size();i++) {
            // 뒤집기는 flag로 처리
            if (func[i]=='R') {
                revFlag=!revFlag;
            }
            else {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    errorFlag=true;
                    break;
                }
                if (revFlag) dq.pop_back();
                else dq.pop_front();
            }
        }
        // 출력
        if (!errorFlag) {
            // revFlag=true로 뒤집혀있으면 리버스 해주기
            if (revFlag) reverse(dq.begin(),dq.end());
            cout << '[';
            if (!dq.empty()) {
                while(dq.size()-1) {
                    cout << dq.front();
                    dq.pop_front();
                    cout << ',';
                }
                cout << dq.front();
            }
            cout << ']' << '\n';
        }
    }
}
