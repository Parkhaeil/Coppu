#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> p;
    
    for(int i = 0 ; i < priorities.size() ; i++){
        pq.push(priorities[i]);
        p.push({i,priorities[i]});
    }
    
    while(!p.empty()){
        auto out = p.front();
        p.pop();
        if(out.second == pq.top()){
            //cout << " "<< out.second << " " << out.first;
            answer++;
            if(out.first == location){
                return answer;
            }else{
                pq.pop();
            }
        }else{
            // out 으로 나온 값이 pq.front()의 값보다 무조건 작은 경우겠지(더 큰 경우는 없음)
            p.push(out);
        }
    }

    return answer;
}
