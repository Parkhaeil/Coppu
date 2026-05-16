#include <string>
#include <vector>
#include <queue>
using namespace std;
int ans = 0;

bool isTarget(vector<int>& v, int target, vector<string> op) {
    int sum=0;
    for (int i=0;i<op.size();i++) {
        if (op[i]=="-") sum-=v[i];
        else sum+=v[i];
    }
    if (sum==target) return true;
    else return false;
}

void func(vector<int>& v, int target,vector<string> op) {
    if (op.size()==v.size()) {
        if (isTarget(v,target,op)) ans++;
        return;
    }
    op.push_back("+");
    func(v, target, op);
    op.pop_back();

    op.push_back("-");
    func(v, target, op);
    op.pop_back();
}

int solution(vector<int> numbers, int target) {
    vector<string> op;
    func(numbers,target,op);
    return ans;
}