#include <iostream>
#include <queue>
using namespace std;

int h, w;
int cnt = 0; // 치즈가 모두 녹아 없어지는 데 걸리는 시간
int prevCheese = 0; // 치즈가 모두 녹기 한 시간 전에 남아있는 치즈 조각의 개수
int arr[101][101];
bool visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if (!visited[ny][nx]) {
                    if (arr[ny][nx] == 1) { // 녹이는 치즈인 경우
                        arr[ny][nx] = 0; // 치즈를 녹임
                        visited[ny][nx] = true;
                    }
                    else { // 공기인 경우
                        q.push({ nx, ny });
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                prevCheese++; // 초기 치즈의 개수 계산
            }
        }
    }

    // 모든 치즈가 녹을 때까지 반복
    while (true) {
        // 방문 배열 초기화
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                visited[i][j] = false;
            }
        }

        bfs(); // 치즈 녹이기
        cnt++; // 시간 증가

        // 남아있는 치즈의 개수 계산
        int curCheese = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 1) {
                    curCheese++;
                }
            }
        }

        // 남아있는 치즈의 개수가 0이면 종료
        if (curCheese == 0) {
            break;
        }

        prevCheese = curCheese; // 이전 치즈의 개수 업데이트
    }

    cout << cnt << "\n";
    cout << prevCheese;
    return 0;
}