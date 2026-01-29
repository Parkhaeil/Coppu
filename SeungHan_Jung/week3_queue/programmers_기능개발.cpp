#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;
    
    
    for(int i = 0 ; i < progresses.size() ; i++){
        int day = (100 - progresses[i] + speeds[i] -1)/speeds[i]; 
        // 신기한 방법의 연산 -> 덜 귀찮음
        if(!Q.empty() && Q.front() < day){
            //cout << "Q.front  = " << Q.front() << "\n";
            answer.push_back(Q.size());
            while(Q.size()){
                Q.pop();
            }
        }
        Q.push(day);       
    }
    answer.push_back(Q.size());
    return answer;
}
