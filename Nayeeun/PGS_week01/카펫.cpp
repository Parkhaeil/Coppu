#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for(int h=1; h*h<=yellow;h++){
        if(yellow%h== 0){
            int w=yellow / h;
            int carpet=(w+2)*(h+2);
            if(carpet-yellow==brown){
                return {w+2,h+2};
            }
        }
    }
}
