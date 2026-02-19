/*
별 채워놓고 공백으로 지우기
=> 공백으로 지워놓고 별 찍기

=> 재귀 문제는 n을 계속 나누고 한칸 됬을떄 어떤걸 하느냐가 핵심인듯
*/
#include<iostream>
using namespace std;
//string board[2187][2187];
//=>char로 메모리 절약
char board[2187][2187];

void func(int n,int x,int y) {
    if (n==1) {
        // => 한칸되면 별 찍기
        board[x][y]='*';
        return;
    }
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            // => 정중앙 정사각형
            if (i==1 && j==1) continue;
            else func(n/3,x+i*n/3,y+j*n/3);
        }
    }
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            board[i][j]=' ';
        }
    }
    func(n,0,0);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
} 