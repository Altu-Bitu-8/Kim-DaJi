#include <iostream>
#include <vector>
#include <set>

using namespace std;
int rotate(vector<char> &wh, set<char> &used, int k, bool &isWheelValidate){
    int findedCharIndex = 0;
    while(k > 0){
        int r; //글자 변화 수
        char c; //문자
        cin >> r >> c;
        findedCharIndex = (findedCharIndex + r) % wh.size();
        //오류 1) 중복된 위치에 다른 문자
         if (wh[findedCharIndex] != '?' && wh[findedCharIndex] != c) {
            isWheelValidate = false;
            return -1;
        }

        //오류 2) 중복된 문자가 다른 위치
        if (wh[findedCharIndex] == '?' && used.count(c)) {
            isWheelValidate = false;
            return -1;
        }
        //정상
        wh[findedCharIndex] = c;
        used.insert(c);
        k--;
    }
    return findedCharIndex;
}
int main(){
    //입력
	int n, k;
    cin >> n >> k;
    
    //바퀴 
    vector<char> wheel(n, '?'); 
    set<char> usedChars;
    bool isWheelValidate = true;
    int finalIndex = rotate(wheel, usedChars, k, isWheelValidate);
    
    //출력
    if(!isWheelValidate) cout << '!';
    else{
         for(int i = 0; i < n ; i++){
            cout << wheel[(finalIndex - i + n) % n];
        }
    }
    return 0;
}
