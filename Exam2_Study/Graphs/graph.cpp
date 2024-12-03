#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>


using namespace std;



class Graph {
    int V;
    vector<list<int> > adjList;

public:

    Graph(int vertices){
        V = vertices;
        adjList.resize(V);
    }


    void addEdge(int u, int v){
        if (u >= 0 && u < V && v < V && v >= 0){

            adjList[u].push_front(v);
            adjList[v].push_front(u);
        }
    }

    void printAdjList() const
    {
        for (int i = 0; i < V; ++i)
        {
            std::cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i])
            {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void BFS(int start){
        vector<bool> visited(V, false);
        queue<int> Q;

        visited[start] = true;
        Q.push(start);

        while(!Q.empty()){

            int curr = Q.front();
            Q.pop();
            cout << curr << " ";

            for(int neighbor : adjList[curr]){
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    Q.push(neighbor);
                }
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        stack<int> S;

        visited[start] = true;
        S.push(start);

        while (!S.empty())
        {

            int curr = S.top();
            S.pop();
            cout << curr << " ";

            for (int neighbor : adjList[curr])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    S.push(neighbor);
                }
            }
        }
    }

    int getDegree(int vertex){
        if(vertex >= 0 && vertex < V){
            return adjList[vertex].size();
        }
    }

    
};

int main(){
    int vertices = 10;
    Graph graph(vertices);

    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 8);
    graph.addEdge(3, 4);
    graph.addEdge(3, 6);
    graph.addEdge(4, 8);
    graph.addEdge(5, 7);
    graph.addEdge(5, 8);
    graph.addEdge(6, 8);
    graph.addEdge(7, 8);

    // graph.printAdjList();

    cout << "BFS: ";
    graph.BFS(1);

    cout << endl;

    cout << "DFS: ";
    graph.DFS(1);

    cout << endl;

    graph.printAdjList();

    return 0;
}
