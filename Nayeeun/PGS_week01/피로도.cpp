#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int k,int cnt, vector<vector<int>>& dungeons,vector<bool>& visited){
    int Max = cnt;
    for(int i=0; i<dungeons.size(); i++) {
        int min_need=dungeons[i][0];
        int consume= dungeons[i][1];

        if(visited[i]==false && k>=min_need) {
            visited[i] = true;
            Max = max(Max, dfs(k-consume, cnt+1,dungeons,visited));
            visited[i] = false;
        }
    }
    return Max;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(),false);
    int answer = dfs(k,0,dungeons,visited);
    return answer;
}
