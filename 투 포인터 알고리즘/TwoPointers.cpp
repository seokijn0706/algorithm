/*
[투 포인터 알고리즘(Two Pointers Algorithm)]
1차원 배열에서 두 개의 포인터를 이용해 원하는 결과를 얻는 알고리즘

배열에 각 원소는 자연수이고 원하는 합 M도 자연수이다.

부분 배열의 시작과 끝을 가리키는 변수 s, e을 준비하고 부분합을 저장할 변수 sum을 준비한다.

다음을 반복한다. while(true)

	1. 현재 부분합이 M과 같다면 원하는 결과를 처리 ex) res++

	2. 현재 부분합이 M 이상이면 sum에서 s가 가리키는 원소의 값을 빼고 s++

	3. e == n 즉 e가 배열에 끝에 도달하면 break

	4. 현재 부분합이 M 미만이면 sum에 e가 가리키는 원소의 값을 더하고 e++
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a[10000];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int res = 0, sum = 0, s = 0, e = 0;

	while (true) {
		if (sum == m) res++;
		if (sum >= m) sum -= a[s++];
		else if (e == n) break;
		else sum += a[e++];
	}
	cout << res;



	return 0;
}
