#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1068

/*
<트리>
주요: 트리, DFS
1. 트리를 DFS로 탐색한다.
2. 지워진 노드는 DFS 탐색 시 배제한다.
3. 리프노드의 개수를 출력한다.
	3-1. 자식 노드가 없으면 ans++
	3-2. 자식 노드가 하나 있었지만 그 노드를 삭제했다면 자신이 리프노드이므로 그 때 ans++

*/

int N, M, root, ans = 0;
vector<int> g[55];

void DFS(int n){

	if(n == M){ return;} // 2반
	for (int i = 0; i < g[n].size(); i++) {
		int next = g[n][i];
		DFS(next);
	}
	if(g[n].size() == 0){ ans++;} // 3-1번
	else if(g[n].size() == 1 && g[n][0] == M){ ans++;} // 3-2번
}

int main(){

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if(input == -1){
			root = i;
		}
		else{
			g[input].push_back(i);
		}
	}
	cin >> M;

	DFS(root);
	cout << ans;

  return 0;
}
