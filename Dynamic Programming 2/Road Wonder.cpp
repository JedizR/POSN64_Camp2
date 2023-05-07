#include <bits/stdc++.h>

using namespace std;
struct A{
    int u,v,w;
};
A edge[1110];
int dis[1100],dis2[1100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k,q,now;
    cin >> n >> m >> k >> q;
    for(int i=1;i<=m;i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    for(int i=1;i<=k;i++)
    {
        cin >> edge[i+m].u >> edge[i+m].v >> edge[i+m].w;
        edge[i+m].w*=-1;
    }
    while(q--)
    {
        cin >> now;
        for(int i=1;i<=n;i++) dis[i]=1e9;
        dis[now]=0;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=1;i<=m+k;j++)
            {
                if(dis[edge[j].u]==1e9) continue;
                if(dis[edge[j].u]+edge[j].w<dis[edge[j].v])
                {
                    dis[edge[j].v]=dis[edge[j].u]+edge[j].w;
                }
            }
        }
        for(int i=1;i<=n;i++) dis2[i]=dis[i];
        for(int j=1;j<=m+k;j++)
        {
            if(dis[edge[j].u]==1e9) continue;
            if(dis[edge[j].u]+edge[j].w<dis[edge[j].v])
            {
                dis[edge[j].v]=dis[edge[j].u]+edge[j].w;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dis[i]!=dis2[i]||(dis[i]==1e9)) cout << "-1 ";
            else cout << dis[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
