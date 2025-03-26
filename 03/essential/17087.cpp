#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 

using namespace std;
int euclidean(int a, int b){
    if(b == 0) return a;
    return euclidean(b, a%b);
}
int main(){
    //입력
    int n, s;
    cin >> n >> s;
    vector<int> loc(n);
    
     for(int i=0; i < n; i++){
        int k;
        cin >> k;
        loc[i] = abs(s - k);
    }
    
  //처리 
    int gcd = loc[0];
    for(int i = 0; i < n ; i++){
        gcd = euclidean(gcd, loc[i]);
    }
    
  //출력
	  cout << gcd;
    
}