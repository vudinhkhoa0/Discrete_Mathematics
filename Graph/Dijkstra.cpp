#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n;
class Edge
{
    public:
        int source, dest, weight;
        Edge(){};
        friend istream& operator >> (istream&, Edge&);
        friend ostream& operator << (ostream&, Edge);
        ~Edge(){};
};
class node
{
    public:
        int id, dist;
        bool visited;
        node(int id, int dist, bool visited)
        {
            this->id = id;
            this->dist = dist;
            this->visited = visited;
        };
        ~node(){};
};
vector <Edge> edges;

istream& operator >> (istream& in, Edge &orther)
{
    in >> orther.source >> orther.dest >> orther.weight;
    return in;
}

ostream& operator << (ostream& out, Edge orther)
{
    out << orther.source << " " << orther.dest << " " << orther.weight << "\n";
    return out;
}

void Open()
{
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        Edge x;
        cin >> x;
        edges.push_back(x);
        // Nhap chiều thứ hai(đề bài là 1 chiều thì không cần dùng):
        swap(x.dest, x.source);
        edges.push_back(x);
    }
}
bool operator < (const node& leftHandSide, const node& rightHandSide)
{
    return leftHandSide.dist > rightHandSide.dist;
}

vector <int> Dijkstra(int source)
{
    priority_queue <node> pq;
    pq.push({source, 0, false});
    vector <int> distance(n, INT_MAX);
    distance[source] = 0;
    while (!pq.empty())
    {
        node u = pq.top();
        pq.pop();
    
        if (u.visited) continue;
        u.visited = true;
    
        for (Edge e : edges)
        {
            if (e.source == u.id)
            {
                int v = e.dest;
                int dist = distance[u.id] + e.weight;
                if (dist < distance[v])
                {
                    distance[v] = dist;
                    pq.push({v, dist, false});
                }
            }
        }
    }
    return distance;
}

void Print(const vector <int> distance)
{
    cout << "Distance from 0 to each point in the table: \n";
    for (int i = 0; i < n; i++) 
    cout << i << ": " << distance[i] << "\n";
}

int main()
{
    Open();
    vector <int> distance;
    distance = Dijkstra(0);
    Print(distance);
    return 0;
}