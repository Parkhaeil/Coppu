#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> dayStock(n);
        for (int i=0;i<n;i++) {
            cin >> dayStock[i];
        }
        long long p=0,mx=0;
        // => 뒤에서부터 시작해서 최대가격 저장
        for (int i=n-1;i>=0;i--) {
            if (dayStock[i]>mx) {
                mx=dayStock[i];
            }
            else {
                int price=mx-dayStock[i];
                p+=price;
            }
        }
        cout << p << '\n';
    }
}
    /*
    while(t--) {
        int n,profit=0;
        cin >> n;
        vector<int> dayStock(n+1);
        for (int i=0;i<n;i++) {
            int price;
            cin >> price;
            dayStock[i]=price;
        }
        // i=0, j=2, 3>1 j=2에서 멈춤
        int i=0,sum=0;
        while (i<n) {
            int j=i;
            while (dayStock[j]<=dayStock[j+1]) {
                j++;
            }
            for (int i=0;i<j;i++) {
                int p=dayStock[j]-dayStock[i];
                sum+=p;
            }
        }
    }
     */