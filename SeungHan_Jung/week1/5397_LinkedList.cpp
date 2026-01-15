#include<iostream>
#include<list>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for(int m = 0 ; m < n ; m++){
        std::string input_string;
        list<char> L = {};
        auto p = L.begin();
        
        cin >> input_string;
        for(char c : input_string){
            if(c=='<'){
                if(p != L.begin()){
                    p--;
                }
            }else if(c=='>'){
                if(p != L.end()){
                    p++;
                }
            }else if(c == '-'){
                if(p != L.begin()){
                    p--;
                    p = L.erase(p);
                }
            }else{
                L.insert(p,c); // 어떤 위치에 어떤 값을 넣을 건지의 순서.
            }
        }
        for(auto p : L){
            cout << p;
        }
        cout << '\n';
    }
    return 0;
}
