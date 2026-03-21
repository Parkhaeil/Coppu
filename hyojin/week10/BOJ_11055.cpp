#include<bits/stdc++.h>
using namespace std;
int num[1001];
int D[100001];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        int k;
        cin >> k;
        num[i]=k;
    }
    D[0]=num[0];
    for (int i=1;i<n;i++) {
        // D[i]=num[i]까지 증가하는 수열의 합
        // j까지의 최대는 이미 D[j]에 들어있으니까
        // 거기에 num[i] 더하면 됨
        D[i]=num[i];
        for (int j=0;j<i;j++) {
            if (num[j]<num[i]) {
                D[i]=max(D[i],D[j]+num[i]);
            }
        }
    } 
    int mx=D[0];
    for (int i=1;i<n;i++) {
        mx=max(mx,D[i]);
    } 
    cout << mx;
}

/*
1912(연속 부분합)은 "연속"이라는 조건 때문에 직전이 i-1 하나뿐이었어.
근데 이 문제는 연속이 아니라 부분수열이야. 
그러면 i 앞에 올 수 있는 게 j=0, 1, 2, ... i-1 전부 가능해. 
그래서 직전 하나만 보면 안 되고 전부 확인해야 하는 거야.
"연속" → 직전 하나만
"부분수열" → 이전 전부 확인
*/