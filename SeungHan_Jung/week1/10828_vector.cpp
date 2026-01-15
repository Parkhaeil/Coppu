#include <iostream>
#include <stack>

// 정리를 살짝 해보자면 list 는 insert , .end() , .front()
// queue 도 top() , pop() , push()
// stack 도 top() , pop() , size() , push()
// vector 는 size() , push_back()
using namespace std;

int main(){
    stack<int> s;
    int n;
    string command;    // 명령어
    int num;
    int result = 0;
    
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> command;
        
        // 1. push
        if(command == "push"){
            cin >> num;
            s.push(num); // push 는 list<int> 등과 같은 모습인 걸 
        }
        
        // 2. pop
        else if(command == "pop"){
            if(s.size() == 0){
                result = -1;
                cout << result << endl;
            }
            else{
                result = s.top();
                cout << result << endl;
                s.pop();
            }
        }
        
        // 3. size
        else if(command == "size"){
            cout << s.size() << endl;
        }
        
        else if(command == "empty"){
            if(s.size() == 0){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
        
        else if(command == "top"){
            if(s.size() == 0){
                cout << -1 << endl;
            }
            else{
                cout << s.top()<<endl;
            }
        }
    }
    
    return 0;
}
