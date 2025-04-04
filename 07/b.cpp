//11053
//dp[n]: n번째 수열 값을 포함하는(가장 끝에) 수열
//점화식: ( k<i, arr[k]<arr[i] ) -> dp[i] = dp[k] + 1 
//주의1: max(dp[i], dp[k] + 1) dp[k] < dp[k-1] 일 경우
//주의2: 마지막 dp[n-1]이 항상 크지 않다

#include <iostream>
#include <vector>
using namespace std;
int main() {
    //입력
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> dp(n, 1);
    
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    //연산
    for(int i=1; i<n; i++){
        for(int k=0; k<i; k++){
            if(arr[i]>arr[k]) dp[i] = max(dp[i], dp[k]+1);
        }
    }
    
    //최댓값 찾기
    int max = 0;
    for(int v : dp){
        if(v>max) max = v;
    }
        
    //출력
    cout << max;
    return 0;
    
}