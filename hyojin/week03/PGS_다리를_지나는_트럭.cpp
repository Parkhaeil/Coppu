#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int t=0;
    int wait=0;
    int now_weights=0;
    queue<pair<int,int>> passing;

    while(true) {
        if (wait < truck_weights.size() &&
            now_weights+truck_weights[wait]<=weight) {
            passing.push({truck_weights[wait],t+bridge_length});
            now_weights+=truck_weights[wait];
            wait++;
        }
        t++;
        if (wait==truck_weights.size() && passing.empty()) {
            break;
        }
        if (passing.front().second==t) {
            now_weights-=passing.front().first;
            passing.pop();
        }
    }
    return t;
}
