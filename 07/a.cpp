// 11726
// 1*2 타일의 어긋난 배치가 가능한가? → 불가능하다 (가정)
// 2*1 or 2*2(가로2) 를 선택할 수 있음
// (1) 2*1 이 빈 경우
// (2) 2*2가 빈 경우
// 점화식: f(n) = f(n-1) + f(n-2)
// 주의: 오버플로우 방지 %10007

#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;
ll getNumOfCases(int n, vector<ll> &dp){
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    return dp[n];
}
int main() {
    // 입력 
    int n;
    cin >> n;
    vector<ll> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    // 연산, 출력
    cout << getNumOfCases(n, dp);
}