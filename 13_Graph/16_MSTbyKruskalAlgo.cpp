#include "iostream"
#include "vector"
#include "unordered_map"
#include "list"
#include "algorithm"


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

void makeSet(vector<int> &parent,vector<int> &rank,int vertex){
    for (int i = 0; i <= vertex; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node] = findParent(parent,parent[node]);
}
void unionSet(int u,int v , vector<int> &parent,vector<int> &rank){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[u]>rank[v]){
        parent[v] = u;
    }
    else{
        parent[u] = v;
        (rank[v])++;
    }
}

bool cmp(vector<int> &p1,vector<int> &p2){
    return p1[2] < p2[2];
}

vector<pair<pair<int,int>,int>> MSTkruskalAlgo(vector<vector<int>> &edges,int vertex){

    sort(edges.begin(), edges.end(),cmp);

    vector<int> parent(vertex);
    vector<int> rank(vertex);

    makeSet(parent,rank,vertex);

    vector<pair<pair<int,int>,int>> ans;


    for (int i = 0; i < edges.size(); ++i) {
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);

        int weight = edges[i][2];

        if(u!=v){
            unionSet(u,v,parent,rank);
            ans.push_back({{u,v},weight});
        }

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

    vector<pair<pair<int,int>,int>> ans= MSTkruskalAlgo(g.edges,1);

    for (int i = 1; i < ans.size(); ++i) {
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }

}