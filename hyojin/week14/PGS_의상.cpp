#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 걍 종류마다 개수 곱하면 되는데 먼 dfs하느라 시간 낭비함..
int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    for (int i=0;i<clothes.size();i++) {
        m[clothes[i][1]]++;
    }
    int ans=1;
    for (auto i : m) {
        ans*=(i.second+1);
    }
    return ans-1;
}