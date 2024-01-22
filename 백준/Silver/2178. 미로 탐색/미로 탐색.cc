#include <iostream>
#include <queue>
#include <string>
using namespace std;

int arr[101][101];
string s[101];//띄어쓰기안되니까 문자열로 받기
int dx[4] = { 1,-1,0,0 };//동서남북
int dy[4] = { 0,0,-1,1 };


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			arr[i][j] = -1;//거리 배열 초기화
		}
	}
	queue<pair<int, int>> q;
	q.push({ 0,0 });//시작점
	arr[0][0] = 0;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = now.first + dx[k];
			int ny = now.second + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {//범위를 벗어나면 X
				continue;
			}
			if (arr[nx][ny] > 0 || s[nx][ny] != '1') {//이미 방문했거나 벽이면 X
				continue;
			}
			arr[nx][ny] = arr[now.first][now.second] + 1;
			q.push({ nx, ny });
		}
	}
	cout << arr[n - 1][m - 1]+1;

	return 0;
}