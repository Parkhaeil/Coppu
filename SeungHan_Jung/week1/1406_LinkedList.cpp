#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<char> L;
    std::string input_string;
    cin >> input_string;
    
    for(char c : input_string){
        L.push_back(c);
    }
    
    auto cursor = L.end(); 
    // 그 내부에 prev , next , value 를 모두 담고 있는 node 라는 이름의 구조체의 주소소
    int ans = 0 ;
    cin >> ans;
    char instruction , add_alpha;
    
    while(ans--){
        cin >> instruction;
        if(instruction == 'P'){
            cin >> add_alpha;
            L.insert(cursor,add_alpha); 
          // 위치 먼저 , 그리고 List<template> 의 template 자료형의 넣을 수 있는 값을 입력
        }else if(instruction == 'L'){
            if(cursor != L.begin()){
                cursor--;
            }
        }else if(instruction == 'D'){
            if(cursor != L.end()){
                cursor++;
            }
        }else{
            if(cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
                // L.erase 가 지우고 바로 다음의 포인터를 반환
                // 그걸 cursor 에게 넘겨주면 , cursor 는 이미 지워진 엉뚱한 주소 가르킴
            }
        }
    }
    
    for(auto c : L){
        cout << c; 
        // L의 각 요소는 아마 어떤 struct의 한 요소일거고
        // 그걸 cout 에 걸면 아마 자동으로 value 를 반환하게끔 그 내부에 오버라이딩이 되어 있겠지
    }
    return 0;
}

/*
std::list 는 처음(head)과 마지막(tail) 노드의 힙 주소만 들고 있고
각 노드는 자기 안에 prev / next 포인터로 연결리스트를 이루고 있으며
실제 데이터(char)는 각 노드 안에 들어 있다
즉 애초에 이름이 그냥 리스트라서 힙 공간에 쭉 생기는 리스트처럼 보이기 쉽지만 완전한
연결리스트로 구현된 형태임
*/
