#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool isOut(int row, int col){
    if(row < 1 || row > 8) return true;
    if(col < 'A' || col > 'H') return true;
    else return false;
}
void move(string st,  pair<int, int> &k,  pair<int, int> &s){
    // 위치 변화량
    int row_moved = 0;
    int col_moved = 0;
    if(st.compare("R") == 0) col_moved++;
    else if(st.compare("L") == 0) col_moved--;
    else if(st.compare("B") == 0) row_moved--;
    else if(st.compare("T") == 0) row_moved++;
    else if(st.compare("RT") == 0) {
        row_moved++;
        col_moved++;
    }
    else if(st.compare("LT") == 0) {
        row_moved++;
        col_moved--;
    }
    else if(st.compare("RB") == 0) {
        row_moved--;
        col_moved++;
    }
    else {
        row_moved--;
        col_moved--;
    }
    int k_row_loc = k.first + row_moved;
    int k_col_loc = k.second + col_moved;
    
    //예외 확인, 이동 완료
    if(isOut(k_row_loc, k_col_loc)) return; // 스킵 1
    if(k_row_loc == s.first && k_col_loc == s.second){
        int s_row_loc = s.first + row_moved;
        int s_col_loc = s.second + col_moved;
        if(isOut(s_row_loc, s_col_loc)) return; // 스킵 2
        else {
            s.first = s_row_loc;
            s.second = s_col_loc;
        }
    }
     k.first = k_row_loc;
     k.second = k_col_loc;
 }
int main(){
    //시간초과 방지
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 행, 열
    pair<int, int> k_loc = make_pair(0, 0);
    pair<int, int> s_loc = make_pair(0, 0);
    int n, row;
    char col;
    
    //입력
    cin >> col >> row;
    k_loc.first = row;
    k_loc.second = (int) col;
    
    cin >> col >> row;
    s_loc.first = row;
    s_loc.second = (int) col;
    
    cin >> n;
    
    // 연산
    string str;
    for(int i=0; i<n; i++){
        cin >> str; // 덮어쓰기 
        move(str, k_loc, s_loc);
    }
    
    // 출력
    cout << (char)k_loc.second << k_loc.first << "\n";
    cout << (char)s_loc.second << s_loc.first;
}