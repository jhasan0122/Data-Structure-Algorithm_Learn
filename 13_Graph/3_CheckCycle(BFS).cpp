#include "iostream"
#include "vector"
#include "unordered_map"
#include "list"
#include "queue"
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

bool checkCycleBfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> visited,int source){
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(source);
    visited[source]= true;
    parent[source] = -1;

    while (!q.empty()){
        int frontNode = q.front();
        q.pop();

        for (auto neighbour:adjList[frontNode]) {
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
            else if(parent[frontNode] != neighbour){
                return true;
            }
        }
    }
    return false;

}


bool checkCycle(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool> visited;
    for (auto node:adjList) {
        if(!visited[node.first]){
            if(checkCycleBfs(adjList,visited,node.first)){
                return true;
            }
        }
    }
    return false;
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

    if(checkCycle(g.adjList)){
        cout<<"Cycle";
    }
    else{
        cout<<"No cycle";
    }


}


