#include "iostream"
#include "vector"
#include "unordered_map"
#include "list"
#include "set"

using namespace std;

class WeiGraph{
public:
    unordered_map<int,list<pair<int,int>>> adjList;
    vector<vector<int>> edges;

    void addEdge(int from,int to,int weight,bool direction){
        adjList[from].push_back(make_pair(to,weight));
        adjList[to];
        if(!direction){
            adjList[to].push_back(make_pair(from,weight));
        }
        vector<int> temp;
        temp.push_back(from);
        temp.push_back(to);
        temp.push_back(weight);
        edges.push_back(temp);
    }
    void printAdjList(){
        for(auto node:adjList){
            cout<<node.first<<" -> ";
            for(auto adjacent:node.second){
                cout<<"["<<adjacent.first<<","<<adjacent.second<<"] ";
            }
            cout<<endl;
        }
    }
};

int bellmonFordShortestPath(vector<vector<int>> &edges,int src,int dest,int vertex){
    vector<int> distance(vertex+1,INT_MAX);
    distance[src] = 0;

    for (int i = 0; i < vertex-1; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int from = edges[j][0];
            int to = edges[j][1];
            int weight = edges[j][2];

            if(distance[from]!=INT_MAX && (distance[from] + weight < distance[to])){
                distance[to] = distance[from] + weight;
            }
        }
    }
    for (int j = 0; j < edges.size(); ++j) {
        int from = edges[j][0];
        int to = edges[j][1];
        int weight = edges[j][2];

        if(distance[from]!=INT_MAX && (distance[from] + weight < distance[to])){
            return -1;
        }
    }
    return distance[dest];
}

int main(){
    WeiGraph g;
    g.addEdge(1,2,4, true);
    g.addEdge(1,3,3, true);
    g.addEdge(2,4,7, true);
    g.addEdge(3,4,-2, true);

    cout<<bellmonFordShortestPath(g.edges,1,4,4)<<endl;
}