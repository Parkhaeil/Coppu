#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int mx=0;
bool visited[10];

// 벡터 원본 참조
void func(const vector<vector<int>>& v,int k,int num) {
    mx=max(mx,num);
    for (int i=0;i<v.size();i++) {
        if (!visited[i]) {
            if (k<v[i][0]) { 
                continue;
            }
            visited[i]=true;
            func(v,k-v[i][1],num+1);
            visited[i]=false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    func(dungeons,k,0);
    return mx;
}