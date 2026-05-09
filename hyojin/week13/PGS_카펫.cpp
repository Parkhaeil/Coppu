#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int k=brown+yellow;
    for (int i=3;i<=sqrt(k);i++) {
        int n=k/i;
        if ((n-2)*(i-2)==yellow) {
            answer.push_back(n);
            answer.push_back(i);
            break;
        }
    }
    sort(answer.begin(),answer.end(),greater<int>());
    // 4 6+2 8*2=16+4*2=24
    // (8-2)*(6-2)=24, 
    return answer;
}