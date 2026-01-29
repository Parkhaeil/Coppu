#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weight = 0;

    queue<int> q,road;
    
    for(int truck : truck_weights){
        q.push(truck);
    }
    
    int current = q.front();
    
    while(1){
        // 조건이 맞으면 pop 시키고 , 항상 
        answer++;
        
        if(road.size()==bridge_length){
            //cout << "꽉 차서 road 하나 pop"<< "\n";
            total_weight -= road.front();
            road.pop();
            answer--;
        }else{
            if(!q.empty()) current = q.front(); // 이미 q 가 비었을때 갱신되면 nullptr이 되니까 이 구문을 걸어놓은 거임.
            if((!q.empty()) && (total_weight + current <= weight)){
                total_weight += current;
                //cout << "weight 추가" << total_weight << "\n";
                road.push(current);
                q.pop();
            }else if(!q.empty()){
                //cout << "그냥 0 추가"<< "\n";
                road.push(0);
            }else{
                // q가 아예 비었을떄 -> 이제 빼기만 해야지.
                return answer + bridge_length -1;
            }
        }
    }
}

// [7] | answer = 1
// [7,0] | answer = 2
// [0] | answer = 3
// [0,4] | answer = 4 가 아닌 3이 되어야 함 -> answer --  가 있는 이유
