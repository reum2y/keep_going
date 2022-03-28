#include <iostream>
using namespace std;


void hanoi(int n, int start, int mid, int end) {
    if (n == 1)
        cout << start << " " << end <<"\n";
    else {
        hanoi(n - 1, start, end, mid); //1±âµÕ > 2±âµÕ
        cout << start << " " << end << "\n"; //1±âµÕ>3±âµÕ
        hanoi(n - 1, mid, start, end);//2±âµÕ>3±âµÕ
    }

}

int main() {
    int k;
    cin >> k;
    cout << (int)(pow(2, k)-1)  << "\n";
    hanoi(k, 1, 2, 3);
    return 0;

}