#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct cmp{
    bool operator()(pair<int, int> &a, pair<int,int> &b){
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    
};
int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    
    for (int i = 0; i < priorities.size(); i++){
        pq.push({i, priorities[i]});
    }
    
    while(pq.size() > 0){
        auto p = pq.top();
        if (p.first == location) break;
        answer++;
        pq.pop();
    }
    return answer;
}