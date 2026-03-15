#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;
int idx[1000001];
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return idx[a.first] < idx[b.first];
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;

        bool found = false;

        for(int j = 0; j < v.size(); j++){
            if(v[j].first == x){
                v[j].second++;
                found = true;
                break;
            }
        }
        if(!found){
            v.push_back(pair<int,int>(x,1));
            idx[x] = i;
        }
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].second; j++){
            cout << v[i].first << " ";
        }
    }
}
