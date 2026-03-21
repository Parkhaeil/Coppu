#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> v;
    int fibo[42][2] = {0,};
    
    fibo[0][0] = 1;
    fibo[1][1] = 1;
    
    for(int i = 2 ; i < 41 ; i++){
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }
    
    for(int i = 0 ; i < N ; i++){
        int T;
        cin >> T;
        v.push_back(T);
    }
    
    for(int i = 0 ; i < v.size() ; i++){
        int T = v[i];
        cout << fibo[T][0] << " " << fibo[T][1] << "\n";
    }
    
    return 0;
}
