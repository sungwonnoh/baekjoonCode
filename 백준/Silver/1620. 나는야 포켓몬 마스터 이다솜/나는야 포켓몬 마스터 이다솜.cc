#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);//실행속도를 높이기 위해
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	string pocketmon[100001], problem = "";
	unordered_map<string, int>p;

	for (int i = 1; i <= n; i++) {
		cin >> pocketmon[i];
		p[pocketmon[i]] = i;//번호 저장

	}
	while (m--)
	{
		cin >> problem;
		if (isdigit(problem[0])) {//숫자여부 확인
			cout << pocketmon[stoi(problem)] << '\n';
		}
		else {
			cout << p[problem] << '\n';
		}
	}

	return 0;
}