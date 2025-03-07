#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int LIMIT = 1000000;

vector<bool> is_prime(LIMIT + 1, true); // 소수 여부 저장
vector<int> happy_primes; // 소수 상근수 저장

// 에라토스테네스의 체
void getPrime() {
    is_prime[0] = is_prime[1] = false; 
    for (int i = 2; i * i <= LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// 각 자릿수 제곱의 합을 구하는 함수
int getSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// 상근수 판별 
bool isHappyNumber(int n) {
    unordered_set<int> not_happy_nums;
    while (n != 1 && not_happy_nums.find(n) == not_happy_nums.end()) {
        not_happy_nums.insert(n);
        n = getSum(n);
    }
    return n == 1; // 1이 나오면 상근수
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    getPrime(); 

    for (int i = 7; i <= n; i++) {
        if (is_prime[i] && isHappyNumber(i)) { 
            happy_primes.push_back(i);
        }
    }
    
    for (int num : happy_primes) {
        cout << num << "\n";
    }

    return 0;
}