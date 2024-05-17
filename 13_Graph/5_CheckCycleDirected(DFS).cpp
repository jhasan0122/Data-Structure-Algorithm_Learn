#include "iostream"
#include "vector"
#include "unordered_map"
#include "list"
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

bool checkCycleDirectedDFS(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,int source){
    visited[source] = true;
    dfsVisited[source] = true;

    for (auto neighbour:adjList[source]) {
        if(!visited[neighbour]){
            bool cycle = checkCycleDirectedDFS(adjList,visited,dfsVisited,neighbour);
            if(cycle){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }

    }
    dfsVisited[source] = false;
    return false;
}


bool checkCycleDirected(unordered_map<int,list<int>> &adjList){
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    for (auto node:adjList) {
        if(!visited[node.first]){
            if(checkCycleDirectedDFS(adjList,visited,dfsVisited,node.first)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    Graph g;
    g.addEdge(0,3, true);
    g.addEdge(3,4, true);
    g.addEdge(4,0, true);
    g.addEdge(0,2, true);
    g.addEdge(2,1, true);
    g.addEdge(1,0, true);



    if(checkCycleDirected(g.adjList)){
        cout<<"Cycle";
    }
    else{
        cout<<"No cycle";
    }


}