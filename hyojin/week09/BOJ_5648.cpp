#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long arr[1000001];

long long back(string num) {
    // reverse함수도 잇음
    for (int i=0;i<num.length()/2;i++) {
        swap(num[i],num[num.length()-i-1]);
    }
    // string -> long long 으로 변환하는 함수
    return stoll(num);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for (int i=0;i<n;i++) {
        string num;
        cin >> num;
        arr[i]=back(num);
    }
    sort(arr,arr+n);
    for (int i=0;i<n;i++) {
        cout << arr[i] << '\n';
    }
}