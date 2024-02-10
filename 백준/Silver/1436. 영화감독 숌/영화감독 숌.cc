#include <iostream>
using namespace std;

void moviename(int n) {
    int cnt = 0;
    int i = 666;
    while (true) {
        int ans = i;//1번째 666부터 시작
        while (ans > 0) {
            if (ans % 1000 == 666) {//자릿수마다 666찾기
                cnt++;
                break;
            }
            ans /= 10;
        }
        if (n == cnt) {
            cout << i;
            break;
        }
        i++;
    }
}

int main() {
    int n;
    cin >> n;
    moviename(n);
    return 0;
}
