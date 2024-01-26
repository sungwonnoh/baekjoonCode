#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cnt = 0, ans = 0;
int maxH = 0;
int minH = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[101][101] = {};//입력받을 지역
bool visited[101][101] = { false, };

void dfs(int x, int y, int height) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {//범위내
			continue;
		}
		if (arr[ny][nx] <= height) {//물에 잠기는가?
			continue;
		}
		if (!visited[ny][nx] && arr[ny][nx] > height) {
			dfs(nx, ny, height);
		}
	}
}
void rainarea() {
	for (int k = 0; k < maxH; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > k && !visited[i][j]) {//안전지역
					cnt++;
					dfs(j, i, k);
				}
			}
		}
		ans = max(ans, cnt);
		cnt = 0;//초기화
		for (int i = 0; i < n; i++) {
			fill(visited[i], visited[i] + n, false);//fill함수 사용해서 초기화
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if(arr[i][j]>maxH){//최대 높이 찾기
				maxH = arr[i][j];
			}
		}
	}
	rainarea();
	if (ans == 0) {
		ans = 1;
	}
	cout << ans;
	return 0;
}