#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

// Youtube video based on Kosaraju's Algorithm, also got help from geeks4geeks & stack overflow
/*
Step 1: Perform a DFS on the Original Graph
Step 2: Transpose the Graph
Step 3: Perform a DFS on the Transposed Graph
Step 4: Assign SCC IDs
- For each SCC found in Step 3, assign the smallest vertex index in the SCC as the SCC ID.
   - Output the SCC ID for each vertex in increasing order of vertex indices.

*/
class Graph {
private:
    int V;
    list<int> *adjList;
    

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFSUtil(int v, bool visited[], vector<int> &scc);

    Graph getTranspose(); // Function to get the transposed graph
    void fillOrder(int v, bool visited[], stack<int> &Stack); // Fill vertices in stack based on finish time
    vector<int> findSCCs();
};

Graph::Graph(int V){
    this->V = V;
    adjList = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[], vector<int> &scc){
    visited[v] = true;
    scc.push_back(v); //add vertext to current scc

    for (auto j = adjList[v].begin(); j != adjList[v].end(); ++j){
        if(!visited[*j]) {
            DFSUtil(*j, visited, scc);
        }
    }
}

Graph Graph::getTranspose(){
    Graph gt(V);
    for (int v = 0; v < V; v++)
    {
        for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i)
        {
            gt.adjList[*i].push_back(v);
        }
    }
    return gt;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;

    // Visit all neighbors
    for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i)
    {
        if (!visited[*i])
        {
            fillOrder(*i, visited, Stack);
        }
    }

    Stack.push(v); // Push the vertex to the stack after all neighbors are processed
}


vector<int> Graph::findSCCs(){
    stack<int> S;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }

    for (int j = 0; j < V; j++){
        if(!visited[j]) {
            fillOrder(j, visited, S);
        }
    }

    Graph gt = getTranspose();

    for (int i = 0; i < V; i++){
        visited[i] = false;

    }

    vector <int> sccIDs(V, -1);
    while(!S.empty()){
        int v = S.top();
        S.pop();

        if(!visited[v]) {
            vector<int> scc;
            gt.DFSUtil(v, visited, scc);

            int sccID = *min_element(scc.begin(), scc.end());
            for(int node : scc){
                sccIDs[node] = sccID;
            }
        }
    }

    delete[] visited;
    return sccIDs;
}

int main(){

    int vertices, edges;
    cin >> vertices;
    cin >> edges;

    Graph G(vertices);

    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }

    vector<int> sccIDs = G.findSCCs();

    for (int id : sccIDs){
        cout << id << "\n";
    }

        return 0;
}
