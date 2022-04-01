#include <iostream>
using namespace std;

void hanoi(int start, int end, int n) {
    //base condition
    //재귀 조건이 필요하므로 base condition해주고 return해주기
    if (n == 1) {
        cout << start << " " << end << '\n';
        return;
    }

    //function setting
    //원판 2개라고 가정
    //1>2, 1>3,2>3 (기둥)

    //1->2 는 처음에서 중간기둥이므로 start, 중간기둥의 숫자는 모든 기둥의 수의 합에서 스타트와 엔드의 합을 빼주면 됨,
    //n-1개의 원판을 옮겨야함
    //즉, n-1개의 원판을 기둥 start에서 기둥 6-start-end로 옮긴다.
    hanoi(start, 6 - start - end, n-1);
    //n번 원판을 기둥 start에서 end로 옮긴다.
    cout << start << " " << end << '\n';
    //n-1개의 원판을 기둥 6-start-end에서 기둥 end로 옮긴다.
    hanoi(6 - start - end, end, n-1);
    
    

}

int main() {
    int N;
    cin >> N;
    cout << (1 << N) - 1<<"\n";
    hanoi(1, 3, N);
    return 0;
}
