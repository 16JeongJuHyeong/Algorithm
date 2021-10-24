#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int>> a[7];
int d[7];

void diks(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start)); //제일 처음엔 자기자신으로의 비용(이건 당연히 0)과 시작노드
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		//최대힙은 큰 값이 앞으로 이동. 우린 최소힙을 필요로 하므로 pq에 push 할 때 비용을 음 값으로 넣어준다
		//그럼 절댓값이 큰 값들은 음값에서 작기 때문에 다 뒤로 간다. 젤 첨엔 0이니까 상관없다
		//distance는 start에서 해당 노드까지의 거리를 담은 정보
		int current = pq.top().second;
		// 방문할 노드 (첨엔 start 노드)
		pq.pop();
		if (d[current] < distance) continue;
		// 이미 갱신한 값이 새로 뽑은 값보다 작다면 갱신할 필요 없다
		// *pq에 경로가 더 큰 정보(ex 1->3은 7인데 1->2->3은 5인 경우, 1->2->3 이 큐에 먼저 들어와 있어서
		// 이게 나중에 d 배열의 값을 바꿈. 1->3 이 나중에 들어왔을 땐 이미 갱신된 상태라 무시
		for (int i = 0; i < a[current].size(); i++)
		{//지금 방문중인 노드랑 연결된 노드들 다 검사
			int next = a[current][i].second; 
			//목적지 노드
			int nextDistance = distance + a[current][i].first;
			//시작지에서 방문한 노드까지 거리 + 방문한 노드에서 목적지까지 거리
			if (nextDistance < d[next])
			{//시작지에서 방문한 노드까지 거리 + 방문한 노드에서 목적지까지 거리 < start에서 해당 노드로 최근까지 갱신된 거리
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main()
{
	for (int i = 0; i <= number; i++)
		d[i] = INF;
	//a[from].push_back(make_pair(비용, to 노드))
	a[1].push_back(make_pair(2, 2)); //1에서 2로 가는 비용 2
	a[1].push_back(make_pair(5, 3)); //1에서 3으로 가는 비용 5
	a[1].push_back(make_pair(1, 4)); //1에서 4로 가는 비용 1

	a[2].push_back(make_pair(2, 1));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(2, 4));

	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(3, 2));
	a[3].push_back(make_pair(3, 4));
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(5, 6));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(1, 5));

	a[5].push_back(make_pair(1, 3));
	a[5].push_back(make_pair(1, 4));
	a[5].push_back(make_pair(2, 6));

	a[6].push_back(make_pair(5, 3));
	a[6].push_back(make_pair(2, 5));

	diks(1);
	return 0;
}