#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp_in(pair<int,int> a, pair<int,int> b){
    // 처음이 고유번호 , 두번째가 재생횟수
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

bool cmp_out(pair<int,vector<pair<int,int>>> a , pair<int,vector<pair<int,int>>> b){
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,vector<pair<int,int>>> um;
    unordered_map<string,int> um_order;
    for(int i = 0 ; i < genres.size() ; i++){
        um_order[genres[i]] = 0;
    }
    // 각 장르별로 노래를 저장할 계획 , 각 노래가 저장이 되는 형태는 자신의 고유번호와 재생횟수 순서로
    for(int i = 0 ; i < genres.size() ; i++){
        um_order[genres[i]] += plays[i];
        um[genres[i]].push_back({i,plays[i]});
    }
    for(auto it = um_order.begin() ; it != um_order.end() ; it++){
        std::sort(um[it->first].begin(),um[it->first].end(),cmp_in);
    }
    
    // 자 이제 정렬을 위해 필수불가결 하게 이 hash set 과 map 을 vector 로 복사해서 옮겨야 함. 근데 그럴거면 맨 처음부터 벡터쓰지 왜 hash 를 썼나? 왜냐면 장르가 몇개 나올지도 모르기 떄문에 각 장르별로 벡터를 만드는 것도 불가능하고 그래서 이렇게 같은 종류별로 싹 합친 다음에 편하게 벡터로 옮기기 위해서다 정도로 생각하면 될 듯
    
    vector<pair<int,vector<pair<int,int>>>> v;
    for(auto it = um_order.begin() ; it != um_order.end() ; it++){
        string cur_genre = it -> first;
        int temp_sum = it -> second;
        v.push_back({temp_sum , um[cur_genre]});
    } 
// 아 hash map 을 순회해야 할 필요가 있을때가 당연히 있구나! -> 종류별로 취합해서 이제 그 다음의 액션을 해야 할때!
    
    std::sort(v.begin(),v.end(),cmp_out);
    for(auto a : v){ 
        // a의 타입은 pair<int,vector<pair<int,int>>>
        // a.second 의 타입은 vector<pair<int,int>> -> 첫번째가 고유번호, 두번째가 plays
        int count = min(2,int(a.second.size())); // 맞다 .size() 는 뭐 unsigned였나 size_t 타입이었나 그거여서 int 로 바꿔야 했었은
        for(int i = 0 ; i < count ; i++){
            answer.push_back(a.second[i].first);
        }
    }
    return answer;
}
