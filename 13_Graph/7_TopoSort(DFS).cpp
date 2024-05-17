#include "iostream"
#include "vector"
#include "unordered_map"
#include "list"
#include "stack"
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

void topologicalSortDFS(unordered_map<int,list<int>> adjList,unordered_map<int,bool> &visited,stack<int> &st,int source){
    visited[source] = true;

    for (auto neighbour:adjList[source]) {
        if(!visited[neighbour]){
            topologicalSortDFS(adjList,visited,st,neighbour);
        }
    }
    st.push(source);
}

vector<int> topologicalSort(unordered_map<int,list<int>> adjList){
    unordered_map<int,bool> visited;
    stack<int> st;
    for (auto node:adjList) {
        if(!visited[node.first]){
            topologicalSortDFS(adjList,visited,st,node.first);
        }
    }
    vector<int> topologicalSort ;
    while (!st.empty()){
        topologicalSort.push_back(st.top());
        st.pop();
    }
    return topologicalSort;

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

    vector<int> ans = topologicalSort(g.adjList);

    for (auto x:ans) {
        cout<<x<<" ";
    }






}