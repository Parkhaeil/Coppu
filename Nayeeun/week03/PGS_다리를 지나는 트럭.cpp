#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    int w = 0;

    int idx = 0;

    while (idx < truck_weights.size()) {
        answer++;

        w -= bridge.front();
        bridge.pop();

        if (w + truck_weights[idx] <= weight) {
            w += truck_weights[idx];
            bridge.push(truck_weights[idx]);
            idx++;
        }
        else bridge.push(0);
    }
    answer += bridge_length;
    return answer;
}
