#include<iostream>
using namespace std;
string board[64];

void func(int n, int x, int y) {
    bool flag=true;
    for (int i=x;i<x+n;i++)
        for (int j=y;j<y+n;j++) 
            if (board[i][j]!=board[x][y]) flag=false;
    if (flag) {
        cout << board[x][y];
        return;
    }
    // if 문 안에 '(' 넣음
    // => 괄호 위치 사분면 쪼개기 바로 전 (0->(01->(011->(0110..
    cout << '(';
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            func(n/2,x+i*n/2,y+j*n/2);
    cout << ')';
}

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> board[i];
    func(n,0,0);
}