#include "iostream"
#include "vector"
#include "unordered_map"
#include "list"


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

vector<pair<pair<int,int>,int>> MSTbyPrimsAlgo(unordered_map<int,list<pair<int,int>>> &adjList,int start){
    int vertex=adjList.size();
    vector<int> key(vertex+1,INT_MAX);
    vector<bool> MST(vertex+1, false);
    vector<int> parent(vertex+1, -1);

    key[start] = 0;
    for (int i = 1; i <= vertex; ++i) {
        int minKey = INT_MAX;
        int from=0;

        for (int ver = 1; ver <= vertex ; ++ver) {
            if(!MST[ver] && key[ver]<minKey){
                minKey = key[ver];
                from= ver;
            }
        }

        MST[from] = true;

        for (auto neighbour:adjList[from]) {
            int to=neighbour.first;
            int weight=neighbour.second;
            if(!MST[to] &&  weight < key[to]){
                key[to] = weight;
                parent[to] = from;
            }
        }
    }

    vector<pair<pair<int,int>,int>> ans;
    for (int i = 1; i <= vertex; ++i) {
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}

int main(){
    WeiGraph g;
    g.addEdge(5,4,9, false);
    g.addEdge(5,1,4, false);
    g.addEdge(4,1,1, false);
    g.addEdge(4,3,5, false);
    g.addEdge(4,2,3, false);
    g.addEdge(1,2,2, false);
    g.addEdge(3,2,3, false);
    g.addEdge(3,6,8, false);
    g.addEdge(2,6,7, false);

    vector<pair<pair<int,int>,int>> ans= MSTbyPrimsAlgo(g.adjList,1);

    for (int i = 1; i < ans.size(); ++i) {
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }

}