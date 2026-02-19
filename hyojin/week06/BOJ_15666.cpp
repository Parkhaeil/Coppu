#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int num[8];
int arr[8];

void func(int k, int st) {
    if (k==m) {
        for (int i=0;i<m;i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int last=0;
    for (int i=st;i<n;i++) {
        if (num[i]!=last) {
            arr[k]=num[i];
            last=arr[k];
            func(k+1,i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++)
        cin >> num[i];
    sort(num,num+n);
    func(0,0);
}