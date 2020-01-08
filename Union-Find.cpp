#include <iostream>
using namespace std;

#define MAX_SIZE 8

int parent[MAX_SIZE];

int Find(int x) {
	if (parent[x] == x) { // 자기 자신과 같으면 부모이므로 리턴
		return x;
	}
	else {
		
		return parent[x] = Find(parent[x]); // 다르면 부모를 찾아서 리턴
	}
}
void Union(int x, int y) {
	int xParent = Find(x); // x의 부모를 찾는다
	int yParent = Find(y); // y의 부모를 찾는다
	if (xParent < yParent) { // 더 크기가 작은 부모 쪽으로 합치기
		parent[yParent] = xParent; //y의 부모를 x로

	}
	else {
		parent[xParent] = yParent; //x의 부모를 y로
	}
}

void printTable() {
	cout << "i         |";
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << i << " |";
	}
	cout << "\n";
	cout << "parent[i] |";
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << parent[i] << " |";
	}
	cout << "\n\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < MAX_SIZE; i++) {
		parent[i] = i;	 // 맨 처음엔 자기 자신이 부모 노드
	}
	printTable(); // 초기값 출력

	cout << "노드 1와 노드 2 Union\n";
	Union(1, 2); // 노드 1와 노드 2 Union
	printTable(); // 결과 출력

	cout << "노드 6와 노드 7 Union\n";
	Union(6, 7); // 노드 6와 노드 7 Union
	printTable(); // 결과 출력

	cout << "노드 3와 노드 7 Union\n";
	Union(3, 7); // 노드 3와 노드 7 Union
	printTable(); // 결과 출력

	cout << "노드 4와 노드 2 Union\n";
	Union(4, 2); // 노드 4와 노드 2 Union
	printTable(); // 결과 출력

	//노드 1과 노드 3가 같은 그래프에 속해있는가?
	if (Find(1) == Find(3)) {
		cout << "노드 1과 노드 3은 같은 그래프에 속해있습니다.\n";
	}
	else {
		cout << "노드 1과 노드 3은 같은 그래프에 속해있지않습니다.\n";

	}
	if (Find(0) == Find(5)) {
		cout << "노드 0과 노드 5은 같은 그래프에 속해있습니다.\n";
	}
	else {
		cout << "노드 0과 노드 5은 같은 그래프에 속해있지않습니다.\n";

	}
	if (Find(3) == Find(7)) {
		cout << "노드 3과 노드 7은 같은 그래프에 속해있습니다.\n";
	}
	else {
		cout << "노드 3과 노드 7은 같은 그래프에 속해있지않습니다.\n";

	}
	return 0;
}
