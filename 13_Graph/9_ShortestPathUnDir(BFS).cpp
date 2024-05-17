#include "iostream"
#include "vector"
#include "unordered_map"
#include "list"
#include "queue"
#include "algorithm"
using namespace std;

class Graph{
public:
    unordered_map<int,list<int>> adjList;
    vector<vector<int>> edges;

    void addEdge(int from,int to,bool direction){
        adjList[from].push_back(to);
        adjList[to];
        if(!direction){
            adjList[to].push_back(from);
        }
    }
    void printAdjList(){
        for(auto node:adjList){
            cout<<node.first<<" -> ";
            for(auto adjacent:node.second){
                cout<<adjacent<<" ";
            }
            cout<<endl;
        }
    }
};

vector<int> shortestPathUnDirBFS(unordered_map<int,list<int>> &adjList,int source,int desti){
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;

    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()){
        int frontNode = q.front();
        q.pop();

        for (auto neighbour:adjList[frontNode]) {
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }
        }
    }

    vector<int> shortestPath;

    int currNode = desti;
    shortestPath.push_back(currNode);

    while (currNode != source){
        currNode=parent[currNode];
        shortestPath.push_back(currNode);
    }

    reverse(shortestPath.begin(), shortestPath.end());


    return shortestPath;
}

int main(){
    Graph g;
    g.addEdge(0,1, false);
    g.addEdge(0,2, false);
    g.addEdge(0,7, false);
    g.addEdge(1,4, false);
    g.addEdge(2,3, false);
    g.addEdge(2,4, false);
    g.addEdge(3,5, false);
    g.addEdge(3,6, false);
    g.addEdge(6,7, false);

    vector<int> ans = shortestPathUnDirBFS(g.adjList,0,5);

    for (auto x:ans) {
        cout<<x<<" ";
    }


}