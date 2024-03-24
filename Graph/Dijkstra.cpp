#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

struct edge
{
    public:
        int source;
        int dest;
        int weight;
};

struct node 
{
    int id;
    int dist;
    bool visited;
};

bool operator < (const node& leftHandSide, const node& rightHandSide)
{
    return leftHandSide.dist > rightHandSide.dist;
}

void dijkstra(int n, int source, const vector <edge> edges)
{
    priority_queue <node> pq;
    pq.push({source, 0, false});

    vector <ll> distance(n, INT_MAX);
    distance[source] = 0;

    while (!pq.empty())
    {
        node u = pq.top();
        pq.pop();

        if (u.visited) continue;
        u.visited = true;

        for (edge e : edges)
        {
            if (e.source == u.id)
            {
                int v = e.dest;
                int dist = u.dist + e.weight;
                if (dist < distance[v])
                {
                    distance[v] = dist;
                    pq.push({v, dist, false});
                }
            }
        }
    }
    for (int i = 0; i < n; i ++)
        cout << distance[i] << " ";
}

void Open(int &n, vector <edge> &edges)
{
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int source, dest, weight;
        cin >> source >> dest >> weight;
        edges.push_back({source, dest, weight});
    }
}

int main()
{
    int n;
    vector <edge> edges;
    Open(n, edges);
    dijkstra(n, 0, edges);
    return 0;
}