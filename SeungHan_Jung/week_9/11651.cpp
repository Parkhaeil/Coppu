#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int,int> a , pair<int,int> b){
    if(a.second == b.second){
        return a.first <= b.first;
    }else{
        return a.second <= b.second;
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int inputs;
    cin >> inputs;
    vector<pair<int,int>> input_vector;

    for(int i = 0 ; i < inputs ; i++){
        int first_input , second_input;
        cin >> first_input >> second_input;
        input_vector.push_back({first_input , second_input});
    }

    sort(input_vector.begin() , input_vector.end() , compare);

    for(int i = 0 ; i < inputs ; i++){
        cout << input_vector[i].first << " " << input_vector[i].second << "\n" ;
        // 이게 input_vector의 행이 그냥 행이 아니다. -> 이건 pair 타입이다. -> 그렇기에 [i][0],  [i][1]
        // 이런거 없음 -> pair타입에 대해서는 .first , .second 를 해야한다.
        // 와 진짜 미쳤네..endl은 출력 버퍼를 비우는 작업(flush)까지 수행하므로, "\n"만 사용하는 것보다 더 느립니다.
    }

}
