#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int node_number = 11; //노드 수
int id=0, d[MAX]; //노드 번호
bool finished[MAX]; //노드 방문 여부
vector<int> a[MAX]; //노드와 간선들 정보
vector<vector<int>> SCC; //SCC 집합들.
stack<int> s;

int dfs(int x)
{
	d[x] = ++id;
	//자기 자신의 번호
	s.push(x);
	//자신을 스택에 넣고 시작
	int parent = d[x];
	//제일 처음엔 자기 자신이 부모
	for (int i = 0; i < a[x].size(); i++) //자신과 연결된 노드들을 찾아나감
	{
		int y = a[x][i]; //연결된 노드번호
		if (d[y] == 0) parent = min(parent, dfs(y));
		//연결된 노드의 번호가 0이다->방문한적 없다->그 친구의 부모가 정확히 누구일지 탐색해본다(하다보면 아래 조건문에 걸림)
		//다음 노드의 부모가 자신의 부모보다 작다->처음 시작 노드의 부모를 가지고 왔을 것임->자신도 그 부모값에 맞춤
		else if (!finished[y]) parent = min(parent, d[y]);
		//자신과 연결된 노드의 DFS가 아직 안 끝났다-> 그 노드가 지금 나까지 연결됐다.
		//그리고 y는 연결된 노드 번호고, d[y]는 그 노드의 부모인데, 작은 번호부터 시작되므로 내 부모를 그 노드의 부모로 맞춤
	}
	if (parent == d[x]) //새로 갱신된 부모값(parent)랑 초기 내 번호로 설정한 부모(d[x])가 같다면 자신이 특정 css의 시작점.
	{
		vector<int> scc; //해당 css의 노드 정보들을 담을 차례
		while (1)
		{
			int t = s.top(); //스택의 최상단 값들을 빼서
			s.pop();
			scc.push_back(t); //한 scc 집합에 넣기 시작
			finished[t] = true; //점검이 끝났으니까 끝났음을 알림
			if (t == x) break; //스택엔 자기 자신도 있었으니 자신을 빼면 그 scc 집합의 노드는 다 찾은거임
		}
		SCC.push_back(scc); //한 scc 집합을 전체 SCC 집합에 넣음
	}
	return parent;
}

int main()
{
	a[1].push_back(2); //1번에서 2번으로 연결
	a[2].push_back(3); //2번에서 3번으로 연결
	a[3].push_back(1); //3번에서 1번으로 연결
	a[4].push_back(2); //4번에서 2번으로 연결
	a[4].push_back(5); //4번에서 5번으로 연결
	a[5].push_back(7); //5번에서 7번으로 연결
	a[6].push_back(5); //6번에서 5번으로 연결
	a[7].push_back(6); //7번에서 6번으로 연결
	a[8].push_back(5); //8번에서 5번으로 연결
	a[8].push_back(9); //8번에서 9번으로 연결
	a[9].push_back(10); //9번에서 10번으로 연결
	a[10].push_back(11); //10번에서 11번으로 연결
	a[11].push_back(3); //11번과에서 3번으로 연결
	a[11].push_back(8); //11번과에서 8번으로 연결

	for (int i = 1; i <= node_number; i++)
		if (d[i] == 0) dfs(i);
	//자기 자신의 부모 설정이 안돼 있다->아직 scc 검사를 안 했다는 뜻이므로 dfs탐색 시작
	//부모가 0이 아니다->자기 자신이 부모로 되어 있던 새 부모를 찾았던 하다는 뜻은
	//scc 집합을 찾았단 뜻이므로 굳이 더 dfs할 필요가 없음

	cout << "SCC의 개수: " << SCC.size() << endl; //SCC 집합 총 개수
	for (int i = 0; i< SCC.size(); i++) //SCC엔 여러 개의 scc 집합이 있으니까 각 집합별로 처리
	{
		cout << i + 1 << "번째 SCC: ";
		for (int j = 0; j < SCC[i].size(); j++) //임의의 scc 집합 내 노드들 출력
			cout << SCC[i][j] << " ";
		cout << endl; //그냥 한줄 띄우려고..
	}

	return 0;
}