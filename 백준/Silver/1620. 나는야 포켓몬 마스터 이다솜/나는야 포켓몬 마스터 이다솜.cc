#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);//실행속도를 높이기 위해
	cin.tie(0);
	cout.tie(0);

	string pocketmon[100000], problem;
	int pnum;
	map<string, int>p;//<key, value>, 자동으로 오름차순 정렬
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> pocketmon[i];
		p[pocketmon[i]] = i + 1;
	}
	for (int j = 0; j < m; j++) {
		cin >> problem;
		if (isdigit(problem[0])) {//숫자일때
			pnum = stoi(problem) - 1;//문자열을 정수로 변환
			cout << pocketmon[pnum] << '\n';//endl은 개행뿐만 아니라 내부 버퍼를 비워주는 역할이라 느림
		}
		else {//문자열이면 인덱스 출력
			cout << p[problem] << '\n';
		}
	}

	return 0;
}
