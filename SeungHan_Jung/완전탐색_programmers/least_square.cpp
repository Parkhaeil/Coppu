#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int return_greater_value(vector<int> size){
    if(size[0] >= size[1]){
        return size[0];
    }else{
        return size[1];
    }
}

int return_smaller_value(vector<int> size){
    if(size[0] >= size[1]){
        return size[1];
    }else{
        return size[0];
    }
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    // 일단 제일 먼저 가장 큰 값을 하나를 고르고 ,
    // 각 배열에서 두번째로 큰 수 중 가장 큰 수를 고르면 되겠다
    // 벡터는 .size() , .empty() , 
    vector<int> first_large_values;
    vector<int> second_large_values;
    for(int i = 0 ; i < sizes.size() ; i++){
        first_large_values.push_back(return_greater_value(sizes[i]));
        second_large_values.push_back(return_smaller_value(sizes[i]));
    }
    sort(first_large_values.begin(),first_large_values.end(),greater<int>());
    sort(second_large_values.begin(),second_large_values.end(),greater<int>());
    answer = first_large_values[0] * second_large_values[0];
    return answer;
}
