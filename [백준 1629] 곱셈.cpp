#include<iostream>
using namespace std;

long long a, b, c;

long long power(long long a, long long b, long long c) {
    if (b == 0) return 1;
    long long tmp = power(a, b / 2, c);
    tmp = tmp * tmp % c;
    if (b % 2 == 0) return tmp;
    else return tmp * a % c;
}


int main() {
    cin >> a >> b >> c;
    cout << power(a, b, c);
    return 0;
}