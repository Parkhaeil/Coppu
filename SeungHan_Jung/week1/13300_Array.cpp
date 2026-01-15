// 2차원 배열을 이용하는 문제이다.

#include <iostream>
using namespace std;

int main(){
    int student_number;
    cin >> student_number;
    
    int max;
    cin >> max;
    
    int sex , grade;
    int table[2][6] = {0}; // 성별(남,여) and 학년(1~6)
    int answer = 0;
    for(int i = 0 ; i < student_number ; i++){
        cin >> sex;
        cin >> grade;
        grade--;
        table[sex][grade]+=1;
    }
    
    int v;
     for(int m = 0 ; m < 2 ; m++){
         for(int n = 0 ; n < 6 ; n++){
             v = table[m][n];
            if(v % max == 0){
                answer+=(v/max);
            }else{
                answer+=((v/max)+1);
            }
         }
     }

    cout << answer;
    return 0;
}
