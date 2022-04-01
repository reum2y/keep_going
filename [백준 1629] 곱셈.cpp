//반복문으로 풀게되면 약 21억번의 반복을 하게 되어 시간초과(O(n)번의 시간복잡도)
//따라서 O(n)번이 아닌 O(log n)번의 시간복잡도로 풀어야함

#include<iostream>
using namespace std;
//a,b,c의 범위 때문에 int로 설정해주면 틀리게된다.
long long a, b, c;

long long power(long long a, long long b, long long c) {
    //1. base조건 설정
    if (b == 0) return 1;
    //2. 함수 설정
    //지수b를 2로 나눈값을 tmp에 저장후 tmp끼리 곱해주면 원래 수, 결론적으로 원래값을 c로 나눈 나머지를 저장한다. 
    long long tmp = power(a, b / 2, c);
    tmp = tmp * tmp % c;
    //b가 짝수면 tmp = tmp*tmp니까 그대로 진행
    if (b % 2 == 0) return tmp;
    //b가 홀수면 a를 한번 더 곱해주어야 원래 숫자 
    else return tmp * a % c;
}


int main() {
    cin >> a >> b >> c;
    cout << power(a, b, c);
    return 0;
}
