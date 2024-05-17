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

unordered_map<int,int> shortestPathSigSrcDijkstra(unordered_map<int,list<pair<int,int>>> &adjList,int src){
    unordered_map<int,int> distance;
    for (auto node:adjList) {
        distance[node.first] = INT_MAX;
    }
    distance[src] = 0;

    set<pair<int,int>> setofpair;
    setofpair.insert(make_pair(0,src));

    while (!setofpair.empty()){
        auto topNode = *(setofpair.begin());
        setofpair.erase(setofpair.begin());

        int topNodeDistance = topNode.first;
        int topNodeVal = topNode.second;

        for (auto neighbour :adjList[topNodeVal]) {
            if(topNodeDistance + neighbour.second < distance[neighbour.first]){
                auto prevRecord = setofpair.find(make_pair(distance[neighbour.first],neighbour.first));

                if(prevRecord != setofpair.end()){
                    setofpair.erase(prevRecord);
                }

                distance[neighbour.first] = topNodeDistance + neighbour.second;
                setofpair.insert(make_pair(distance[neighbour.first],neighbour.first));
            }

        }
    }
    return distance;
}

int main(){
    WeiGraph g;
    g.addEdge(2,1,3, false);
    g.addEdge(2,0,1, false);
    g.addEdge(0,1,7, false);
    g.addEdge(1,4,1, false);
    g.addEdge(1,3,5, false);
    g.addEdge(0,3,2, false);
    g.addEdge(3,4,7, false);

    unordered_map<int,int> ans = shortestPathSigSrcDijkstra(g.adjList,0);
    for (auto x:ans) {
        cout<<x.first<<" -> "<<x.second<<endl;
    }
}