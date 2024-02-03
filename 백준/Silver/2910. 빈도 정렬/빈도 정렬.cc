#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int arr[1001];
map<int, int> num, rec;//숫자, 빈도수
vector<pair<int, int>> v;

bool ans(pair<int, int>a, pair<int, int> b) {
	if (a.first == b.first) {//입력순서에 따라 출력
		return rec[a.second] < rec[b.second];
	}
	return a.first > b.first;//빈도수 높은거부터 반환
}
int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		num[arr[i]]++;
		if (rec[arr[i]] == 0) {//처음이면 입력받은 순서 저장
			rec[arr[i]] = i+1;
		}
	}
	for (auto i:num) {
		v.push_back({ i.second, i.first });
	}
	sort(v.begin(), v.end(), ans);
	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}
	return 0;
}