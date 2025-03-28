#include <iostream>
#include <set>
using namespace std;

int main(){
    //입력
    set<int> people;
    set<int> burgers;
    
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        if(c == 'H') burgers.insert(i+1);
        else people.insert(i+1);
    }
    
    //연산
    int answer = 0;
    for(int p: people){
        int min = p - k;
        int max = p + k;
        for(int i=min; i<=max; i++){
            if(burgers.find(i) != burgers.end()){
                burgers.erase(i);
                answer++;
                break;
            } 
        }
    }
    
    //출력
    cout << answer;
        
}
