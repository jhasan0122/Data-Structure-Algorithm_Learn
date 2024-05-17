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

vector<int> topoSortKahnAlgo(unordered_map<int,list<int>> &adjList){
    unordered_map<int,int> indegree;
    for (auto node:adjList) {
        indegree[node.first];
        for (auto adjacent:node.second) {
            indegree[adjacent]++;
        }
    }

    queue<int> q;
    for (auto node:indegree) {
        if(node.second==0){
            q.push(node.first);
        }
    }

    vector<int> topoSortList;

    while (!q.empty()){
        int frontNode = q.front();
        q.pop();

        topoSortList.push_back(frontNode);

        for (auto neighbour:adjList[frontNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    return topoSortList;

}




int main(){


    Graph g;
    g.addEdge(1,2, true);
    g.addEdge(1,3, true);
    g.addEdge(2,4, true);
    g.addEdge(2,5, true);
    g.addEdge(3,6, true);
    g.addEdge(4,7, true);
    g.addEdge(5,7, true);
    g.addEdge(6,5, true);
    g.addEdge(6,7, true);

    vector<int> ans = topoSortKahnAlgo(g.adjList);

    for (auto x:ans) {
        cout<<x<<" ";
    }




}