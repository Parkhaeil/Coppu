#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int number;
    cin >> number;

    string preString, postString;

    while(number--){
        cin >> preString >> postString;

        sort(preString.begin(), preString.end());
        sort(postString.begin(), postString.end());
        // string 자료형의 인스턴스에 .end() 하면 마지막인자가 끝난 바로 다음 주소 가르킴
        // 즉 sort 의 , 기준 우측 주소값에 대해 열린 주소여도 ㄱㅊ 하다는 것
        // postString = sort(postString.begin(),postString.end()); 
        // -> sort 는 그냥 바로 메모리 딴에서 수정하고 그 어떤 값도 반환하지 않는다 
        // answer = strcpy(preString , postString); 
        // strcpy , strcmp등은 c 언어 전용으로 c 언어에는 애초에 string 이라는 클래스 자료형 없음 
        // c++ 에서 string 클래스 자료형의 값을 .c_str() 로 char 형태의 일반적인 배열 형태로 바꿀 수 있음 
        // strcmp(preString.c_str(), postString.c_str()) == 0 
        // answer = (preString == postString); 
        // c++ 의 string 자료형은 내부에 == 이 오버라이딩 되어 있음

        if(preString == postString)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}
