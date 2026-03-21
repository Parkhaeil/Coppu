#include<bits/stdc++.h>
using namespace std;
int D[40][2];
// D가 i일때 0 개수, 1 개수 저장
// D[2]=D[1]+D[0]->D[2][0]=D[0][0]=1,D[2][1]=D[1][1]=1
// D[3]=D[2]+D[1]->D[3][0]=D[2][0]+D[1][0]

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=0;i<40;i++) {
            for (int j=0;j<2;j++)
                D[i][j]=0;
        }
        D[0][0]=1; D[0][1]=0;
        D[1][1]=1; D[1][0]=0;
        for (int i=2;i<=n;i++) {
            D[i][0]=D[i-1][0]+D[i-2][0];
            D[i][1]=D[i-1][1]+D[i-2][1];
        }
        cout << D[n][0] << ' ' << D[n][1] << '\n';
    }
}