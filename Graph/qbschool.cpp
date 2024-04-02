#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;

class edge
{
    public:
        int street, source, dest;
        long weight;
        edge(){};
        friend istream& operator >> (istream&, edge&);
        ~edge(){};
};
vector <edge> edges;

class node 
{
    public:
        int id;
        long dist;
        bool visited;
        node(int id, long dist, bool visited)
        {
            this->id = id;
            this->dist = dist;
            this->visited = visited;
        };
        ~node(){};
};

istream& operator >> (istream& in, edge &orther)
{
    in >> orther.street >> orther.source >> orther.dest >> orther.weight;
    return in;
}

void Open()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        edge x;
        cin >> x;
        edges.push_back(x);
        if (x.street == 2)
        {
            swap(x.source, x.dest);
            edges.push_back(x);
        }
    }
}

bool operator < (const node &leftHandSide, const node &rightHandSide)
{
    return leftHandSide.dist > rightHandSide.dist;
}
bool operator > (const node &leftHandSide, const node &rightHandSide)
{
    return leftHandSide.dist < rightHandSide.dist;
}

void dijkstra(int source)
{
    vector <long> distance(n + 1, INT_MAX);
    distance[source] = 0;
    vector <long> count(n + 1, 0);
    count[source] = 1;

    priority_queue <node> pq;
    pq.push({source, 0, false});

    while (!pq.empty())
    {
        node u = pq.top();
        pq.pop();

        if (u.visited) continue;
        u.visited = true;

        for (edge e : edges)
        if (e.source == u.id)
        {
            int v = e.dest;
            int dist = distance[u.id] + e.weight;
            if (dist < distance[v]) 
            {
                distance[v] = dist;
                count[v] = count[u.id];
                pq.push({v, dist, false});
            }
            else if (dist == distance[v])
            {
                count[v] = count[u.id] + count[v];
            }
        }
    }
    cout << distance[n] << " " << count[n];
}

int main()
{
    Open();
    dijkstra(1);
    return 0;
}