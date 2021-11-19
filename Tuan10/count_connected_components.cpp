#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    void DFS(int v, bool visited[]) {
        visited[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFS(*i, visited);
    }
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int countConnectedComponents() {
        bool* visited = new bool[V];
        int count = 0;
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                DFS(i, visited);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    //3
    cout << g.countConnectedComponents();
    return 0;
}
