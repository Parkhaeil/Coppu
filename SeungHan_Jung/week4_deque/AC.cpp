#include <bits/stdc++.h>
using namespace std;
    
void parse(string& tmp , deque<int>& d){
    int number;
    number = 0;
    for(int i = 1 ; i < tmp.size() -1 ; i++){ 
        // 아 이렇게 인덱스 범위를 컨트롤 해서 바로 [,] 을 빼버리네 굿굿
        if(tmp[i] == ','){
            d.push_back(number);
            number = 0;
        }else{
            number = (number*10) + (tmp[i] - '0');
        }
    }
    if(number != 0){
        d.push_back(number);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        string operators, tmp;
        int n;
        int reverse = -1;
        deque<int> d;
        cin >> operators;
        cin >> n;
        cin >> tmp;
        bool error = false;
        parse(tmp , d);
        
        for(char c : operators){
            if(c == 'R'){
                reverse *= -1;
            }else{
                if(d.size() == 0){
                    error = true;
                    break;
                }else{
                    // D 인데 또 배열안에 든 값도 좀 있는 경우
                    if(reverse == 1){
                        d.pop_back();
                    }else{
                        d.pop_front();
                    }
                }
            }
        }
if (error) {
    cout << "error\n";
} else {
    cout << '[';
    if (!d.empty()) {
        if (reverse == -1) {
            // 앞 → 뒤
            cout << d.front();
            d.pop_front();
            while (!d.empty()) {
                cout << ',' << d.front();
                d.pop_front();
            }
        } else {
            // 뒤 → 앞
            cout << d.back();
            d.pop_back();
            while (!d.empty()) {
                cout << ',' << d.back();
                d.pop_back();
            }
        }
    }
    cout << "]\n";
}

    }
}
