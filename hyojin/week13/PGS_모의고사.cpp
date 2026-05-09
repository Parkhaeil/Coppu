#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    // 5 , 8, 10
    int stud1[5]={1,2,3,4,5};
    int stud2[8]={2, 1, 2, 3, 2, 4, 2, 5};
    int stud3[10]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int stud_sum[3]={0,}; 
    for (int i=0;i<answers.size();i++) {
        if (stud1[i%5]==answers[i])
            stud_sum[0]+=1;
        if (stud2[i%8]==answers[i])
            stud_sum[1]+=1;
        if (stud3[i%10]==answers[i])
            stud_sum[2]+=1;
    }
    vector<int> ans;
    int mx=max(stud_sum[0],max(stud_sum[1],stud_sum[2]));
    for (int i=0;i<3;i++) {
        if (stud_sum[i]==mx) {
            ans.push_back(i+1);
        }
    }
    return ans;
}