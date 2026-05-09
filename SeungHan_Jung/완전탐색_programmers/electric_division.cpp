#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>

using namespace std;
int answer = -1;
set<int> contained;
map<int,vector<int>> graph;
stack<int> s;
int total = 0;

// 끊을 수 있는 전선의 개수가 정해져 있으므로 상태공간이 유한하다
// dfs 함수를 통해 전선을 하나씩 끊고 각 끊은 경우에 대해 끊어진 그 전선의 한쪽 끝에서 출발을 해서 , 각 wire 을 돌면서 그 한쪽 끝이 wire의 두 끝 점 중에 하나라도 포함된 경우 해당 wire의 반대쪽 edge 를 우리 집단에 포함시키고 , 들어올때마다 visited[] 의 해당 값을 false 로 추가시키고 더 이상 늘어나지 않으면 종료하는 그런 느낌? 
void count(vector<vector<int>> wires , int i){
    // 특정 선을 끊음 -> wire 의 번호가 i 임
    contained.insert(wires[i][0]); // 항상 wires의 두 끝 점 중 앞에 걸로 간다
    for(int j = 0 ; j < graph[wires[i][0]].size() ; j++){
        s.push(graph[wires[i][0]][j]);// 스택은 push , pop 만 있지   
    }
    while(!s.empty()){
        int cur = s.top(); // s의 인자는 점의 번호니까
        s.pop();
        for(int j = 0 ; j < graph[cur].size() ; j++){
            contained.insert(graph[cur][j]);
            s.push(graph[cur][j]);
        }
    }
    answer = max(answer , total - int(contained.size()));
}

int solution(int n, vector<vector<int>> wires) {
    total = n;
    for(int i = 1 ; i <= n ; i++){
        graph.insert({i,vector<int>()}); // vector<자료형>() 은 빈 벡터 생성!!
    }
    for(int i = 0 ; i < wires.size() ; i++){
        graph[wires[i][0]].push_back(wires[i][1]);
    }
    for(int i = 0 ; i < wires.size(); i++){ // 각 간선은 끊어짐을 당했는가 - 큰 틀
        contained.clear();
        count(wires,i);
    }
    return answer;
}
