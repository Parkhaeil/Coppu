#include <bits/stdc++.h>
using namespace std;

const int Max = 2000000; 
const int Half = Max/2;
vector<int> arrays(Max+4);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,current;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> current;
        arrays[Half + current] += 1;
    }
    
    for(int i = 0 ; i < arrays.size() ; i++){
        while(arrays[i]--){
            cout << i - Half << "\n";
         }
    }
}
