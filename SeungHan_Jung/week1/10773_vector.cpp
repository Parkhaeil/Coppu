// 스택은 pop() , top() , push() , size()

#include <iostream>
#include <stack>
using namespace std;

int n,num,ans;

int main(){
    cin >> n;
    stack<int> s;
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        if(num == 0){
            if(s.size() == 0){
                continue;
            }else{
                s.pop();
            }
        }else{
            s.push(num);
        }
    }
    ans = 0;
    while(s.size() > 0){
        ans += s.top();
        s.pop();
    }
    cout << ans;
    return 0;
}
