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
    vector<vector<int>> adjMatrix;


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
    void prepareAdjMatrix(int vertex){
        for (int i = 0; i <= vertex; ++i) {
            vector<int> temp(vertex+1,INT_MAX);
            temp[i] = 0;
            adjMatrix.push_back(temp);
        }

    }
    void addEdge(int from,int to,int weight,int vertex){
        adjMatrix[from][to] = weight;
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
    void printAdjMatrix(int vertex){
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                cout<<adjMatrix[i][j]<<"    |     ";
            }
            cout<<endl;
        }
    }
};

vector<vector<int>> floydWarshalAllPairShortestPath(vector<vector<int>> adjMatrix){
    int vertex = adjMatrix.size();


    for (int k = 0; k < vertex; ++k) {
        for (int i = 0; i < vertex; ++i) {
            for (int j = 0; j < vertex; ++j) {
                if(adjMatrix[i][k]!=INT_MAX && adjMatrix[k][j]!=INT_MAX){
                    adjMatrix[i][j] = min(adjMatrix[i][j] , adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }
    return adjMatrix;
}

int main(){
    WeiGraph g;
    g.prepareAdjMatrix(4);
    g.addEdge(2,1,8,4);
    g.addEdge(1,2,3,4);
    g.addEdge(2,3,2,4);
    g.addEdge(3,1,5,4);
    g.addEdge(1,4,7,4);
    g.addEdge(4,1,2,4);
    g.addEdge(3,4,1,4);
//    g.printAdjMatrix(4);

    vector<vector<int>> ans = floydWarshalAllPairShortestPath(g.adjMatrix);

    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}