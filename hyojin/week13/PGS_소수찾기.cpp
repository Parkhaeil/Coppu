#include <string>
#include <vector>
#include <set>
using namespace std;
bool visited[10];
vector<int> num;
set<int> s;

int isPrime(int n) {
    if (n<2)
        return false;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) return false;
    }
    return true;
}

void func(int depth,int n) {
    // set은 insert 사용
    // depth=길이
    s.insert(n);
    for (int i=0;i<num.size();i++) {
        if (!visited[i]) {
            visited[i]=true;
            // n은 함수 호출할때 변경. 밖에서하면 되돌려줘야함.
            func(depth+1,n*10+num[i]);
            visited[i]=false;
        }
    }
}

int solution(string numbers) {
    for (int i=0;i<numbers.length();i++) {
        num.push_back(numbers[i]-'0');
    }
    func(0,0);
    int ans=0;
    for (int i : s) 
        if (isPrime(i)) ans++;
    return ans;
}