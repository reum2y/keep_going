#include <iostream>
#include <cmath>
using namespace std;


void hanoi(int n, int start, int mid, int end) {
    if (n == 1)
        cout << start << " " << end <<"\n";
    else {
        hanoi(n - 1, start, end, mid); //1기둥 > 2기둥
        cout << start << " " << end << "\n"; //1기둥>3기둥
        hanoi(n - 1, mid, start, end);//2기둥>3기둥
    }

}

int main() {
    int k;
    cin >> k;
    cout << (int)(pow(2, k)-1)  << "\n";
    hanoi(k, 1, 2, 3);
    return 0;

}
