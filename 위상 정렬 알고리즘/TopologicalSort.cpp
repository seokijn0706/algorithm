/*
[위상 정렬 알고리즘]

1. indegree가 0인 정점을 모두 큐에 넣는다.

2. 큐가 빌 때까지 다음을 반복한다.

3. 큐에서 정점을 하나 꺼낸다.

4. 꺼낸 정점을 결과 리스트에 넣고 정점의 인접 리스트를 확인한다.

5. 꺼낸 정점과 연결된 다른 정점의 indegree을 1 감소시킨다.

5. 만약 연결된 정점의 indegree를 1 감소시켰을 때 indegree가 0이 되면 그 정점을 큐에 넣는다.

<사이클의 존재 여부>

결과 리스트의 사이즈가 n과 다르면 사이클이 존재

*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int indegree[10];
vector<int> adj[10];
vector<int> res;
int n, m;

/*위상 정렬*/
bool TopologicalSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!indegree[i]) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (auto& next : adj[cur]) {
			indegree[next]--;
			if (!indegree[next])q.push(next);
		}
	}
	if (res.size() == n) return true; //사이클 존재 x
	else return false; // 사이클 존재
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	TopologicalSort();

	for (auto& e : res) {
		cout << e << " ";
	}


	return 0;
}
