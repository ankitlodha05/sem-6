#include<bits/stdc++.h>
using namespace std;

class Graph 
{

    public:
    int ver;
    int edge;
    vector<pair<int,pair<int,int>>> adj;
    vector<int> parent;
    vector<pair<int,pair<int,int>>> mst;
    Graph()
    {
        ver = 0;
        edge = 0;
    }

    Graph(int x)
    {
        ver = x;
        parent.resize(ver,-1);
    }

    void addEdge(int u ,int v, int wt)
    {
        adj.push_back({wt,{u,v}});
    }


    int find(int u)
    {
        if(parent[u] == -1)
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void unionSet(int u , int v)
    {
        int uP = find(u);
        int vP = find(v);

        parent[uP] = vP;
    }

    void kruskal()
    {
        sort(adj.begin(),adj.end());

        for(int i = 0 ; i < edge; i++)
        {
            pair<int,pair<int,int>> temp ;
            temp = adj[i];
            int u = temp.second.first;
            int v = temp.second.second;
            if(find(u) != find(v))
            {
                mst.push_back(temp);
                unionSet(u,v);
            }
        }
        print_mst();
        
    }

    void print_mst()
    {
        int cost = 0;
        cout<<"mst is "<<endl;
        for(auto temp : mst)
        {
            cout<<temp.second.first<<" - "<<temp.second.second<<" "<<temp.first<<endl;
            cost += temp.first;
        }
        cout<<"Cost is "<<cost<<endl;
    }
};

int main()
{
    int ver;
    cin>>ver;
    int edge; 
    cin>>edge;

    Graph g(ver);

    g.edge = edge;

    for(int i = 0; i < edge ; i++)
    {
        int u , v, wt;
        cin>>u>>v>>wt;

        g.addEdge(u,v,wt);

    }

    g.kruskal();
}
