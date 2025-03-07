// a % m = b % m 
// a % m - b % m = (a - b) % m = 0
// 수 간의 차이의 최대공약수의 약수를 구한다 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// GCD
int euclidean(int a, int b){
    if(a <= b) swap(a, b);
    if(b == 0) return a;
    return euclidean(b, a%b);
}

// GCD의 약수
vector<int> getDivisors(int gcd) {
    vector<int> divisors;
    for (int i = 2; i * i <= gcd; i++) { 
        if (gcd % i == 0) {
            divisors.push_back(i);
            if (i != gcd / i)  
                // 제곱수가 아닌 경우
                divisors.push_back(gcd / i);
        }
    }
    divisors.push_back(gcd);  
    sort(divisors.begin(), divisors.end());  
    return divisors;
}
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // 숫자 정렬
    sort(numbers.begin(), numbers.end());

    // 차이 
    int g = numbers[1] - numbers[0];  
    for (int i = 2; i < n; i++) {
        g = euclidean(g, numbers[i] - numbers[i - 1]);
    }

    // GCD의 약수 
    vector<int> result = getDivisors(g);

    // 출력
    for (int m : result) {
        cout << m << " ";
    }

    return 0;
}