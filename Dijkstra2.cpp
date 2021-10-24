#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 987654321;

vector<pair<int, int>> arr[20001];
int dist[20001];
int V, E, K;

struct cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second != b.second)
			return a.second > b.second;
		else
			return a.first > b.first;
	}
};

void diks()
{
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	dist[K] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
	q.push({ K,0 });
	while (!q.empty())
	{
		int current = q.top().first;
		int distance = q.top().second;
		q.pop();
		if (dist[current] < distance) continue;
		for (int i = 0; i < arr[current].size(); i++)
		{
			int next_node = arr[current][i].first;
			int dist_to_next_node = arr[current][i].second;
			if (dist[next_node] > dist_to_next_node + distance)
			{
				dist[next_node] = dist_to_next_node + distance;
				q.push({ next_node, dist[next_node]});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back({ v,w });
	}
	diks();
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}