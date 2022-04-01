#include <iostream>
using namespace std;

int func(int n, int r, int c) {
    if (n == 0) return 0;
    int half = 1 << (n - 1); // 1<<k는 2의 k승과 같다. 
    //한변이 2^2라고 가정하자
    //그럼 4등분하면 한 변은 2^1 = half(그 좌표가 있는 큰 네모칸의 한변길이)

    //1번 사각형일 때
    if (r < half && c < half) return func(n - 1, r, c); 
    //2번 사각형일 때
    // 1번사각형의 좌표와 비교했을 때, 행은 똑같고 열이 더 늘어나 다음칸으로 갔으므로 열-half
    if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
    //3번일 때
    if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
    //4번
    if (r >= half && c >= half) return 3 * half * half + func(n - 1, r - half, c - half);

}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << func(N, r, c);
}
