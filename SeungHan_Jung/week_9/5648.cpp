#include <bits/stdc++.h>
using namespace std;

bool compare(long long &a , long long &b){
    return a <= b;
}

int main(){
    int N;
    cin >> N;
    vector<long long> S;
    
    for(int i = 0 ; i < N ; i++){
        string st;
        cin >> st;
        reverse(st.begin(),st.end());
        S.push_back(stoll(st));
    }
    sort(S.begin(),S.end(),compare);
    for(int i = 0 ; i < S.size() ; i++){
        cout << S[i] << "\n";
    }
}
