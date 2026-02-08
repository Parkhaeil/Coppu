#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define x first
#define y second
int dx[8]={-2,-2,-1,1,-1,1,2,2};
int dy[8]={-1,1,-2,-2,2,2,-1,1};
int minDist[301][301];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int l;
        cin >> l;
        for (int i=0;i<l;i++) {
            for (int j=0;j<l;j++) {
                minDist[i][j]=-1;
            }
        }
        queue<pair<int,int>> q;
        // 나이트 시작 위치 입력 받고 큐에 넣기
        pair<int,int> st;
        cin >> st.x >> st.y;
        q.push({st.x,st.y});
        minDist[st.x][st.y]=0;
        // 원하는 도착 위치
        pair<int,int> en;
        cin >> en.x >> en.y;
        while(!q.empty()) {
            auto cur=q.front(); q.pop();
            // 원하는 위치에 도착했을 때
            if (cur.x==en.x && cur.y==en.y) break;
            for (int dir=0;dir<8;dir++) {
                int nx=cur.x+dx[dir];
                int ny=cur.y+dy[dir];
                if (nx<0||nx>=l||ny<0||ny>=l) continue;
                if (minDist[nx][ny]!=-1) continue;
                minDist[nx][ny]=minDist[cur.x][cur.y]+1;
                q.push({nx,ny});
            }
        }
        cout << minDist[en.x][en.y] << '\n';
    }
}