#include <bits/stdc++.h>
using namespace std;

int dist[305][305];

// 나이트 이동은 모든 간선의 비용이 1
// → BFS 사용 가능
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2,  2,  1, -1, -2,-2,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int size, sr, sc, dr, dc;
        cin >> size >> sr >> sc >> dr >> dc;

        // dist = -1 : 아직 방문하지 않음
        // BFS에서는 "첫 방문 순간"이 항상 최단 거리이므로
        // 이후 거리 비교나 재갱신은 필요 없음
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                dist[i][j] = -1;

        queue<pair<int,int>> q;

        // 시작점
        q.push({sr, sc});
        dist[sr][sc] = 0;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            // 목적지에 도달한 순간의 거리가 최단 거리
            if(r == dr && c == dc) break;

            for(int k = 0; k < 8; k++){
                int nr = r + dy[k];
                int nc = c + dx[k];

                if(nr < 0 || nr >= size || nc < 0 || nc >= size) continue;

                // 이미 방문했다면,
                // 그 칸은 더 짧은 거리로 먼저 방문된 상태이므로 스킵
                if(dist[nr][nc] != -1) continue;

                // 첫 방문 = 최단 거리 확정
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }

        cout << dist[dr][dc] << "\n";
    }
}
