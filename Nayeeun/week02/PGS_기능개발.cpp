#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> time;
    for (int i = 0; i < progresses.size(); i++) {
        int t = (100 - progresses[i]);
        t = (t + speeds[i] - 1) / speeds[i];
        time.push_back(t);
    }
    int idx = 0;
    int cnt = 1;
    for (int i = 1; i < progresses.size(); i++) {
        if (time[idx] >= time[i]) {
            cnt++;
        }
        else {
            idx = i;
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}
