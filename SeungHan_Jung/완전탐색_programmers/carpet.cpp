#include <string>
#include <vector>

using namespace std;
vector<pair<int,int>> total;
vector<pair<int,int>> brown;
vector<pair<int,int>> yellow;

// vector<int> dfs(vector<bool> used_total , vector<bool> used_brown , vector<bool> used_yellow){
//     // 종료조건
//     if()
// } 풀다보니 느낀 점 : 상태가 누적되지 않기 떄문에 굳이 탐색을 쓸 필요가 없음 그냥 이중 for문 쓰면 됨.

vector<int> solution(int brown_area, int yellow_area) {
    vector<int> answer;
    int total_area = brown_area + yellow_area;
    
    // 가로 >= 세로 이므로 무조건 첫번째 값이 세로 , 두번쨰 값이 가로임.
    
    // for(int i = 0 ; i * i <= brown_area ; i++){
    //     if(brown_area % i == 0){
    //         brown.push_back({i,brown_area / i});
    //     }
    // } 사실 brown 은 별로 필요가 없는 것 같은디? 
    
    for(int i = 1 ; i * i <= yellow_area ; i++){
        if(yellow_area % i == 0){
            yellow.push_back({i,yellow_area / i});
        }
    }
    for(int i = 1 ; i * i <= total_area ; i++){
        if(total_area % i == 0){
            total.push_back({i,total_area / i});
        }
    }
    
    // vector<bool> used_brown(brown.size(),false);
    // vector<bool> used_yellow(yellow.size(),false);
    // vector<bool> used_total(total.size(),false);
    
    for(int i = 0 ; i < yellow.size() ; i++){
        for(int j = 0 ; j < total.size() ; j++){
            if((yellow[i].first + 2 == total[j].first) && (yellow[i].second + 2 == total[j].second)){
                answer.push_back(total[j].second);
                answer.push_back(total[j].first);
            }
        }
    }

    return answer;
}
