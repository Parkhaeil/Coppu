#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<int> nums;
bool isPrime(int n){
    if(n<2)
        return false;

    for(int i=2; i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

void dfs(string numstr, string numbers, vector<bool>& visited) {
    if(numstr != ""){
        nums.insert(stoi(numstr));
    }
    for(int i=0;i <numbers.size();i++){
        if(visited[i]==false){
            visited[i]=true;
            dfs(numstr+numbers[i],numbers,visited);
            visited[i]=false;
        }
    }
}

int solution(string numbers) {
    vector<bool> visited(numbers.size(), false);
    dfs("", numbers, visited);
    int answer = 0;
    for(int n:nums) {
        if(isPrime(n)) answer++;
    }
    return answer;
}
