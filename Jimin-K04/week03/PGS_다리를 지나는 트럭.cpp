#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;            
    int current_weight = 0;     
    int truck_idx = 0;         
    queue<int> bridge;         
    
    while (truck_idx < truck_weights.size()) {
        time++; 
        
        if (bridge.size() == bridge_length) {
            current_weight -= bridge.front();
            bridge.pop();
        }
 
        if (current_weight + truck_weights[truck_idx] <= weight) {
            bridge.push(truck_weights[truck_idx]); 
            current_weight += truck_weights[truck_idx];
            truck_idx++;
        } else {
            bridge.push(0); 
        }
    }

    return time + bridge_length;
}