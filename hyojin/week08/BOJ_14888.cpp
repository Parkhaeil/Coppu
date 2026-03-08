/*
이 문제에선 현재 깊이를 인덱스로 사용해야함.
depth (Level): 우리가 해결해야 할 단계 (총 N-1번의 선택)
i (Choice): 각 단계에서 우리가 선택할 수 있는 옵션. (+, -, *, /)
*/
#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;
int n;
int num[12];
int oper[4];
int mx=-INT_MIN, mn=INT_MAX;
char temp[12];

void solve() {
    int result=num[0];
    for (int i=0;i<n-1;i++) {
        if (temp[i]=='+') result+=num[i+1];
        if (temp[i]=='-') result-=num[i+1];
        if (temp[i]=='*') result*=num[i+1];
        if (temp[i]=='/') result/=num[i+1];
    }
    mx=max(mx,result);
    mn=min(mn,result);
}

void func(int depth) {
    if (depth==n-1) {
        solve();
        return;
    }
    for (int i=0;i<4;i++) {
        if (oper[i]>0) {
            // => 현재 깊이를 인덱스로 써야함!!
            if (i==0) temp[depth]='+';
            else if (i==1) temp[depth]='-';
            else if (i==2) temp[depth]='*';
            else if (i==3) temp[depth]='/';
            oper[i]--;
            func(depth+1);
            oper[i]++;
        }
        
    }
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> num[i];
    }
    for (int i=0;i<4;i++) {
        cin >> oper[i];
    }
    func(0);
    cout << mx << '\n' << mn;
}