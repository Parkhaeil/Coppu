#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> idx;
    vector<int> result;
    for (int i=0;i<priorities.size();i++) {
        idx.push(i);
    }
    while(!idx.empty()) {
        int now_idx=idx.front();
        if (priorities[now_idx]!=*max_element(priorities.begin(), priorities.end())) {
            idx.pop();
            idx.push(now_idx);
        }
        else {
            result.push_back(now_idx);
            idx.pop();
            priorities[now_idx] = 0;
        }
    }
    for (int i=0;i<result.size();i++) {
        if (result[i]==location) {
            return i+1;
        }
    }
}
