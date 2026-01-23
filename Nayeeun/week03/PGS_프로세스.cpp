#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<int> q;
    
    for(int i=0;i<priorities.size();i++){
        pq.push(priorities[i]);
        q.push(i);
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(priorities[top] < pq.top()) q.push(top);
        else{
            answer++;
            pq.pop();
            if(top == location) break;
        }
    }
    
    return answer;
}
