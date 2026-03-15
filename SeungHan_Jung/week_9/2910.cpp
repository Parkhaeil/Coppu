#include<bits/stdc++.h>
using namespace std;

struct Node{
    int num;
    int order;
    int count;
};

bool compare(Node a, Node b){
    if(a.count != b.count) {
        return a.count > b.count;
    }else{
        return a.order < b.order;
    }
}

int main(){
    int N,Max;
    cin >> N >> Max;
    
    vector<Node> v;
    
    for(int i = 0 ; i < N ; i++){
        int current;
        cin >> current;
        
        bool found = false;
        
        for(auto &e : v){
            if(e.num == current){
                e.count++;
                found = true;
                break;
            }
        }
        
        if(!found){
            v.push_back({current,i,1});
        }
    }
    
    // 입력 다 받았으니까 이제 정렬해야지
    sort(v.begin(),v.end(),compare);
    
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v[i].count ; j++){
            cout << v[i].num << " ";
        }
    }
    
    
}
