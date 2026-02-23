/*
현재 톱니바퀴에서 오른쪽 / 왼쪽으로 전파 / 회전방향 미리 저장 후 회전
*/
#include<iostream>
#include<deque>
using namespace std;
int dirContainer[4];
deque<int> dq[4];

int main() {
    for (int i=0;i<4;i++) {
        string s;
        cin >> s;
        for (int j=0;j<8;j++) {
            dq[i].push_back(s[j]-'0');
        }
    }
    int turn;
    cin >> turn;
    while(turn--) {
        for (int i=0;i<4;i++) {
            dirContainer[i]=0;
        }
        int idx,dir;
        cin >> idx >> dir;
        idx--;
        // 현재 톱니바퀴 방향 저장
        dirContainer[idx]=dir;
        // 왼쪽 전파
        for (int i=idx;i>0;i--) {
            if (dq[i-1][2]==dq[i][6]) break;
            dirContainer[i-1]=-dirContainer[i];
        }
        // 오른쪽 전파
        for (int i=idx;i<3;i++) {
            if (dq[i+1][6]==dq[i][2]) break;
            dirContainer[i+1]=-dirContainer[i];
        }
        // 회전
        for (int i=0;i<4;i++) {
            if (dirContainer[i]==1) {
                // 시계 방향
                dq[i].push_front(dq[i].back());
                dq[i].pop_back();
            }
            else if (dirContainer[i]==-1) {
                // 반시계 방향
                dq[i].push_back(dq[i].front());
                dq[i].pop_front();
            }
        }
    }
    int score=0;
    // 점수 계산
    if (dq[0][0]==1) score+=1;
    if (dq[1][0]==1) score+=2;
    if (dq[2][0]==1) score+=4;
    if (dq[3][0]==1) score+=8;
    cout << score;
}