#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define all(x) (x).begin(),(x).end()
using ll=long long;
struct Node
{
    int u,w;
    bool operator < (const Node& o) const{
        return w > o.w;
    }
};
vector<pair<int,int>> adj[100100];
int dist[100100];
bool visited[100100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,q,u,v,w,x;
    cin >> n >> m >> q;
    for(int i=1;i<=m;++i)
    {
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w); //push_back({v,w})
    }
    memset(dist,-1,sizeof dist);
    priority_queue<Node> pq;
    pq.push({1,0});
    dist[1]=0;
    while(!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if(visited[now.u])
        {
            continue;
        }
        visited[now.u]=true;
        dist[now.u]=now.w;
        for(auto x: adj[now.u]) //every node after u
        {
            pq.push({x.first,now.w+x.second});
        }
    }
    while(q--)
    {
        cin >> x;
        cout << dist[x] << endl;
    }
    return 0;
}
