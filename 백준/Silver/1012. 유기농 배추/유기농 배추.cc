#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };  // 동서남북
int dy[4] = { 0, 0, -1, 1 };
int arr[51][51];
queue<pair<int, int>> q;
int t, m, n, k;


void bfs(int x, int y) {
    q.push({ x, y });
    arr[x][y] = 0;

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int c = 0; c < 4; c++) {
            int nx = now.first + dx[c];
            int ny = now.second + dy[c];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 0) {
                continue;
            }
            arr[nx][ny] = 0;
            q.push({ nx, ny });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> t;

    while (t--) {
        cin >> m >> n >> k;
        int cnt = 0;
        // 배열 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = 0;
            }
        }
        //좌표 입력 
        for (int j = 0; j < k; j++) {
            cin >> x >> y;
            arr[y][x] = 1;//행,열 맞춰서 저장
        }

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (arr[a][b] == 1) {
                    bfs(a, b);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
