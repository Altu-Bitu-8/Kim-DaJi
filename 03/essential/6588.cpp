#include <iostream>
#include <vector>

using namespace std;

vector<bool> is_prime(1000001, true); 

void findPrime() {
    is_prime[0] = is_prime[1] = false; 
    // 0과 1은 소수가 아님
    for (int i = 2; i * i <= 1000000; i++) {
    // 제곱근 
        if (is_prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) { 
	           // 중복 계산 제거
                is_prime[j] = false; 
                // i의 배수를 제거
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //시간 초과 해결

    findPrime(); 
    // 소수를 미리 계산

    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0; // 종료

        bool valid = false; // 골드바흐 검증
        
        // 합으로 나타내기
        for (int a = 3; a < n; a += 2) { 
        // 홀수 소수만 탐색
            if (is_prime[a] && is_prime[n - a]) { 
            // 두 수가 소수인지 확인
                printf("%d = %d + %d\n", n, a, n - a);
                valid = true;
                break;
            }
        }
        
        if (!valid) {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    return 0;
}
