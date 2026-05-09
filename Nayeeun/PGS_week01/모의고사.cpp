#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> m1 = {1,2,3,4,5};
    vector<int> m2 = {2,1,2,3,2,4,2,5};
    vector<int> m3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=0;i<answers.size();i++){
        int a = answers[i];
        if(a==m1[i%5]) cnt1++;
        if(a==m2[i%8]) cnt2++;
        if(a==m3[i%10]) cnt3++;
    }
    
    vector<int> cnts = {cnt1,cnt2,cnt3};
    int maxScore = *max_element(cnts.begin(),cnts.end());
    for(int i= 0; i <cnts.size();i++) {
        if(cnts[i] == maxScore) {
            answer.push_back(i+1);
        }
    }
    return answer;
}
