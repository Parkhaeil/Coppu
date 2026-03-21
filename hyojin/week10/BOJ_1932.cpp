#include<bits/stdc++.h>
using namespace std;
int num[500][500];
int D[500][500];
/*
(2,1) 칸에 도착하는 경로가 두 개 있을 때
7→3→1 = 11
7→8→1 = 16
여기서 11인 경로는 어차피 16인 경로를 못 이김(남은 경로가 동일)

=> 위에서 아래로 내려가는게 아니라 해당 칸에서의 최대값을 생각하면 됨!!
*/

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<i+1;j++)
            cin >> num[i][j];
    }
    // 인덱스 넣을때 i번째 선택 후의 결과x
    // D[i][j] => 삼각형 i층 j번째 칸까지의 최대합
    D[0][0]=num[0][0];
    for (int i=1;i<n;i++) {
        for (int j=0;j<i+1;j++) {
            // 양쪽에 있는 애들은 인덱스 안 벗어나게 따로 처리
            if (j==0) D[i][j]=num[i][j]+D[i-1][0];
            else if (j==i) D[i][j]=num[i][j]+D[i-1][i-1];
            else D[i][j]=max(D[i-1][j-1],D[i-1][j])+num[i][j];
        }
    } 
    int mx=0;
    for (int i=0;i<n;i++) {
        mx=max(mx,D[n-1][i]);
    }
    cout << mx;
}