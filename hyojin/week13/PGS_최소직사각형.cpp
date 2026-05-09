#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    //각 명함 (a, b)에 대해 (작은 값 / 큰 값) 으로 정리하면 최소지갑크기나옴..
    for (int i=0;i<sizes.size();i++) {
        sort(sizes[i].begin(),sizes[i].end());
    }
    int row=0,col=0;
    for (int i=0;i<sizes.size();i++) {
        row=max(sizes[i][0],row);
        col=max(sizes[i][1],col);
    }
    return row*col;
    
    
    // int mn_row=0,mn_col=0;
    // int wallet_size=10000000;
    // int flag_row=0;
    // int flag_col=1;
    // for (int k=-1;k < sizes.size();k++) { // k=-1,0,1,2,3
    //         for (int j=0;j < sizes.size();j++) {
    //             if (j==k) {
    //                 flag_row=1; flag_col=0;
    //             }
    //             mn_row=max(sizes[j][flag_row],mn_row);
    //             mn_col=max(sizes[j][flag_col],mn_col);
    //             if (k==j) {
    //                 flag_row=0; flag_col=1;
    //             }
    //         }
    //         wallet_size=min((mn_row*mn_col),wallet_size);
    // }
    // return wallet_size;
}