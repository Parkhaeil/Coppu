#include<bits/stdc++.h>
using namespace std;
int num[100001];
int D[100001];

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> num[i];
    }
    int mx=INT_MIN;
    /*
    예를 들어 연속 부분합 문제에서 i번째 원소를 볼 때
    이 원소가 어떤 구간의 끝이라고 치면 직전에 뭘 했을까?
        이전 구간에 붙었거나 → D[i-1] + a[i]
        여기서 새로 시작했거나 → a[i]
    */
    for (int i=0;i<n;i++) {
        D[i]=max(num[i],D[i-1]+num[i]);
        mx=max(mx,D[i]);
    }
    cout << mx;
}